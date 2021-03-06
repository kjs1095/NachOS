// thread.cc 
//	Routines to manage threads.  These are the main operations:
//
//	Fork -- create a thread to run a procedure concurrently
//		with the caller (this is done in two steps -- first
//		allocate the Thread object, then call Fork on it)
//	Begin -- called when the forked procedure starts up, to turn
//		interrupts on and clean up after last thread
//	Finish -- called when the forked procedure finishes, to clean up
//	Yield -- relinquish control over the CPU to another ready thread
//	Sleep -- relinquish control over the CPU, but thread is now blocked.
//		In other words, it will not run again, until explicitly 
//		put back on the ready queue.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "thread.h"
#include "switch.h"
#include "synch.h"
#include "sysdep.h"

// this is put at the top of the execution stack, for detecting stack overflows
const int STACK_FENCEPOST = 0xdedbeef;

//----------------------------------------------------------------------
// Thread::Thread
// 	Initialize a thread control block, so that we can then call
//	Thread::Fork.
//
//	"threadName" is an arbitrary string, useful for debugging.
//----------------------------------------------------------------------

Thread::Thread(char* threadName, int priority, bool isJoinable)
{
    name = threadName;
    stackTop = NULL;
    stack = NULL;
    status = JUST_CREATED;
    for (int i = 0; i < MachineStateSize; i++) {
	machineState[i] = NULL;		// not strictly necessary, since
					// new thread ignores contents 
					// of machine registers
    }
    this->isJoinable = isJoinable;
    joinLock = new Lock("Join lock");
    joinWait = new Condition("Join() called CV");
    finishWait = new Condition("Finish() called CV");
    deleteWait = new Condition("Permition to delete CV");
    joinCalled = false;
    finishCalled = false;
    forkCalled = false;
    readyToFinish = false;

    (void) setPriority(priority);

    donatedPriority = 0;
    isDonated = FALSE;
    desiredJoin = NULL;
    desiredLock = NULL;

    burstTime = 10;
    startTicks = 0;
#ifdef USER_PROGRAM
    space = NULL;
    for (int i = 0; i < MaxNumUserOpenFiles; ++i)
        openFileTable[i] = new UserOpenFileEntry();
#endif
}

//----------------------------------------------------------------------
// Thread::~Thread
// 	De-allocate a thread.
//
// 	NOTE: the current thread *cannot* delete itself directly,
//	since it is still running on the stack that we need to delete.
//
//      NOTE: if this is the main thread, we can't delete the stack
//      because we didn't allocate it -- we got it automatically
//      as part of starting up Nachos.
//----------------------------------------------------------------------

Thread::~Thread()
{
    DEBUG(dbgThread, "Deleting thread: " << name);

    ASSERT(this != kernel->currentThread);
    
    delete joinLock;
    delete joinWait;
    delete finishWait;
    delete deleteWait;

    if (stack != NULL)
	DeallocBoundedArray((char *) stack, StackSize * sizeof(int));

#ifdef USER_PROGRAM
    for (int i = 0; i < MaxNumUserOpenFiles; ++i) {
        if (openFileTable[i]->openFile != NULL)
            delete openFileTable[i]->openFile;
        delete openFileTable[i];
    }

    delete space;
#endif
}

//----------------------------------------------------------------------
// Thread::setPriority
//  Set new priority value and return old value. 
//  Assume this method just is used internally and called by constructor
//
// Return: old priority value 
// "newPriority" is the new priority value
//----------------------------------------------------------------------

int Thread::setPriority(int newPriority)
{
    // TODO should be atomic in the future
 
    if (newPriority < 0)        newPriority = 0;
    else if (newPriority > 7)   newPriority = 7;
 
    int oldPriority = priority;
    priority = newPriority;
    
    return oldPriority;
}

//----------------------------------------------------------------------
// Thread::getPriority
//  Return: priority value
//----------------------------------------------------------------------

int Thread::getPriority()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    return priority;
}

