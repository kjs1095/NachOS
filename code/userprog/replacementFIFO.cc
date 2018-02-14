// replacementFIFO.cc
//  Routines providing FIFO replacement algorithm
//  Assume index of elements is contiguous and unique, and starts with 0

#include "debug.h"
#include "replacementFIFO.h"

//----------------------------------------------------------------------
// ReplacementFIFO::ReplacementFIFO
//  Initialize data to maintain FIFO strategy.
//
//  "size" -- size of candidates
//----------------------------------------------------------------------

ReplacementFIFO::ReplacementFIFO(int size)
{
    ASSERT(size > 0);

    this->size = size;
    replaceId = 0;
}

//----------------------------------------------------------------------
// ReplacementFIFO::FindOneToReplace
//  Return id of element to be replaced this round. It's the next element
//  of previous result. The pointer would move circular by mod operation.
//----------------------------------------------------------------------

int
ReplacementFIFO::FindOneToReplace()
{
    int target = replaceId;
    replaceId = (replaceId +1) % size;

    DEBUG(dbgPage, "Id of replaced candidate: " << target);
    return target;
}
