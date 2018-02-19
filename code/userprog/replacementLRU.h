// replacementLRU.h
//  Data structure for implementing LRU (Least Recently Used)
//  replacement algorithm.

#ifndef REPLACEMENTLRU
#define REPLACEMENTLRU

#include "list.h"
#include "replacementstrategy.h"

// The following class defines LRU algorithm to choose
// next element to replace from elements with index (start
// from 0) and fixed size.

class ReplacementLRU : public ReplacementStrategy {
  public:
    ReplacementLRU(int size);
    virtual ~ReplacementLRU();

    virtual int FindOneToReplace();
    virtual void UpdateElementWeight(int id);
    virtual void ResetStatus();

  private:
    int size;
    int* lastUsed;
};

#endif