//----------------------------------------------------------------------
// Thread::setEffectivePriority
//  Upate effective priority and update ready list.
//
//  Return old effective priority value
//
// "newDonatedPriority" is priority donated from other thread
//----------------------------------------------------------------------

int Thread::setEffectivePriority(int newDonatedPriority)
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);
    ASSERT(newDonatedPriority >= 0);
    DEBUG(dbgThread, "Thread "<< name << " gets donate: " << newDonatedPriority);

    int oldDonatedPriority = donatedPriority;

    donatedPriority = newDonatedPriority;
    isDonated = TRUE;
    kernel->scheduler->UpdateReadyList(this);

    NotifyDesiredLockNewDonation();
    NotifyDesiredJoinNewDonation();

    return oldDonatedPriority;
}

//----------------------------------------------------------------------
// Thread::getEffectivePriority
//  Return donated priority if set, otherwise return its own priority
//----------------------------------------------------------------------

int Thread::getEffectivePriority()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    if (isDonated == FALSE)
        return priority;
    else
        return donatedPriority;
}

//----------------------------------------------------------------------
// Thread::resetEffectivePriority
//  Reset isDonated to FALSE
//
// Return TRUE, if succeed. FALSE, otherwise
//----------------------------------------------------------------------

bool Thread::resetEffectivePriority()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    bool oldValue = isDonated;
    if (oldValue == TRUE) {
        isDonated = FALSE;
        kernel->scheduler->UpdateReadyList(this);
    }

    return oldValue;
}

//----------------------------------------------------------------------
// Thread::setDesiredJoin
//  Called by Join when caller thread (current thread) has to wait for 
//  "joinThread" 
//----------------------------------------------------------------------

void Thread::setDesiredJoin(Thread* joinThread)
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);
   
    this->desiredJoin = joinThread;
}

//----------------------------------------------------------------------
// Thread::resetDesiredJoin
//  Called by Join when joinable thread finish
//----------------------------------------------------------------------

void Thread::resetDesiredJoin()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    desiredJoin = NULL;
}

//----------------------------------------------------------------------
// Thread::setDesiredLock
//  Called by Lock when this thread tries to acqure lock but failed
//----------------------------------------------------------------------

void Thread::setDesiredLock(Lock* desiredLock)
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    this->desiredLock = desiredLock;
}

//----------------------------------------------------------------------
// Thread::resetDesiredLock
//  Called by Lock when this thread acquire lock sucessfully
//----------------------------------------------------------------------

void Thread::resetDesiredLock()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    desiredLock = NULL;
}

//----------------------------------------------------------------------
// Thread::Fork
// 	Invoke (*func)(arg), allowing caller and callee to execute 
//	concurrently.
//
//	NOTE: although our definition allows only a single argument
//	to be passed to the procedure, it is possible to pass multiple
//	arguments by making them fields of a structure, and passing a pointer
//	to the structure as "arg".
//
// 	Implemented as the following steps:
//		1. Allocate a stack
//		2. Initialize the stack so that a call to SWITCH will
//		cause it to run the procedure
//		3. Put the thread on the ready queue
// 	
//	"func" is the procedure to run concurrently.
//	"arg" is a single argument to be passed to the procedure.
//----------------------------------------------------------------------

void 
Thread::Fork(VoidFunctionPtr func, void *arg)
{
    Interrupt *interrupt = kernel->interrupt;
    Scheduler *scheduler = kernel->scheduler;
    IntStatus oldLevel;
    
    DEBUG(dbgThread, "Forking thread: " << name << " f(a): " << (int) func << " " << arg);
    
    StackAllocate(func, arg);

    oldLevel = interrupt->SetLevel(IntOff);
    scheduler->ReadyToRun(this);	// ReadyToRun assumes that interrupts 
					// are disabled!

    forkCalled = TRUE;
    (void) interrupt->SetLevel(oldLevel);

    if (kernel->scheduler->IsPreemptive())
        kernel->currentThread->Yield();
}    

