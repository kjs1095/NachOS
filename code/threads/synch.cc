// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables.
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Once we'e implemented one set of higher level atomic operations,
// we can implement others using that implementation.  We illustrate
// this by implementing locks and condition variables on top of 
// semaphores, instead of directly enabling and disabling interrupts.
//
// Locks are implemented using a semaphore to keep track of
// whether the lock is held or not -- a semaphore value of 0 means
// the lock is busy; a semaphore value of 1 means the lock is free.
//
// The implementation of condition variables using semaphores is
// a bit trickier, as explained below under Condition::Wait.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "main.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List<Thread *>;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    Interrupt *interrupt = kernel->interrupt;
    Thread *currentThread = kernel->currentThread;
    
    // disable interrupts
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	
    
    while (value == 0) { 		// semaphore not available
	queue->Append(currentThread);	// so go to sleep
	currentThread->Sleep(FALSE);
    } 
    value--; 			// semaphore available, consume its value
   
    // re-enable interrupts
    (void) interrupt->SetLevel(oldLevel);	
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that interrupts
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Interrupt *interrupt = kernel->interrupt;
    
    // disable interrupts
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	
    
    if (!queue->IsEmpty()) {  // make thread ready.
	kernel->scheduler->ReadyToRun(queue->RemoveFront());
    }
    value++;
    
    // re-enable interrupts
    (void) interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Semaphore::SelfTest, SelfTestHelper
// 	Test the semaphore implementation, by using a semaphore
//	to control two threads ping-ponging back and forth.
//----------------------------------------------------------------------

static Semaphore *ping;
static void
SelfTestHelper (Semaphore *pong) 
{
    for (int i = 0; i < 10; i++) {
        ping->P();
	pong->V();
    }
}

void
Semaphore::SelfTest()
{
    Thread *helper = new Thread("ping");

    ASSERT(value == 0);		// otherwise test won't work!
    ping = new Semaphore("ping", 0);
    helper->Fork((VoidFunctionPtr) SelfTestHelper, this);
    for (int i = 0; i < 10; i++) {
        ping->V();
	this->P();
    }
    delete ping;
}

//----------------------------------------------------------------------
// Lock::Lock
// 	Initialize a lock, so that it can be used for synchronization.
//	Initially, unlocked.
//
//	"debugName" is an arbitrary name, useful for debugging.
//----------------------------------------------------------------------

Lock::Lock(char* debugName)
{
    name = debugName;
    waitQueue = new List<Thread *>;
    locked = FALSE;
    lockHolder = NULL;
}

//----------------------------------------------------------------------
// Lock::~Lock
// 	Deallocate a lock
//----------------------------------------------------------------------
Lock::~Lock()
{
    ASSERT(locked == FALSE);
    ASSERT(waitQueue->IsEmpty());
    delete waitQueue;
}

//----------------------------------------------------------------------
// Lock::Acquire
//	Atomically wait until the lock is free, then set it to busy.
//	Equivalent to Semaphore::P(), with the semaphore value of 0
//	equal to busy, and semaphore value of 1 equal to free.
//----------------------------------------------------------------------

