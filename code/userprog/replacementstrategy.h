// ReplacementStrategy.h
//  Interface for replacement algorithm.

#ifndef REPLACEMENTSTRATEGY
#define REPLACEMENTSTRATEGY

// The following abstract class defines interface of a
// replacement algorithm.
//
// FindOneToReplace - Return id of element which would be replaced.
//
// UpdateElementWeight - Adjust weight of specified element with
//                       index = "id"
//
// ResetStatus - Reset state of replacement policy when context-switch
//               occured.

class ReplacementStrategy {
  public:
    virtual int FindOneToReplace() = 0;
    virtual void UpdateElementWeight(int id) = 0;
    virtual void ResetStatus() = 0;
};

#endif
