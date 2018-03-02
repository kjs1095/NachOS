// filehdr.cc 
//	Routines for managing the disk file header (in UNIX, this
//	would be called the i-node).
//
//	The file header is used to locate where on disk the 
//	file's data is stored.  We implement this as a fixed size
//	table of pointers -- each entry in the table points to the 
//	disk sector containing that portion of the file data
//	(in other words, there are no indirect or doubly indirect 
//	blocks). The table size is chosen so that the file header
//	will be just big enough to fit in one disk sector, 
//
//      Unlike in a real system, we do not keep track of file permissions, 
//	ownership, last modification date, etc., in the file header. 
//
//	A file header can be initialized in two ways:
//	   for a new file, by modifying the in-memory data structure
//	     to point to the newly allocated data blocks
//	   for a file already on disk, by reading the file header from disk
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "debug.h"
#include "main.h"
#include "synchdisk.h"
#include "filehdr.h"

//----------------------------------------------------------------------
// FileHeader::FileHeader
//  Initialize empty file header
//----------------------------------------------------------------------

FileHeader::FileHeader()
{
    numBytes = -1;
    numSectors = -1;
    nextFileHeaderSector = -1;
    nextFileHeader = NULL;

    bzero(dataSectors, sizeof(dataSectors));
}

//----------------------------------------------------------------------
// FileHeader::~FileHeader
//  Deallocate the file header data
//----------------------------------------------------------------------

FileHeader::~FileHeader()
{
    if (nextFileHeader != NULL)
        delete nextFileHeader;
}

//----------------------------------------------------------------------
// FileHeader::Allocate
// 	Initialize a fresh file header for a newly created file.
//	Allocate data blocks for the file out of the map of free disk blocks.
//	Return FALSE if there are not enough free blocks to accomodate
//	the new file.
//
//	"freeMap" is the bit map of free disk sectors
//	"fileSize" is the bit map of free disk sectors
//----------------------------------------------------------------------

bool
FileHeader::Allocate(Bitmap *freeMap, int fileSize)
{ 
    int numTotalSectors = divRoundUp(fileSize, SectorSize);
    numBytes = fileSize;
    numSectors  = min(numTotalSectors, (int)NumDirect);
    if (freeMap->NumClear() < numSectors)
	return FALSE;		// not enough space

    for (int i = 0; i < numSectors; i++) {
	    dataSectors[i] = freeMap->FindAndSet();
        if (dataSectors[i] == -1)
            return FALSE;
    }

    if (numTotalSectors > NumDirect) {
        nextFileHeaderSector = freeMap->FindAndSet();
        if (nextFileHeaderSector == -1) {
            return FALSE;
        } else {
            DEBUG(dbgFile, "Allocate next part of file header: " <<
                                nextFileHeaderSector);
            nextFileHeader = new FileHeader;
            return nextFileHeader->Allocate(freeMap,
                                            fileSize - MaxFileSize);
        }
    } else {
        return TRUE;
    }
}

//----------------------------------------------------------------------
// FileHeader::Deallocate
// 	De-allocate all the space allocated for data blocks for this file.
//
//	"freeMap" is the bit map of free disk sectors
//----------------------------------------------------------------------

void 
FileHeader::Deallocate(Bitmap *freeMap)
{
    if (nextFileHeader != NULL) {
        DEBUG(dbgFile, "Deallocate next part of file header: "
                            << nextFileHeaderSector);
        nextFileHeader->Deallocate(freeMap);
    }

    for (int i = 0; i < numSectors; i++) {
	ASSERT(freeMap->Test((int) dataSectors[i]));  // ought to be marked!
	freeMap->Clear((int) dataSectors[i]);
    }
}

//----------------------------------------------------------------------
// FileHeader::FetchFrom
// 	Fetch contents of file header from disk. 
//
//	"sector" is the disk sector containing the file header
//----------------------------------------------------------------------