//----------------------------------------------------------------------
// Thread::CheckOverflow
// 	Check a thread's stack to see if it has overrun the space
//	that has been allocated for it.  If we had a smarter compiler,
//	we wouldn't need to worry about this, but we don't.
//
// 	NOTE: Nachos will not catch all stack overflow conditions.
//	In other words, your program may still crash because of an overflow.
//
// 	If you get bizarre results (such as seg faults where there is no code)
// 	then you *may* need to increase the stack size.  You can avoid stack
// 	overflows by not putting large data structures on the stack.
// 	Don't do this: void foo() { int bigArray[10000]; ... }
//----------------------------------------------------------------------

void
Thread::CheckOverflow()
{
    if (stack != NULL) {
#ifdef HPUX			// Stacks grow upward on the Snakes
	ASSERT(stack[StackSize - 1] == STACK_FENCEPOST);
#else
	ASSERT(*stack == STACK_FENCEPOST);
#endif
   }
}

//----------------------------------------------------------------------
// Thread::Begin
// 	Called by ThreadRoot when a thread is about to begin
//	executing the forked procedure.
//
// 	It's main responsibilities are:
//	1. deallocate the previously running thread if it finished 
//		(see Thread::Finish())
//	2. enable interrupts (so we can get time-sliced)
//----------------------------------------------------------------------

void
Thread::Begin ()
{
    ASSERT(this == kernel->currentThread);
    DEBUG(dbgThread, "Beginning thread: " << name);
    
    kernel->scheduler->CheckToBeDestroyed();
    kernel->interrupt->Enable();
}

//----------------------------------------------------------------------
// Thread::Finish
// 	Called by ThreadRoot when a thread is done executing the 
//	forked procedure.
//
// 	NOTE: we can't immediately de-allocate the thread data structure 
//	or the execution stack, because we're still running in the thread 
//	and we're still on the stack!  Instead, we tell the scheduler
//	to call the destructor, once it is running in the context of a different thread.
//
// 	NOTE: we disable interrupts, because Sleep() assumes interrupts
//	are disabled.
//----------------------------------------------------------------------

//
void
Thread::Finish ()
{
    (void) kernel->interrupt->SetLevel(IntOff);		
    ASSERT(this == kernel->currentThread);
    
    DEBUG(dbgThread, "Finishing thread: " << name);

    if (isJoinable) {
        joinLock->Acquire();
        finishCalled = TRUE;

        while (!joinCalled) {
            joinWait->Wait(joinLock);
            (void) kernel->interrupt->SetLevel(IntOff);
        }

        finishWait->Signal(joinLock);

        if (kernel->scheduler->IsPreemptive()) {
            (void) setPriority(0);
            (void) resetEffectivePriority(); // caller should leave Join() first, 
                // or memory access error would be occured. 
        }

        while (!readyToFinish) {
            deleteWait->Wait(joinLock);
            (void) kernel->interrupt->SetLevel(IntOff);
        }

        joinLock->Release();

        DEBUG(dbgThread, "Wholly finishing thread after Join() called: " << name);
    }

    Sleep(TRUE);				// invokes SWITCH
    // not reached
    ASSERTNOTREACHED();
}

//----------------------------------------------------------------------
// Thread::Yield
// 	Relinquish the CPU if any other thread is ready to run.
//	If so, put the thread on the end of the ready list, so that
//	it will eventually be re-scheduled.
//
//	NOTE: returns immediately if no other thread on the ready queue.
//	Otherwise returns when the thread eventually works its way
//	to the front of the ready list and gets re-scheduled.
//
//	NOTE: we disable interrupts, so that looking at the thread
//	on the front of the ready list, and switching to it, can be done
//	atomically.  On return, we re-set the interrupt level to its
//	original state, in case we are called with interrupts disabled. 
//
// 	Similar to Thread::Sleep(), but a little different.
//----------------------------------------------------------------------

