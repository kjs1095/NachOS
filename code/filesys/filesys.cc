// filesys.cc 
//	Routines to manage the overall operation of the file system.
//	Implements routines to map from textual file names to files.
//
//	Each file in the file system has:
//	   A file header, stored in a sector on disk 
//		(the size of the file header data structure is arranged
//		to be precisely the size of 1 disk sector)
//	   A number of data blocks
//	   An entry in the file system directory
//
// 	The file system consists of several data structures:
//	   A bitmap of free disk sectors (cf. bitmap.h)
//	   A directory of file names and file headers
//
//      Both the bitmap and the directory are represented as normal
//	files.  Their file headers are located in specific sectors
//	(sector 0 and sector 1), so that the file system can find them 
//	on bootup.
//
//	The file system assumes that the bitmap and directory files are
//	kept "open" continuously while Nachos is running.
//
//	For those operations (such as Create, Remove) that modify the
//	directory and/or bitmap, if the operation succeeds, the changes
//	are written immediately back to disk (the two files are kept
//	open during all this time).  If the operation fails, and we have
//	modified part of the directory and/or bitmap, we simply discard
//	the changed version, without writing it back to disk.
//
// 	Our implementation at this point has the following restrictions:
//
//	   there is no synchronization for concurrent accesses
//	   files have a fixed size, set when the file is created
//	   files cannot be bigger than about 3KB in size
//	   there is no hierarchical directory structure, and only a limited
//	     number of files can be added to the system
//	   there is no attempt to make the system robust to failures
//	    (if Nachos exits in the middle of an operation that modifies
//	    the file system, it may corrupt the disk)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "disk.h"
#include "bitmap.h"
#include "directory.h"
#include "filehdr.h"
#include "filesys.h"
#include "debug.h"
#include "pbitmap.h"

// Sectors containing the file headers for the bitmap of free sectors,
// and the directory of files.  These file headers are placed in well-known 
// sectors, so that they can be located on boot-up.
#define FreeMapSector 		0
#define DirectorySector 	1

// Initial file sizes for the bitmap and directory; until the file system
// supports extensible files, the directory size sets the maximum number 
// of files that can be loaded onto the disk.
#define FreeMapFileSize 	(NumSectors / BitsInByte)
#define NumDirEntries 		64
#define DirectoryFileSize 	(sizeof(DirectoryEntry) * NumDirEntries)
#define PathMaxLen          255

//----------------------------------------------------------------------
// FileSystem::FileSystem
// 	Initialize the file system.  If format = TRUE, the disk has
//	nothing on it, and we need to initialize the disk to contain
//	an empty directory, and a bitmap of free sectors (with almost but
//	not all of the sectors marked as free).  
//
//	If format = FALSE, we just have to open the files
//	representing the bitmap and the directory.
//
//	"format" -- should we initialize the disk?
//----------------------------------------------------------------------

FileSystem::FileSystem(bool format)
{ 
    DEBUG(dbgFile, "Initializing the file system.");
    if (format) {
        PersistBitMap *freeMap = new PersistBitMap(NumSectors);
        Directory *directory = new Directory(NumDirEntries);
	FileHeader *mapHdr = new FileHeader();
	FileHeader *dirHdr = new FileHeader();

        DEBUG(dbgFile, "Formatting the file system.");

    // First, allocate space for FileHeaders for the directory and bitmap
    // (make sure no one else grabs these!)
	freeMap->Mark(FreeMapSector);	    
	freeMap->Mark(DirectorySector);

    // Second, allocate space for the data blocks containing the contents
    // of the directory and bitmap files.  There better be enough space!

	ASSERT(mapHdr->Allocate(freeMap, FreeMapFileSize));
	ASSERT(dirHdr->Allocate(freeMap, DirectoryFileSize));

    // Flush the bitmap and directory FileHeaders back to disk
    // We need to do this before we can "Open" the file, since open
    // reads the file header off of disk (and currently the disk has garbage
    // on it!).

        DEBUG(dbgFile, "Writing headers back to disk.");
	mapHdr->WriteBack(FreeMapSector);    
	dirHdr->WriteBack(DirectorySector);

    // OK to open the bitmap and directory files now
    // The file system operations assume these two files are left open
    // while Nachos is running.

        freeMapFile = new OpenFile(FreeMapSector);
        directoryFile = new OpenFile(DirectorySector);
     
    // Once we have the files "open", we can write the initial version
    // of each file back to disk.  The directory at this point is completely
    // empty; but the bitmap has been changed to reflect the fact that
    // sectors on the disk have been allocated for the file headers and
    // to hold the file data for the directory and bitmap.

        DEBUG(dbgFile, "Writing bitmap and directory back to disk.");
	freeMap->WriteBack(freeMapFile);	 // flush changes to disk
	directory->WriteBack(directoryFile);

	if (debug->IsEnabled('f')) {
	    freeMap->Print();
	    directory->Print();
        }
        delete freeMap; 
	delete directory; 
	delete mapHdr; 
	delete dirHdr;
    } else {
    // if we are not formatting the disk, just open the files representing
    // the bitmap and directory; these are left open while Nachos is running
        freeMapFile = new OpenFile(FreeMapSector);
        directoryFile = new OpenFile(DirectorySector);
    }
}

