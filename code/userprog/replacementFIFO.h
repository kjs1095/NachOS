// replacementFIFO.h
//  Data structure for implementing FIFO (First-In First-Out)
//  replacement algorithm.

#ifndef REPLACEMENTFIFO
#define REPLACEMENTFIFO

#include "replacementstrategy.h"

// The following class defines FIFO algorithm to choose
// next element to replace from elements with index (start
// from 0) and fixed size.

class ReplacementFIFO : public ReplacementStrategy {
  public:
    ReplacementFIFO(int size);
    virtual ~ReplacementFIFO() {}

    virtual int FindOneToReplace();
    virtual void UpdateElementWeight(int id) {}
    virtual void ResetStatus() { replaceId = 0; }

  private:
    int size;
    int replaceId;
};

#endif