void
Thread::Yield ()
{
    Thread *nextThread;
    IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);
    
    ASSERT(this == kernel->currentThread);
    
    DEBUG(dbgThread, "Yielding thread: " << name);
    
    nextThread = kernel->scheduler->FindNextToRun();
    if (nextThread != NULL && nextThread != this) {
        int actualBurstTime = kernel->stats->userTicks - startTicks;
        burstTime = (int)(alpha * (float)(actualBurstTime)
                      + (1.0 - alpha) * (float)(burstTime));

        DEBUG(dbgThread, "Acutal burst time: " << actualBurstTime);
        DEBUG(dbgThread, "Predict next burst time: " << burstTime);

	kernel->scheduler->ReadyToRun(this);
	kernel->scheduler->Run(nextThread, FALSE);
    }
    (void) kernel->interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Thread::Sleep
// 	Relinquish the CPU, because the current thread has either
//	finished or is blocked waiting on a synchronization 
//	variable (Semaphore, Lock, or Condition).  In the latter case,
//	eventually some thread will wake this thread up, and put it
//	back on the ready queue, so that it can be re-scheduled.
//
//	NOTE: if there are no threads on the ready queue, that means
//	we have no thread to run.  "Interrupt::Idle" is called
//	to signify that we should idle the CPU until the next I/O interrupt
//	occurs (the only thing that could cause a thread to become
//	ready to run).
//
//	NOTE: we assume interrupts are already disabled, because it
//	is called from the synchronization routines which must
//	disable interrupts for atomicity.   We need interrupts off 
//	so that there can't be a time slice between pulling the first thread
//	off the ready list, and switching to it.
//----------------------------------------------------------------------
void
Thread::Sleep (bool finishing)
{
    Thread *nextThread;
    
    ASSERT(this == kernel->currentThread);
    ASSERT(kernel->interrupt->getLevel() == IntOff);
    
    DEBUG(dbgThread, "Sleeping thread: " << name);

    int actualBurstTime = kernel->stats->userTicks - startTicks;
    burstTime = (int)(alpha * (float)(actualBurstTime)
                    + (1.0 - alpha) * (float)(burstTime));

    DEBUG(dbgThread, "Acutal burst time: " << actualBurstTime);
    DEBUG(dbgThread, "Predict next burst time: " << burstTime);

    status = BLOCKED;
    while ((nextThread = kernel->scheduler->FindNextToRun()) == NULL)
	kernel->interrupt->Idle();	// no one to run, wait for an interrupt
    
    // returns when it's time for us to run
    kernel->scheduler->Run(nextThread, finishing); 
}

//----------------------------------------------------------------------
// Thread::Join
//  Called by parent thread to allow parent to wait until child is 
//  terminated.
//----------------------------------------------------------------------

void 
Thread::Join () 
{
    ASSERT(this != kernel->currentThread);
    ASSERT(isJoinable == TRUE);
    ASSERT(joinCalled == FALSE);
    ASSERT(forkCalled == TRUE);

    IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);
    DEBUG(dbgThread , "Joining thread: " << name);

    joinLock->Acquire();
    joinCalled = TRUE;

    while (!finishCalled) {
        if (kernel->scheduler->IsPreemptive() == TRUE) {
            IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);

            kernel->currentThread->setDesiredJoin(this);
            kernel->scheduler->DonatePriority(kernel->currentThread, this);

            (void) kernel->interrupt->SetLevel(oldLevel);
        }

        finishWait->Wait(joinLock);
    }
   
    kernel->currentThread->resetDesiredJoin(); 
    joinWait->Signal(joinLock);

    readyToFinish = TRUE;
    deleteWait->Signal(joinLock);
    
    joinLock->Release(); 

    (void) kernel->interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Thread::NotifyDesiredJoinNewDonation 
//  Used internally by setEffectivePriority
//----------------------------------------------------------------------