//----------------------------------------------------------------------
// FileSystem::~FileSystem
// 	Deallocate the free map and directory file descriptor in file system.
//----------------------------------------------------------------------

FileSystem::~FileSystem()
{
    delete freeMapFile;
    delete directoryFile;
}

//----------------------------------------------------------------------
// FileSystem::Create
// 	Create a file in the Nachos file system (similar to UNIX create).
//	Since we can't increase the size of files dynamically, we have
//	to give Create the initial size of the file.
//
//	The steps to create a file are:
//	  Make sure the file doesn't already exist
//        Allocate a sector for the file header
// 	  Allocate space on disk for the data blocks for the file
//	  Add the name to the directory
//	  Store the new file header on disk 
//	  Flush the changes to the bitmap and the directory back to disk
//
//	Return TRUE if everything goes ok, otherwise, return FALSE.
//
// 	Create fails if:
//   		file is already in directory
//	 	no free space for file header
//	 	no free entry for file in directory
//	 	no free space for data blocks for the file 
//
// 	Note that this implementation assumes there is no concurrent access
//	to the file system!
//
//	"name" -- name of file to be created
//	"initialSize" -- size of file to be created
//  "isDir" -- file or subdirectory to be created
//----------------------------------------------------------------------

bool
FileSystem::Create(char *path, int initialSize, bool isDir)
{
    Directory *directory;
    PersistBitMap *freeMap;
    FileHeader *hdr;
    char name[FileNameMaxLen +1];
    int sector;
    bool success;

    DEBUG(dbgFile, "Creating file " << path << " size " << initialSize);

    if(isDir)   initialSize = DirectoryFileSize;

    OpenFile *curDirectoryFile = FindSubDirectory(path);
    if (curDirectoryFile == NULL)
        return FALSE;    // path is illegal

    directory = new Directory(NumDirEntries);
    directory->FetchFrom(curDirectoryFile);
    GetLastElementOfPath(path, name);
    DEBUG(dbgFile, "Added File/Directory: " << name);

    if (directory->Find(name) != -1)
      success = FALSE;			// file is already in directory
    else {	
        freeMap = new PersistBitMap(NumSectors);
        freeMap->FetchFrom(freeMapFile);
        sector = freeMap->FindAndSet();	// find a sector to hold the file header
        if (sector == -1)
            success = FALSE;		// no free block for file header 
        else if (!directory->Add(name, sector, isDir)) {
            success = FALSE;	// no space in directory
            freeMap->Clear(sector);
        } else {
    	    hdr = new FileHeader();
	    if (!hdr->Allocate(freeMap, initialSize)) {
            success = FALSE;	// no space on disk for data
	        hdr->Deallocate(freeMap);
            freeMap->Clear(sector);
            directory->Remove(name);
        } else {
	    	success = TRUE;
		// everthing worked, flush all changes back to disk
    	    	hdr->WriteBack(sector); 		
                directory->WriteBack(curDirectoryFile);
    	    	freeMap->WriteBack(freeMapFile);
	    }
            delete hdr;
	}
        delete freeMap;
    }
    delete curDirectoryFile;
    delete directory;
    return success;
}

//----------------------------------------------------------------------
// FileSystem::Open
// 	Open a file for reading and writing.  
//	To open a file:
//	  Find the location of the file's header, using the directory 
//	  Bring the header into memory
//
//	"path" -- the path of the file to be opened
//----------------------------------------------------------------------

