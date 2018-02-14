// coremapmanager.cc
//  Routines for manipulate core map entries

#include "debug.h"
#include "coremapmanager.h"
#include "framemanager.h"
#include "main.h"

//----------------------------------------------------------------------
// CoreMapManager::CoreMapManager
//  Initialize core map
//
//  "size" -- size of core map (as same as frame table size)
//----------------------------------------------------------------------

CoreMapManager::CoreMapManager(int size)
{
    pageTableSize = size;
    coreMap = new CoreMapEntry*[size];
    for (int i = 0; i < size; ++i)
        coreMap[i] = new CoreMapEntry();
}

//----------------------------------------------------------------------
// CoreMapManager::~CoreMapManager
//  Deallocate core map
//----------------------------------------------------------------------

CoreMapManager::~CoreMapManager()
{
    for (int i = 0; i < pageTableSize; ++i)
        delete coreMap[i];
    delete[] coreMap;
}

//----------------------------------------------------------------------
// CoreMapManager::PushEntryToTLB
//  Push specifed entry of current thread to TLB by virtual page number.
//  If the page entry is not in memory, swap-out a page (if needed) to
//  disk and swap-in it from disk.
//
// "vpn" is the virtual page number of page entry need to cache in TLB
//----------------------------------------------------------------------

void
CoreMapManager::PushEntryToTLB(int vpn)
{
    // 1. find specified page entry
    TranslationEntry *targetEntry = FetchPageEntry(vpn);

    // 2. if not found, swap in and swap out
    if (targetEntry == NULL) {
        // 1. get empty entry
        int availPageEntryId = kernel->frameManager->Acquire();

        // 2. if not, swap in, and return its id, atomic occupy id
        if (availPageEntryId == -1) {
        }

        DEBUG(dbgPage, "Available Physical Page Entry: " << availPageEntryId);
        // 3. notify addrSpace to load
        targetEntry = kernel->currentThread->space->LoadPageFromDisk(vpn, availPageEntryId);
        coreMap[availPageEntryId]->vpn = vpn;
        coreMap[availPageEntryId]->owner = kernel->currentThread->space;

        kernel->stats->numPageFaults += 1;
    }

    // 3. push entry to tlb
    kernel->machine->tlbManager->CachePageEntry(targetEntry);
}

//----------------------------------------------------------------------
// CoreMapManager::FetchPageEntry
//  Return specified page entry of current thread in core map by virtual
//  page number (vpn)
//
// "vpn" is the virtual page number of current thread
//----------------------------------------------------------------------

TranslationEntry*
CoreMapManager::FetchPageEntry(int vpn)
{
    TranslationEntry *target = NULL;
    for (int i = 0; i < pageTableSize; ++i) {
        if (coreMap[i]->vpn == vpn &&
            coreMap[i]->owner == kernel->currentThread->space) {
            target = coreMap[i]->owner->GetPageTableEntry(vpn);
        }
    }

    return target;
}

//----------------------------------------------------------------------
// CoreMapManager::SyncPage
//  Synchronize attributes of TLB entry and corrosponding page entry
//
// "ppn" is the physical frame number
// "vpn" is the virtual page number
// "tlbEntry" is the pointer of TLB entry
//----------------------------------------------------------------------

void
CoreMapManager::SyncPage(int ppn, int vpn, TranslationEntry *tlbEntry)
{
    coreMap[ppn]->owner->SyncPageAttributes(vpn, tlbEntry);
}