void Lock::Acquire()
{
    Interrupt *interrupt = kernel->interrupt;
    Thread *currentThread = kernel->currentThread;

    ASSERT(locked == 0 || !IsHeldByCurrentThread());

    // disable interrupt
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    while (locked == TRUE) {
        DonatePriorityToLockHolder(currentThread);
        waitQueue->Append(currentThread);
        currentThread->Sleep(FALSE);        
    }

    locked = TRUE;
    lockHolder = currentThread;

    DEBUG(dbgSynch, "Lock: " << getName() << " is held by "
                << currentThread->getName());

    // re-enable interrupt
    (void*) interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Lock::Release
//	Atomically set lock to be free, waking up a thread waiting
//	for the lock, if any.
//	Equivalent to Semaphore::V(), with the semaphore value of 0
//	equal to busy, and semaphore value of 1 equal to free.
//
//	By convention, only the thread that acquired the lock
// 	may release it.
//---------------------------------------------------------------------

void Lock::Release()
{
    ASSERT(locked == TRUE);
    ASSERT(IsHeldByCurrentThread());
    
    Interrupt *interrupt = kernel->interrupt;
    IntStatus oldLevel = interrupt->SetLevel(IntOff); // disable interrupt

    bool didLockHolderHaveBeenDonated = CleanDonatedPriority();
    while (!waitQueue->IsEmpty())
        kernel->scheduler->ReadyToRun(waitQueue->RemoveFront());
    
    lockHolder = NULL;
    locked = FALSE;

    DEBUG(dbgSynch, "Lock: " << getName() << " is released");

    // re-enable interrupt
    (void*) interrupt->SetLevel(oldLevel);

    if (kernel->scheduler->IsPreemptive() && didLockHolderHaveBeenDonated == TRUE)
        kernel->currentThread->Yield();
}

//----------------------------------------------------------------------
// Lock::DonatePriorityToLockHolder
//  Donate effective priority to lock holder by current thread.
//
// "doner" : doner thread of effective priority
//---------------------------------------------------------------------

void Lock::DonatePriorityToLockHolder(Thread* doner)
{
    kernel->scheduler->DonatePriority(doner, lockHolder);
}

//----------------------------------------------------------------------
// Lock::CleanDonatedPriorty()
//  Reset donated priority of lock holder. Used interally by Release()
//
// Return TRUE, if lockHolder had been donated. FALSE, otherwise. 
//---------------------------------------------------------------------

bool Lock::CleanDonatedPriority()
{
    DEBUG(dbgSynch, "Lock: " << this->getName() << ", "
                << "reset donated priority of lock holder: "
                << lockHolder->getName());

    return lockHolder->resetEffectivePriority();
}

//----------------------------------------------------------------------
// Condition::Condition
// 	Initialize a condition variable, so that it can be 
//	used for synchronization.  Initially, no one is waiting
//	on the condition.
//
//	"debugName" is an arbitrary name, useful for debugging.
//----------------------------------------------------------------------
Condition::Condition(char* debugName)
{
    name = debugName;
    waitQueue = new List<Thread *>;
}

//----------------------------------------------------------------------
// Condition::Condition
// 	Deallocate the data structures implementing a condition variable.
//----------------------------------------------------------------------

Condition::~Condition()
{
    ASSERT(waitQueue->IsEmpty());
    delete waitQueue;
}

//----------------------------------------------------------------------
// Condition::Wait
// 	Atomically release monitor lock and go to sleep.
//  Step 1. do these operations below atomicity by diable/re-enable 
//          interrupt.
//    1.a Release the mutex
//    1.b Move this running thread into wait-queue
//    1.c Sleep this thread
//
//  Step 2. Once this thread is notified and resumed, the re-acquire 
//          the mutex.
//
//	Note: we assume Mesa-style semantics, which means that the
//	waiter must re-acquire the monitor lock when waking up.
//
//	"conditionLock" -- lock protecting the use of this condition
//----------------------------------------------------------------------

void Condition::Wait(Lock* conditionLock) 
{
    ASSERT(conditionLock->IsHeldByCurrentThread());
    
    Thread *currentThread = kernel->currentThread;
    Interrupt *interrupt = kernel->interrupt;
    // disable interrupt
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    
    waitQueue->Append(currentThread);

    conditionLock->Release();
    currentThread->Sleep(FALSE);

    // re-enable interrupt
    (void) interrupt->SetLevel(oldLevel);    

    conditionLock->Acquire();
}

//----------------------------------------------------------------------
// Condition::Signal
// 	Wake up a thread waiting on this condition, if any.
//
//	Note: we assume Mesa-style semantics, which means that the
//	signaller doesn't give up control immediately to the thread
//	being woken up (unlike Hoare-style).
//
//	Also note: we assume the caller holds the monitor lock
//	(unlike what is described in Birrell's paper).  This allows
//	us to access waitQueue without disabling interrupts.
//
//	"conditionLock" -- lock protecting the use of this condition
//----------------------------------------------------------------------

void Condition::Signal(Lock* conditionLock)
{
    ASSERT(conditionLock->IsHeldByCurrentThread());
   
    Interrupt *interrupt = kernel->interrupt;
    // disable interrupt
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    if (!waitQueue->IsEmpty()) {
        kernel->scheduler->ReadyToRun(waitQueue->RemoveFront()); 
    }

    // re-enable interrupt
    (void) interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Condition::Broadcast
// 	Wake up all threads waiting on this condition, if any.
//
//	"conditionLock" -- lock protecting the use of this condition
//----------------------------------------------------------------------

void Condition::Broadcast(Lock* conditionLock) 
{
    while (!waitQueue->IsEmpty()) {
        Signal(conditionLock);
    }
}

//----------------------------------------------------------------------
// MailBox::MailBox
//  Initialize a mailbox
//
// "debugName" -- name for debug purpose
//----------------------------------------------------------------------

Mailbox::Mailbox(char* debugName)
{
    name = debugName;
    bufferWritable = TRUE;  // Indicate the buffer is writable or not
    numRecvCalled = 0;     // #Receive(int* message) called
    
    mbLock = new Lock("Lock for mailbox"); 
    sendWait = new Condition("CV for waiting Send");
    recvWait = new Condition("CV for waiting Receive"); 
}

//----------------------------------------------------------------------
// MailBox::~MailBox
//  Deallocate the mailbox
//----------------------------------------------------------------------
Mailbox::~Mailbox()
{
    delete mbLock;
    delete sendWait;
    delete recvWait;
}

//----------------------------------------------------------------------
// MailBox::Send
//  Step 1. Wait until the buffer is writable or any Receive is called.
//  Step 2. Put message in the buffer and set the buffer to be not 
//          writable. 
//
// "message" is the message to be passed.
//----------------------------------------------------------------------

void Mailbox::Send(int message)
{
    mbLock->Acquire();

    while (bufferWritable == FALSE || numRecvCalled == 0) {
        sendWait->Wait(mbLock);
    }
    
    buffer = message;
    bufferWritable = FALSE;
    
    recvWait->Signal(mbLock);    
    mbLock->Release();
}

//----------------------------------------------------------------------
// MailBox::Receive
//  Step 1. Increment #Receive calls
//  Step 2. Wake sleeping Send up if any
//  Step 3. Wait until buffer is not writable
//  Step 4. Place the message in buffer into the buffer passed in as 
//          parameter
//  Step 5. Set the inner buffer to become writable and decrement
//          #Receive calls
//
// "message" pointer to external method that message would pass into
//----------------------------------------------------------------------

void Mailbox::Receive(int* message)
{
    mbLock->Acquire();

    numRecvCalled++;
    sendWait->Signal(mbLock);

    while (bufferWritable == TRUE) {
        recvWait->Wait(mbLock);
    }

    *message = buffer;
    numRecvCalled--;
    bufferWritable = TRUE;

    mbLock->Release();
}
