// framemanager.h 
//  Data structures for synchronized acquire free physical
//  memory frames and release occupied frames when thread
//  finish.

#ifndef FRAMEMANAGER_H
#define FRAMEMANAGER_H

#include "bitmap.h"
#include "synch.h"

// The following class defines a "frame manager" -- a manager for 
// holding one thread at a time can access frame manager data
// structure.

class FrameManager {
  public:
    FrameManager(int numFrames);
    ~FrameManager();

    int Acquire();
    void Release(int frameNumber);

    int GetNumAvailFrames();

  private:
    Bitmap *frameUsageBitmap;
    Lock *lock;
};

#endif  // FRAMEMANAGER_H
