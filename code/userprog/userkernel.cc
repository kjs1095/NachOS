// userkernel.cc 
//	Initialization and cleanup routines for the version of the
//	Nachos kernel that supports running user programs.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synchconsole.h"
#include "framemanager.h"
#include "userkernel.h"

//----------------------------------------------------------------------
// UserProgKernel::UserProgKernel
// 	Interpret command line arguments in order to determine flags 
//	for the initialization (see also comments in main.cc)  
//----------------------------------------------------------------------

UserProgKernel::UserProgKernel(int argc, char **argv) 
		: ThreadedKernel(argc, argv)
{
    debugUserProg = FALSE;
    numUserProgram = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
	    debugUserProg = TRUE;
        } else if (strcmp(argv[i], "-e") == 0) {
            ASSERT(i + 1 < argc);
            executeFile[numUserProgram] = argv[i +1];
            ++numUserProgram, ++i;
        } else if (strcmp(argv[i], "-u") == 0) {
            cout << "Partial usage: nachos [-s]\n";
	}
    }
}

//----------------------------------------------------------------------
// UserProgKernel::Initialize
// 	Initialize Nachos global data structures.
//----------------------------------------------------------------------

void
UserProgKernel::Initialize()
{
    ThreadedKernel::Initialize();	// init multithreading

    machine = new Machine(debugUserProg);
    fileSystem = new FileSystem();

    synchConsoleInput = NULL;
    synchConsoleOutput = new SynchConsoleOutput(NULL);

    frameManager = new FrameManager(NumPhysPages);
}

//----------------------------------------------------------------------
// UserProgKernel::~UserProgKernel
// 	Nachos is halting.  De-allocate global data structures.
//	Automatically calls destructor on base class.
//----------------------------------------------------------------------

UserProgKernel::~UserProgKernel()
{
    delete frameManager;
    delete synchConsoleInput;
    delete synchConsoleOutput;
    delete fileSystem;
    delete machine;
}

//----------------------------------------------------------------------
// UserProgKernel::ForkExecute
//  Run user program, executable file path is the nane of thread
//----------------------------------------------------------------------
static void
ForkExecute(Thread *t)
{
    DEBUG(dbgThread, "Path of executable file: " << t->getName());
    t->space->Execute(t->getName());
}

//----------------------------------------------------------------------
// UserProgKernel::Run
// 	Run the Nachos kernel.  For now, just run the "halt" program. 
//----------------------------------------------------------------------

void
UserProgKernel::Run()
{
    DEBUG(dbgThread, "#User Program: " << numUserProgram);
    for (int i = 0; i < numUserProgram; ++i) {
        userThread[i] = new Thread(executeFile[i]);
        userThread[i]->space = new AddrSpace();
        userThread[i]->Fork((VoidFunctionPtr)ForkExecute, (void *) userThread[i]);
    }

    ThreadedKernel::Run();
}

//----------------------------------------------------------------------
// UserProgKernel::SelfTest
//      Test whether this module is working.
//----------------------------------------------------------------------

void
UserProgKernel::SelfTest() {
/*    char ch;

    ThreadedKernel::SelfTest();

    // test out the console device

    cout << "Testing the console device.\n" 
	<< "Typed characters will be echoed, until q is typed.\n"
    	<< "Note newlines are needed to flush input through UNIX.\n";
    cout.flush();

    SynchConsoleInput *input = new SynchConsoleInput(NULL);
    SynchConsoleOutput *output = new SynchConsoleOutput(NULL);

    do {
    	ch = input->GetChar();
    	output->PutChar(ch);   // echo it!
    } while (ch != 'q');

    cout << "\n";

    delete input;
    delete output;

    input = NULL;
    output = NULL;*/
    // self test for running user programs is to run the halt program above
}
