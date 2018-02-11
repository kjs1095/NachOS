// framemanager.cc 
//  Routines for providing synchronized acquire and releaes available
//  physical frames. 

#include "framemanager.h"

//----------------------------------------------------------------------
// FrameManager::FrameManager
//  Initialize synchronized access to the status of memory frames.
//
//  "numFrames" - Num of total physical memory frame
//----------------------------------------------------------------------

FrameManager::FrameManager(int numFrames)
{
    frameUsageBitmap = new Bitmap(numFrames);
    lock = new Lock("lock for frame management");
}

//----------------------------------------------------------------------
// FrameManager::~FrameManager
//  Deallocate data structures for synchronized access to the status
//  of memory frames.
//----------------------------------------------------------------------

FrameManager::~FrameManager()
{
    delete frameUsageBitmap;
    delete lock;
}

//----------------------------------------------------------------------
// FrameManager::Acquire
//  Atomically request an available physical frame id.
//  Return -1 if there is no any available frame.
//----------------------------------------------------------------------

int FrameManager::Acquire()
{
    int frameNumber = -1;

    lock->Acquire();
    frameNumber = frameUsageBitmap->FindAndSet();
    lock->Release();

    return frameNumber;
}

//----------------------------------------------------------------------
// FrameManager::Release
//  Atomically release a frame by frame id.
//
// "frameNumber" is the id of frame to be available
//----------------------------------------------------------------------

void FrameManager::Release(int frameNumber)
{
    lock->Acquire();
    frameUsageBitmap->Clear(frameNumber);
    lock->Release();
}

//----------------------------------------------------------------------
// FrameManager::GetNumAvailFrames
//  Atomically get number of free frames.
//  Return number of free frames.
//----------------------------------------------------------------------


int FrameManager::GetNumAvailFrames()
{
    int numAvailFrames = 0;

    lock->Acquire();
    numAvailFrames = frameUsageBitmap->NumClear();
    lock->Release();

    return numAvailFrames;
}
