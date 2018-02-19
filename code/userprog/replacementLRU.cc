// replacementLRU.cc
//  Routines providing LRU replacement algorithm
//  Assume index of elements is contiguous and unique, and starts with 0

#include "debug.h"
#include "replacementLRU.h"
#include "main.h"

//----------------------------------------------------------------------
// ReplacementLRU::ReplacementLRU
//  Initialize data to maintain LRU strategy.
//
//  "size" -- size of candidates
//----------------------------------------------------------------------

ReplacementLRU::ReplacementLRU(int size)
{
    ASSERT(size > 0);

    this->size = size;
    lastUsed = new int[size];
    ResetStatus();
}

//----------------------------------------------------------------------
// ReplacementLRU::!ReplacementLRU
//  Deallocate data of  LRU strategy.
//----------------------------------------------------------------------

ReplacementLRU::~ReplacementLRU()
{
    delete[] lastUsed;
}

//----------------------------------------------------------------------
// ReplacementLRU::FindOneToLRU
//  Return id of element to be replaced this round. Choose the minimal
//  value of last used time.
//----------------------------------------------------------------------

int
ReplacementLRU::FindOneToReplace()
{
    int target;

    target = 0;
    for (int i = 0; i < size; ++i) {
        if (lastUsed[i] < lastUsed[target]) {
            target = i;
        }
    }

    return target;
}

//----------------------------------------------------------------------
// ReplacementLRU::UpdateElementWeight
//  Assign current time to element with id
//----------------------------------------------------------------------

void
ReplacementLRU::UpdateElementWeight(int id)
{
    lastUsed[id] = kernel->stats->totalTicks;
}

//----------------------------------------------------------------------
// ReplacementLRU::ResetStatus
//  Reset last used time of all entry to -1
//----------------------------------------------------------------------

void
ReplacementLRU::ResetStatus()
{
    for (int i = 0; i < size; ++i) {
        lastUsed[i] = -1;
    }
}