void 
Thread::NotifyDesiredJoinNewDonation()
{
    if (desiredJoin != NULL)
        kernel->scheduler->DonatePriority(this, desiredJoin);
}

//----------------------------------------------------------------------
// Thread::NotifyDesiredLockNewDonation
//  Used internally by setEffectivePriority
//----------------------------------------------------------------------

void 
Thread::NotifyDesiredLockNewDonation()
{
    if (desiredLock != NULL)
        desiredLock->DonatePriorityToLockHolder(this);
}

//----------------------------------------------------------------------
// ThreadBegin, ThreadFinish,  ThreadPrint
//	Dummy functions because C++ does not (easily) allow pointers to member
//	functions.  So we create a dummy C function
//	(which we can pass a pointer to), that then simply calls the 
//	member function.
//----------------------------------------------------------------------

static void ThreadFinish()    { kernel->currentThread->Finish(); }
static void ThreadBegin() { kernel->currentThread->Begin(); }
void ThreadPrint(Thread *t) { t->Print(); }

#ifdef PARISC

//----------------------------------------------------------------------
// PLabelToAddr
//	On HPUX, function pointers don't always directly point to code,
//	so we need to do the conversion.
//----------------------------------------------------------------------

static void *
PLabelToAddr(void *plabel)
{
    int funcPtr = (int) plabel;

    if (funcPtr & 0x02) {
        // L-Field is set.  This is a PLT pointer
        funcPtr -= 2;	// Get rid of the L bit
        return (*(void **)funcPtr);
    } else {
        // L-field not set.
        return plabel;
    }
}
#endif

//----------------------------------------------------------------------
// Thread::StackAllocate
//	Allocate and initialize an execution stack.  The stack is
//	initialized with an initial stack frame for ThreadRoot, which:
//		enables interrupts
//		calls (*func)(arg)
//		calls Thread::Finish
//
//	"func" is the procedure to be forked
//	"arg" is the parameter to be passed to the procedure
//----------------------------------------------------------------------

void
Thread::StackAllocate (VoidFunctionPtr func, void *arg)
{
    stack = (int *) AllocBoundedArray(StackSize * sizeof(int));

#ifdef PARISC
    // HP stack works from low addresses to high addresses
    // everyone else works the other way: from high addresses to low addresses
    stackTop = stack + 16;	// HP requires 64-byte frame marker
    stack[StackSize - 1] = STACK_FENCEPOST;
#endif

#ifdef SPARC
    stackTop = stack + StackSize - 96; 	// SPARC stack must contains at 
					// least 1 activation record 
					// to start with.
    *stack = STACK_FENCEPOST;
#endif 

#ifdef PowerPC // RS6000
    stackTop = stack + StackSize - 16; 	// RS6000 requires 64-byte frame marker
    *stack = STACK_FENCEPOST;
#endif 

#ifdef DECMIPS
    stackTop = stack + StackSize - 4;	// -4 to be on the safe side!
    *stack = STACK_FENCEPOST;
#endif

#ifdef ALPHA
    stackTop = stack + StackSize - 8;	// -8 to be on the safe side!
    *stack = STACK_FENCEPOST;
#endif


#ifdef x86
    // the x86 passes the return address on the stack.  In order for SWITCH() 
    // to go to ThreadRoot when we switch to this thread, the return addres 
    // used in SWITCH() must be the starting address of ThreadRoot.
    stackTop = stack + StackSize - 4;	// -4 to be on the safe side!
    *(--stackTop) = (int) ThreadRoot;
    *stack = STACK_FENCEPOST;
#endif
    
#ifdef PARISC
    machineState[PCState] = PLabelToAddr(ThreadRoot);
    machineState[StartupPCState] = PLabelToAddr(ThreadBegin);
    machineState[InitialPCState] = PLabelToAddr(func);
    machineState[InitialArgState] = arg;
    machineState[WhenDonePCState] = PLabelToAddr(ThreadFinish);
#else
    machineState[PCState] = (void*) ThreadRoot;
    machineState[StartupPCState] = (void*) ThreadBegin;
    machineState[InitialPCState] = (void*) func;
    machineState[InitialArgState] = (void*) arg;
    machineState[WhenDonePCState] = (void*) ThreadFinish;
#endif
}

