// scheduler.h 
//	Data structures for the thread dispatcher and scheduler.
//	Primarily, the list of threads that are ready to run.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "copyright.h"
#include "list.h"
#include "thread.h"

enum SchedulerType {
    RR, // Round-Robin
    FCFS, // First-Come-First-Serve
    Priority,
    SJF // Shortest Job First
};

// The following class defines a thread that is waked up in
// the future.  The internal data structures are left public 
// to make it simpler to manipulate.

class PendingThread {
  public:
    PendingThread(Thread *threadToWakeUp, int time);
                                // initial a thread that will be wake 
                                // up in the future
    Thread *threadToWakeUp;
    int when;   // when the thread is supposed to wake up
};

// The following class defines the scheduler/dispatcher abstraction -- 
// the data structures and operations needed to keep track of which 
// thread is running, and which threads are ready but not running.

class Scheduler {
  public:
    Scheduler(SchedulerType initSchedulerType, bool isPreemptive);		
                // Initialize list of ready threads 
    ~Scheduler();		// De-allocate ready list

    void ReadyToRun(Thread* thread);	
    				// Thread can be dispatched.
    Thread* FindNextToRun();	// Dequeue first thread on the ready 
				// list, if any, and return thread.
    void Run(Thread* nextThread, bool finishing);
    				// Cause nextThread to start running
    void CheckToBeDestroyed();// Check if thread that had been
    				// running needs to be deleted
    void Print();		// Print contents of ready list
    
    // SelfTest for scheduler is implemented in class Thread

    void SetSleep(int sleepTime);   // suspend execution 
                    // until time > now + sleepTime
    void WakeUpSleepingThread();    // called to wake up threads
                    // if any when interrupt occured
    bool IsSleepListEmpty() { return sleepList->IsEmpty(); }

    bool IsPreemptive() { return isPreemptive; }
                    // return true if current scheduler is preemptive
    SchedulerType getSchedulerType();

    int CompareThread(Thread* thread1, Thread* thread2);

    void DonatePriority(Thread* doner, Thread* donee);

    bool UpdateReadyList(Thread* updatedThread);    // Update ready list
                // if any thread changes its effective priority

  private:
    SortedList<Thread *> *readyList;  // queue of threads that are ready to run,
				// but not running
    SortedList<PendingThread *> *sleepList;
    Thread *toBeDestroyed;	// finishing thread to be destroyed
    				// by the next thread that runs
    bool isPreemptive;
    SchedulerType schedulerType;
};

#endif // SCHEDULER_H
