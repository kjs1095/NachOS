// userkernel.h
//	Global variables for the Nachos kernel, for the assignment
//	supporting running user programs.
//
//	The kernel supporting user programs is a version of the 
//	basic multithreaded kernel.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef USERKERNEL_H  
#define USERKERNEL_H

#include "kernel.h"
#include "filesys.h"
#include "machine.h"
#include "coremapmanager.h"

#define NumMaxUserProgram  5   // Maximum #user programs 
                            // can be executed in NachOS
#define MaxPathLen  255 // Maximum length of file path

class SynchConsoleInput;
class SynchConsoleOutput;

class FrameManager;

class SynchDisk;

enum FsCmd {
    UNUSED,
    PUT,
    LIST,
    PRINT,
    REMOVE
};

class UserProgKernel : public ThreadedKernel {
  public:
    UserProgKernel(int argc, char **argv);
				// Interpret command line arguments
    ~UserProgKernel();		// deallocate the kernel

    void Initialize();		// initialize the kernel 

    void Run();			// do kernel stuff 

    void SelfTest();		// test whether kernel is working

// These are public for notational convenience.
    Machine *machine;
    FileSystem *fileSystem;

    SynchConsoleInput *synchConsoleInput;
    SynchConsoleOutput *synchConsoleOutput;

    FrameManager *frameManager;

    CoreMapManager *coreMapManager;

#ifdef FILESYS
    SynchDisk *synchDisk;
#endif // FILESYS

  private:
    bool debugUserProg;		// single step user program
    Thread *userThread[NumMaxUserProgram];
    char *executeFile[NumMaxUserProgram];
    int numUserProgram;

    bool fileSysFormat;
    FsCmd fsCmd;
    char localPath[MaxPathLen +1];
    char nachosPath[MaxPathLen +1];
};

#endif
