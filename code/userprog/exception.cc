// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "syscall.h"
#include "synchconsole.h"

int WriteCharsToUserAddrSpace(int addr, char *buf, int limit);
int ReadStringFromUserAddrSpace(int addr, int limit, char *buf);
void AdvancePC();

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler(ExceptionType which)
{
    int type = kernel->machine->ReadRegister(2);
    int arg1;
    char* buf;
    int bufSize;
    OpenFile *openFilePtr;
    OpenFileId userFd;
    int numBytesRW;

    switch (which) {
	case SyscallException:
	    switch(type) {
		case SC_Halt:
		    DEBUG(dbgAddr, "Shutdown, initiated by user program.\n");
   		    kernel->interrupt->Halt();
		    break;
        case SC_Exit:
            arg1 = kernel->machine->ReadRegister(4);
            DEBUG(dbgAddr, "Exit wit return value: " << arg1 
                            << ", initiated by user program.\n");

            kernel->currentThread->Finish();

            return;
        case SC_Create:
            arg1 = kernel->machine->ReadRegister(4);
            buf = new char[MaxFileNameLength +1];
            bufSize = ReadStringFromUserAddrSpace(arg1, MaxFileNameLength, buf);

            if (bufSize <= 0) {
                DEBUG(dbgAddr, "Illegal file name string at address: " 
                                << arg1 << "\n");

                kernel->machine->WriteRegister(2, -1);
            } else if (kernel->fileSystem->Create(buf) == TRUE) {
                DEBUG(dbgAddr, "Create file: " << buf << " succeed.\n");
                
                kernel->machine->WriteRegister(2, 0);
            } else {
                DEBUG(dbgAddr, "Create file: " << buf << " failed.\n");
                
                kernel->machine->WriteRegister(2, -1);
            }

            delete[] buf;

            // Increment the pc before returning.
            AdvancePC();
            return;
        case SC_Open:
            arg1 = kernel->machine->ReadRegister(4);
            buf = new char[MaxFileNameLength +1];
            bufSize = ReadStringFromUserAddrSpace(arg1, MaxFileNameLength, buf);           

            if (bufSize <= 0) {
                DEBUG(dbgAddr, "Illegal file name string at address: " 
                            << arg1 << "\n");
                
                kernel->machine->WriteRegister(2, -1);
            } else {    // length of file name stirng > 0
                openFilePtr = kernel->fileSystem->Open(buf);
                
                if (openFilePtr == NULL) {
                    DEBUG(dbgAddr, "Fail to open file: " << buf << "\n");

                    kernel->machine->WriteRegister(2, -1);
                } else {    // open file accepted by FileSystem
                    userFd = kernel->currentThread->AddOpenFileEntry(openFilePtr);

                    if (userFd == -1) {
                        DEBUG(dbgAddr, "No room for handling more file descriptor of file: " 
                                << buf << "\n");

                        delete openFilePtr;
                        
                        kernel->machine->WriteRegister(2, -1);
                    } else {    // open file accepted by Thread
                        DEBUG(dbgAddr, "Open file: " << buf << 
                                    " with fd : " << userFd << "\n");

                        kernel->machine->WriteRegister(2, userFd);
                    }
                }
            }
            delete[] buf;
 
            // Increment the pc before returning.
            AdvancePC();
            return;
        case SC_Read:
            arg1 = kernel->machine->ReadRegister(4);
            bufSize = kernel->machine->ReadRegister(5);
            userFd = kernel->machine->ReadRegister(6);

            openFilePtr = kernel->currentThread->GetOpenFileEntry(userFd);

            if (openFilePtr == NULL) {
                DEBUG(dbgAddr, "Illegal file descriptor: " << userFd <<"\n");

                kernel->machine->WriteRegister(2, -1);
            } else if (bufSize <= 0) {
                 DEBUG(dbgAddr, "Illegal string length: " << bufSize << "\n");

                 kernel->machine->WriteRegister(2, -1);
            } else { 
                buf = new char[bufSize +1];
                bufSize = openFilePtr->Read(buf, bufSize);

                if (bufSize <= 0) {
                    DEBUG(dbgAddr, "Read failed with file descriptor: " 
                            << userFd << "\n");
                    cout << "read failed : " << userFd << "\n";

                    kernel->machine->WriteRegister(2, -1);
                } else {
                    numBytesRW = WriteCharsToUserAddrSpace(arg1, buf, bufSize);
                    DEBUG(dbgAddr, "Read " << numBytesRW << " bytes."); 

                    kernel->machine->WriteRegister(2, numBytesRW);
                }

                delete[] buf;
            }

            // Increment the pc before returning.
            AdvancePC();
            return;
        case SC_Write:
            arg1 = kernel->machine->ReadRegister(4);
            bufSize = kernel->machine->ReadRegister(5);
            userFd = kernel->machine->ReadRegister(6);

            openFilePtr = kernel->currentThread->GetOpenFileEntry(userFd);

            if (openFilePtr == NULL) {
                DEBUG(dbgAddr, "Illegal file descriptor: " << userFd <<"\n");
                
                kernel->machine->WriteRegister(2, -1);
            } else if (bufSize < 0) {
                 DEBUG(dbgAddr, "Illegal string length: " << bufSize << "\n");
                
                 kernel->machine->WriteRegister(2, -1);
            } else { 
                buf = new char[bufSize +1];
                bufSize = ReadStringFromUserAddrSpace(arg1, bufSize, buf);
                
                if (bufSize <= 0) {
                    DEBUG(dbgAddr, "Illegal string at address: " 
                            << arg1 << "\n");
                
                    kernel->machine->WriteRegister(2, -1);
                } else {
                    numBytesRW = openFilePtr->Write(buf, bufSize);
                    DEBUG(dbgAddr, "Written " << numBytesRW << " bytes."); 

                    kernel->machine->WriteRegister(2, numBytesRW);
                }
            
                delete[] buf; 
            }

            // Increment the pc before returning.
            AdvancePC();
            return;
        case SC_Close:
            arg1 = kernel->machine->ReadRegister(4);
            if (kernel->currentThread->RemoveOpenFileEntry(arg1) == TRUE) {
                DEBUG(dbgAddr, "Close file by file descriptor: " << arg1);
            } else {
                DEBUG(dbgAddr, "Fail to close file by file descriptor: " << arg1);
            }

            // Increment the pc before returning.
            AdvancePC();
            return;
        case SC_PrintInt:
            arg1 = kernel->machine->ReadRegister(4);
            DEBUG(dbgAddr, "Print integer to console\n");
            kernel->synchConsoleOutput->PutInt(arg1);            

            // Increment the pc before returning.
            AdvancePC();
            return;
        case SC_PrintChar:
            arg1 = kernel->machine->ReadRegister(4);
            DEBUG(dbgAddr, "Print char to console\n");
            kernel->synchConsoleOutput->PutChar((char)arg1);    

            // Increment the pc before returning.
            AdvancePC();
            return;
		default:
		    cerr << "Unexpected system call " << type << "\n";
 		    break;
	    }
	    break;
	default:
	    cerr << "Unexpected user mode exception" << which << "\n";
	    break;
    }
    ASSERTNOTREACHED();
}

