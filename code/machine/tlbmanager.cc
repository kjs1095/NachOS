// tlbmanager.cc
//  Routines for manipulate TLB entries

#include "debug.h"
#include "tlbmanager.h"
#include "replacementLRU.h"

//----------------------------------------------------------------------
// TLBManager::TLBManager
//  Initialize TLB entires
//
//  "size" -- size of TLB
//----------------------------------------------------------------------

TLBManager::TLBManager(int size)
{
    ASSERT(size > 0);

    tlbSize = size;
    tlb = new TranslationEntry[tlbSize];
    for (int i = 0; i < tlbSize; ++i) {
        tlb[i].valid = FALSE;
        tlb[i].dirty = FALSE;
    }

    strategy = new ReplacementLRU(size);
}

//----------------------------------------------------------------------
// TLBManager::~TLBManager
//  Deallocate data of TLB
//----------------------------------------------------------------------

TLBManager::~TLBManager()
{
    delete[] tlb;
    delete strategy;
}

//----------------------------------------------------------------------
// TLBManager::CachePageEntry
//  Cache one page entry of current thread.
//
//  "pageEntry" is one of page entries of current thread
//----------------------------------------------------------------------

void
TLBManager::CachePageEntry(TranslationEntry *pageEntry)
{
    int targetEntryId = FindEntryToCache();
    tlb[ targetEntryId ] = *pageEntry;
    tlb[ targetEntryId ].valid = TRUE;
    strategy->UpdateElementWeight(targetEntryId);

    DEBUG(dbgPage, "TLB ["<< targetEntryId  <<"] cache page: "
                << pageEntry->virtualPage);
}

//----------------------------------------------------------------------
// TLBManager::FinEntryToCache
//  Find a entry with specified virtual page number (vpn) and the entry
//  is belong to current thread.
//
// "vpn" is the virutal page number of entry we want
//----------------------------------------------------------------------

TranslationEntry*
TLBManager::FetchPageEntry(int vpn)
{
    TranslationEntry* target = NULL;
    for (int i = 0; i < tlbSize; ++i) {
        if (tlb[i].valid && (tlb[i].virtualPage == vpn)) {
            strategy->UpdateElementWeight(i);
            target = &tlb[i];
            break;
        }
    }

    return target;
}

//----------------------------------------------------------------------
// TLBManager::CleanTLB
//  Clean all entries of TLB when context-switch occured
//----------------------------------------------------------------------

void
TLBManager::CleanTLB()
{
    DEBUG(dbgPage, "Clean all TLB entries");
    strategy->ResetStatus();

    for (int i = 0; i < tlbSize; ++i) {
        tlb[i].valid = FALSE;
        tlb[i].dirty = FALSE;
    }
}

//----------------------------------------------------------------------
// TLBManager::FindEntryToCache
//  Return index of a space of TLB entries to cache anothor new entry.
//----------------------------------------------------------------------

int
TLBManager::FindEntryToCache()
{
    int availEntryId = -1;
    for (int i = 0; i < tlbSize; ++i) {
        if (tlb[i].valid == FALSE) {
            availEntryId = i;
            break;
        }
    }

    if (availEntryId == -1) {   // TLB is full
        availEntryId = strategy->FindOneToReplace();
    }

    DEBUG(dbgPage, "Available TLB entry: " << availEntryId);
    return availEntryId;
}
