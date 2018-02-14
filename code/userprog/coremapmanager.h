// coremapmanager.h
//  Data structure for managing core map

#ifndef COREMAPMANAGER
#define COREMAPMANAGER

#include "translate.h"

class AddrSpace;

// The following class defiens data structure of core
// map entry.

class CoreMapEntry {
  public:
    CoreMapEntry() {
        vpn = -1;
        owner = NULL;
    }
    ~CoreMapEntry() {
        owner = NULL;
    }

    int vpn;
    AddrSpace *owner;
};

// The following class defiens a "Core map manager" -- a manager for
// manipulate core map entries.

class CoreMapManager {
  public:
    CoreMapManager(int size);
    ~CoreMapManager();

    void PushEntryToTLB(int vpn);
        // Push specifed page entry to TLB by givn virtual page number (vpn)

    void SyncPage(int ppn, int vpn, TranslationEntry* tlbEntry);
        // Synchroize attributes of TLB entry and corrosponding page entry

  private:
    TranslationEntry* FetchPageEntry(int vpn);
            // Determine the slot to cache new entry
            // Use internally by PushEntryToTLB
    // TODO frame repalce swap strategy

    int pageTableSize;
    CoreMapEntry **coreMap;
};

#endif