//----------------------------------------------------------------------
// WriteCharsToUserAddrSpace
//
//  Returns length of string
//
// "addr" -- the virtual address to write to
// "limit" -- max length of string can be written
// "buf" -- source of data
//----------------------------------------------------------------------

int WriteCharsToUserAddrSpace(int addr, char *buf, int limit)
{
    ASSERT(addr >= 0);
    if (limit <= 0)
        return -1;

    int ch;
    int bufSize;
    for (bufSize = 0; bufSize < limit; ++bufSize) {
        ch = (int) buf[bufSize];
        if (kernel->machine->WriteMem(addr + bufSize, 1, ch) == FALSE)
            break;
    }

    return bufSize;
}

//----------------------------------------------------------------------
// ReadStringFromUserAddrSpace
//
//  Returns length of string
//
// "addr" -- the virtual address to read from
// "limit" -- max length of string can be read, no limitation with 0 value
// "buf" -- the place to write the result
//----------------------------------------------------------------------

int ReadStringFromUserAddrSpace(int addr, int limit, char *buf)
{
    ASSERT(addr >= 0);

    int ch;
    int bufSize = 0;
    for (int i = 0; addr > 0 && limit > 0; ++i) {
        if (limit > 0 && i >= limit)
            break;

        kernel->machine->ReadMem(addr + i, 1, &ch);
        if (ch == 0)
            break; 

        buf[bufSize] = (char)ch;
        ++bufSize;
    }

    buf[bufSize] = '\0';
    
    if (addr == 0 || limit <= 0)
        bufSize = -1;

    return bufSize;
}

//----------------------------------------------------------------------
// AdvancePC
//  Advance program counter
//----------------------------------------------------------------------

void AdvancePC()
{
    kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));
    kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(NextPCReg));
    kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg) + sizeof(int));
}