void
FileHeader::FetchFrom(int sector)
{
    DEBUG(dbgFile, "Fetch file header data from sector: " << sector);
    char buf[SectorSize];
    kernel->synchDisk->ReadSector(sector, buf);

    int offset = 0;
    bcopy(buf + offset, &numBytes, sizeof(numBytes));
    offset += sizeof(numBytes);
    bcopy(buf + offset, &numSectors, sizeof(numSectors));
    offset += sizeof(numSectors);
    bcopy(buf + offset, &nextFileHeaderSector, sizeof(nextFileHeaderSector));
    offset += sizeof(nextFileHeaderSector);
    bcopy(buf + offset, dataSectors, numSectors * sizeof(int));

    if (nextFileHeaderSector != -1) {
        DEBUG(dbgFile, "Go to next file header part: "
                            << nextFileHeaderSector);
        nextFileHeader = new FileHeader;
        nextFileHeader->FetchFrom(nextFileHeaderSector);
    }
}

//----------------------------------------------------------------------
// FileHeader::WriteBack
// 	Write the modified contents of the file header back to disk. 
//
//	"sector" is the disk sector to contain the file header
//----------------------------------------------------------------------

void
FileHeader::WriteBack(int sector)
{
    DEBUG(dbgFile, "Write file header to sector: " << sector);
    char buf[SectorSize];
    bzero(buf, SectorSize * sizeof(char));

    int offset = 0;
    bcopy(&numBytes, buf + offset, sizeof(numBytes));
    offset += sizeof(numBytes);
    bcopy(&numSectors, buf + offset, sizeof(numSectors));
    offset += sizeof(numSectors);
    bcopy(&nextFileHeaderSector, buf + offset, sizeof(nextFileHeaderSector));
    offset += sizeof(nextFileHeaderSector);
    bcopy(dataSectors, buf + offset, numSectors * sizeof(int));

    kernel->synchDisk->WriteSector(sector, buf);

    if (nextFileHeaderSector != -1) {
        DEBUG(dbgFile, "Go to next part of file header: "
                            << nextFileHeaderSector);
        nextFileHeader->WriteBack(nextFileHeaderSector);
    }
}

//----------------------------------------------------------------------
// FileHeader::ByteToSector
// 	Return which disk sector is storing a particular byte within the file.
//      This is essentially a translation from a virtual address (the
//	offset in the file) to a physical address (the sector where the
//	data at the offset is stored).
//
//	"offset" is the location within the file of the byte in question
//----------------------------------------------------------------------

int
FileHeader::ByteToSector(int offset)
{
    if (offset >= MaxFileSize)
        return nextFileHeader->ByteToSector(offset - MaxFileSize);
    else
        return dataSectors[ offset / SectorSize];
}

//----------------------------------------------------------------------
// FileHeader::FileLength
// 	Return the number of bytes in the file.
//----------------------------------------------------------------------

int
FileHeader::FileLength()
{
    if (nextFileHeader != NULL)
        return numBytes + nextFileHeader->FileLength();
    else
        return numBytes;
}

//----------------------------------------------------------------------
// FileHeader::Print
// 	Print the contents of the file header, and the contents of all
//	the data blocks pointed to by the file header.
//----------------------------------------------------------------------

void
FileHeader::Print()
{
    int i, j, k;
    char *data = new char[SectorSize];

    printf("FileHeader contents.  File size: %d.  File blocks:\n", numBytes);
    for (i = 0; i < numSectors; i++)
	printf("%d ", dataSectors[i]);
    printf("\nFile contents:\n");
    for (i = k = 0; i < numSectors; i++) {
	kernel->synchDisk->ReadSector(dataSectors[i], data);
        for (j = 0; (j < SectorSize) && (k < numBytes); j++, k++) {
	    if ('\040' <= data[j] && data[j] <= '\176')   // isprint(data[j])
		printf("%c", data[j]);
            else
		printf("\\%x", (unsigned char)data[j]);
	}
        printf("\n"); 
    }
    delete [] data;

    if (nextFileHeader != NULL)
        nextFileHeader->Print();
}