OpenFile *
FileSystem::Open(char *path)
{ 
    Directory *directory = new Directory(NumDirEntries);
    OpenFile *openFile = NULL;
    int sector;

    DEBUG(dbgFile, "Opening file" << path);
    OpenFile *curDirectoryFile = FindSubDirectory(path);
    if (curDirectoryFile != NULL) {
        directory->FetchFrom(curDirectoryFile);
        char fileName[FileNameMaxLen +1];
        GetLastElementOfPath(path, fileName);
        sector = directory->Find(fileName);
        if (sector >= 0 && !directory->IsDir(fileName))
	        openFile = new OpenFile(sector);	// name was found in directory
        delete curDirectoryFile;
    }

    delete directory;
    return openFile;				// return NULL if not found
}

//----------------------------------------------------------------------
// FileSystem::Remove
// 	Delete a file from the file system.  This requires:
//	    Remove it from the directory
//	    Delete the space for its header
//	    Delete the space for its data blocks
//	    Write changes to directory, bitmap back to disk
//
//	Return TRUE if the file was deleted, FALSE if the file wasn't
//	in the file system.
//
//	"path" -- the path of the file to be removed
//----------------------------------------------------------------------

bool
FileSystem::Remove(char *path)
{ 
    Directory *directory;
    PersistBitMap *freeMap;
    FileHeader *fileHdr;
    int sector;
    char fileName[FileNameMaxLen +1];
    
    OpenFile *curDirectoryFile = FindSubDirectory(path);
    if (curDirectoryFile == NULL)
        return FALSE;    // path is illegal

    directory = new Directory(NumDirEntries);
    directory->FetchFrom(curDirectoryFile);
    GetLastElementOfPath(path, fileName);
    DEBUG(dbgFile, "Remove File: " << fileName);

    sector = directory->Find(fileName);
    if (sector == -1 || directory->IsDir(fileName)) {
       delete curDirectoryFile;
       delete directory;
       return FALSE;			 // file not found 
    }
    fileHdr = new FileHeader;
    fileHdr->FetchFrom(sector);

    freeMap = new PersistBitMap(NumSectors);
    freeMap->FetchFrom(freeMapFile);

    fileHdr->Deallocate(freeMap);  		// remove data blocks
    freeMap->Clear(sector);			// remove header block
    directory->Remove(fileName);

    directory->WriteBack(curDirectoryFile);    // flush to disk
    freeMap->WriteBack(freeMapFile);		// flush to disk
    delete curDirectoryFile;
    delete fileHdr;
    delete directory;
    delete freeMap;
    return TRUE;
} 

//----------------------------------------------------------------------
// FileSystem::List
// 	List all the files in the file system directory.
//
// "path" -- the path of file/directory to be listed
//----------------------------------------------------------------------

void
FileSystem::List(char *path)
{
    Directory *directory = new Directory(NumDirEntries);
    OpenFile *curDirectoryFile;
    int sector = -1;

    DEBUG(dbgFile, "List file/directory: " << path);
    if (strcmp(path, "/") == 0) {
        sector = DirectorySector;
    } else {
        curDirectoryFile = FindSubDirectory(path);
        char name[FileNameMaxLen +1];
        GetLastElementOfPath(path, name);
        if (curDirectoryFile != NULL) {
            directory->FetchFrom(curDirectoryFile); 
            sector = directory->Find(name);
            if (sector != -1 && !directory->IsDir(name)) {
                printf("FILE %s\n", name);
                sector = -1;
            }

            delete curDirectoryFile;
        }
    }

    if (sector != -1) {
        curDirectoryFile = new OpenFile(sector);
        directory->FetchFrom(curDirectoryFile);
        directory->List();
        delete curDirectoryFile;
    }

    delete directory;
}

//----------------------------------------------------------------------
// FileSystem::Print
// 	Print everything about the file system:
//	  the contents of the bitmap
//	  the contents of the directory
//	  for each file in the directory,
//	      the contents of the file header
//	      the data in the file
//----------------------------------------------------------------------

