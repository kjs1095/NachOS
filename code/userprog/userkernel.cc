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
#include "synchdisk.h"
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
    fileSysFormat = FALSE;
    fsCmd = UNUSED;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
	    debugUserProg = TRUE;
        } else if (strcmp(argv[i], "-e") == 0) {
            ASSERT(i + 1 < argc);
            executeFile[numUserProgram] = argv[i +1];
            ++numUserProgram, ++i;
        } else if (strcmp(argv[i], "-format") == 0) {
            fileSysFormat = TRUE;
        } else if (strcmp(argv[i], "-put") == 0) {
            ASSERT(i + 2 < argc);
            strcpy(localPath, argv[i +1]);
            strcpy(nachosPath, argv[i +2]);
            fsCmd = PUT;
        } else if (strcmp(argv[i], "-mkdir") == 0) {
            ASSERT(i +1 < argc);
            strcpy(nachosPath, argv[i +1]);
            fsCmd = MKDIR;
        } else if (strcmp(argv[i], "-ls") == 0) {
            ASSERT(i +1 < argc);
            strcpy(nachosPath, argv[i +1]);
            fsCmd = LIST;
        } else if (strcmp(argv[i], "-rm") == 0) {
            ASSERT(i +1 < argc);
            strcpy(nachosPath, argv[i +1]);
            fsCmd = REMOVE;
        } else if (strcmp(argv[i], "-p") == 0) {
            fsCmd = PRINT;
        } else if (strcmp(argv[i], "-cat") == 0) {
            ASSERT(i +1 < argc);
            fsCmd = CAT;
            strcpy(nachosPath, argv[i +1]);
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
#ifdef FILESYS_STUB
    fileSystem = new FileSystem();
#else
    synchDisk = new SynchDisk("SynchDisk");
    fileSystem = new FileSystem(fileSysFormat);
#endif

    synchConsoleInput = NULL;
    synchConsoleOutput = new SynchConsoleOutput(NULL);

    frameManager = new FrameManager(NumPhysPages);

    coreMapManager = new CoreMapManager(NumPhysPages);
}

//----------------------------------------------------------------------
// UserProgKernel::~UserProgKernel
// 	Nachos is halting.  De-allocate global data structures.
//	Automatically calls destructor on base class.
//----------------------------------------------------------------------

UserProgKernel::~UserProgKernel()
{
    delete coreMapManager;
    delete frameManager;
    delete synchConsoleInput;
    delete synchConsoleOutput;
    delete fileSystem;
#ifdef FILESYS
    delete synchDisk;
#endif
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
 #ifdef FILESYS
    switch (fsCmd) {
        case PUT:
            fileSystem->Put(localPath, nachosPath);
            break;
        case MKDIR:
            fileSystem->Create(nachosPath, -1, TRUE);
            break;
        case LIST:
            fileSystem->List(nachosPath);
            break;
        case PRINT:
            fileSystem->Print();
            break;
        case REMOVE:
            fileSystem->Remove(nachosPath);
            break;
        case CAT:
            fileSystem->Print(nachosPath);
            break;
        case UNUSED:
            break;
        defualt:
            ASSERTNOTREACHED();
            break;
    }
#endif
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