#ifdef USER_PROGRAM
#include "machine.h"

//----------------------------------------------------------------------
// Thread::SaveUserState
//	Save the CPU state of a user program on a context switch.
//
//	Note that a user program thread has *two* sets of CPU registers -- 
//	one for its state while executing user code, one for its state 
//	while executing kernel code.  This routine saves the former.
//----------------------------------------------------------------------

void
Thread::SaveUserState()
{
    for (int i = 0; i < NumTotalRegs; i++)
	userRegisters[i] = kernel->machine->ReadRegister(i);
}

//----------------------------------------------------------------------
// Thread::RestoreUserState
//	Restore the CPU state of a user program on a context switch.
//
//	Note that a user program thread has *two* sets of CPU registers -- 
//	one for its state while executing user code, one for its state 
//	while executing kernel code.  This routine restores the former.
//----------------------------------------------------------------------

void
Thread::RestoreUserState()
{
    for (int i = 0; i < NumTotalRegs; i++)
	kernel->machine->WriteRegister(i, userRegisters[i]);
}

//----------------------------------------------------------------------
// Thread::AddOpenFileEntry
//	Add OpenFile into user file table
//
// Return -1 if there is no room for handling another OpenFile
// Return integer as file descriptor 
//
// "newOpenFile" is new OpenFile that tries to add into file table
//----------------------------------------------------------------------

int
Thread::AddOpenFileEntry(OpenFile *newOpenfile)
{
    for (int i = 0; i < MaxNumUserOpenFiles; ++i) {
        if (openFileTable[i]->inUse == FALSE) {
            openFileTable[i]->openFile = newOpenfile;
            openFileTable[i]->inUse = TRUE;
            return i;
        }
    }

    return -1;
}

//----------------------------------------------------------------------
// Thread::RemoveOpenFileEntry
//  Remove OpenFile from user file table by file descriptor
//
// Return TRUE, if success. FALSE, otherwise.  
//
// "fd" is the file descriptor of open file would remove from file table
//----------------------------------------------------------------------

bool 
Thread::RemoveOpenFileEntry(int fd) 
{
    if (fd < 0 || fd >= MaxNumUserOpenFiles) {
        return FALSE;
    } else if (openFileTable[fd]->inUse == FALSE) {
        return FALSE;
    } else {    // fd is legal value and entry is in use 
        openFileTable[fd]->inUse = FALSE;
        if (openFileTable[fd]->openFile != NULL)
            delete openFileTable[fd]->openFile;
        openFileTable[fd]->openFile = NULL;

        return TRUE;
    }   
}

//----------------------------------------------------------------------
// Thread::GetOpenFileEntry
//  Retrive OpenFile from user file table by file descriptor
//
// Return pointer of target OpenFile, NULL for not found
//
// "fd" is the file descriptor of open file would retrive from file table
//----------------------------------------------------------------------

OpenFile*
Thread::GetOpenFileEntry(int fd) 
{
    if (fd < 0 || fd >= MaxNumUserOpenFiles) {
        return NULL;
    } else if (openFileTable[fd]->inUse == FALSE) {
        return NULL;
    } else if (openFileTable[fd]->openFile == NULL) {
        return NULL;
    } else {    // fd is legal value and entry is in use and exist 
        return openFileTable[fd]->openFile;
    }   
}
#endif

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

static void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	cout << "*** thread " << which << " looped " << num << " times\n";
        kernel->currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// Thread::SelfTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
Thread::SelfTest()
{
    DEBUG(dbgThread, "Entering Thread::SelfTest");

    Thread *t = new Thread("forked thread");

    t->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    SimpleThread(0);
}