void
FileSystem::Print()
{
    FileHeader *bitHdr = new FileHeader;
    FileHeader *dirHdr = new FileHeader;
    PersistBitMap *freeMap = new PersistBitMap(NumSectors);
    Directory *directory = new Directory(NumDirEntries);

    printf("Bit map file header:\n");
    bitHdr->FetchFrom(FreeMapSector);
    bitHdr->Print();

    printf("Directory file header:\n");
    dirHdr->FetchFrom(DirectorySector);
    dirHdr->Print();

    freeMap->FetchFrom(freeMapFile);
    freeMap->Print();

    directory->FetchFrom(directoryFile);
    directory->Print();

    delete bitHdr;
    delete dirHdr;
    delete freeMap;
    delete directory;
}

//----------------------------------------------------------------------
// FileSystem::Print
// 	Print contents of the file with specified path
//
// "path" -- the path of file to be printed
//----------------------------------------------------------------------

void
FileSystem::Print(char *path)
{
    DEBUG(dbgFile, "Print content of file: " << path);
    OpenFile *curDirectoryFile = FindSubDirectory(path);
    if (curDirectoryFile == NULL)
        return;

    char fileName[FileNameMaxLen +1];
    GetLastElementOfPath(path, fileName);
    Directory *directory = new Directory(NumDirEntries);
    directory->FetchFrom(directoryFile);
    int sector = directory->Find(fileName);

    if (sector != -1 && !directory->IsDir(fileName)) {
        FileHeader *hdr = new FileHeader;
        hdr->FetchFrom(sector);
        hdr->Print();
        delete hdr;
    }

    delete directory;
    delete curDirectoryFile;
}

//----------------------------------------------------------------------
// FileSystem::Put
// 	Move the file from Linux FS to NachOS FS
//
// "localPath" is the source path of file in Linux FS
// "nachosPath" is the target path of file in NachOS FS
//----------------------------------------------------------------------

void
FileSystem::Put(char *localPath, char *nachosPath)
{
    Copy(localPath, nachosPath);
}

//----------------------------------------------------------------------
// FileSystem::GetLastElementOfPath
//  Split path string by '/', copy last element to result variable
//
// "path" - the source path
// "result" - pointer to store result
//----------------------------------------------------------------------

void
FileSystem::GetLastElementOfPath(char *path, char *result)
{
    char tmpPath[PathMaxLen +1];
    strcpy(tmpPath, path);
    char parent[] = "/";
    char *child = strtok(tmpPath, "/");

    while (child != NULL) {
        sscanf(child, "%s", parent);
        child = strtok(NULL, "/");
    }
    strcpy(result, parent);

    DEBUG(dbgFile, "Last element of path: " << result);
}

//----------------------------------------------------------------------
// FileSystem::FindSubDirectory
//  Return open file descriptor of lowest directory
//  1.  Read directory file
//  2.  Find next level file or directory
//  3a. Break when the name of next level doesn't exist
//   b. Or move on to next level
//  4.  Break when next level is file
//
//  Clean data if (1) file/dir doesn't not exist (2) not last element
//
// case 1: /dir1/dir2/file
// case 2: /dir1/dir2
// case 3: /
// case 4: /file
// case 5: /dir1/file/dir2
// 
// "path" - the source path
//----------------------------------------------------------------------

OpenFile*
FileSystem::FindSubDirectory(char *path)
{
    Directory *directory = new Directory(NumDirEntries);
    OpenFile* curDirectoryFile = NULL;
    int sector = DirectorySector;
    char tmpPath[PathMaxLen +1];
    strcpy(tmpPath, path);
    char parent[FileNameMaxLen +1] = "/";
    char *child = strtok(tmpPath, "/");

    while (child != NULL) {
        char *next = strtok(NULL, "/");
        curDirectoryFile = new OpenFile(sector);
        if (next == NULL)
            break;

        directory->FetchFrom(curDirectoryFile);
        sector = directory->Find(child);
        if (sector == -1)
            break;

        strcpy(parent, child);
        child = next;

        if (!directory->IsDir(parent))
            break;

        delete curDirectoryFile;    // prevent memory leak
    }

    if (sector == -1 || (strcmp(parent, "/") != 0 && !directory->IsDir(parent))) {
        if (curDirectoryFile != NULL)
            delete curDirectoryFile;
        curDirectoryFile = NULL;
    }

    delete directory;
    return curDirectoryFile;
} 
