// tlbmanager.h
//  Data structure for managing TLB component.

#ifndef TLBMANAGER
#define TLBMANAGER

#include "translate.h"
#include "replacementstrategy.h"

// The following class defiens a "TLB manager" -- a manager for
// manipulate TLB entries.

class TLBManager {
  public:
    TLBManager(int size);
    ~TLBManager();

    void CachePageEntry(TranslationEntry *pageEntry);
            // The way to initialize entry of TLB
    TranslationEntry* FetchPageEntry(int vpn);
            // Fetch specified entry with ritvual page number = vpn.
    void CleanTLB();
            // Invalidate all entries when contex-switch occured

  private:
    int FindEntryToCache();
            // Determine the slot to cache new entry
            // Use internally by FetchPageEntry

    int tlbSize;
    TranslationEntry *tlb;
    ReplacementStrategy* strategy;
};

#endif
