// pbitmap.h 
//	Data structures defining a "persistent" bitmap -- a bitmap
//	that can be stored and fetched off of disk
//
// Copyright (c) 1992,1993,1995 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef PBITMAP_H
#define PBITMAP_H

#include "copyright.h"
#include "bitmap.h"
#include "openfile.h"

// The following class defines a persistent bitmap.  It inherits all
// the behavior of a bitmap (see bitmap.h), adding the ability to
// be read from and stored to the disk.

class PersistBitMap : public Bitmap {
  public:
    PersistBitMap(int numItems);

    ~PersistBitMap(); 			// deallocate bitmap

    void FetchFrom(OpenFile *file);     // read bitmap contents from disk

    void WriteBack(OpenFile *file); 	// write bitmap contents to disk 
};

#endif // PBITMAP_H
