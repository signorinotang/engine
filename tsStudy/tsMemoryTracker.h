//
//  MemoryTracker.h
//  tsStudy
//
//  Created by signorinotang on 13-12-29.
//  Copyright (c) 2013 signorinotang. All rights reserved.
//

#ifndef __tsStudy__MemoryTracker__
#define __tsStudy__MemoryTracker__

#include <map>



class MemoryTracker {
public:
    static MemoryTracker& instance();
    ~MemoryTracker();
    
    void recordAllocation(void* p, size_t size, const char* file = 0, unsigned int line = 0, const char* func = 0);
    void recordDeallocation(void* p);
    
    size_t totalMemoryAllocated();
    void reportLeaks();
private:
    struct Allocation {
        size_t size;
        const char* file;
        unsigned int line;
        const char* func;
        
        Allocation(): size(0), file(0), line(0), func(0) {}
        Allocation(size_t s, const char* f, unsigned int l, const char* fn)
        :size(s), file(f), line(l), func(fn) {}
    };
    
    typedef std::map<void*, Allocation> AllocationMap;
    //typedef fastMutex lock
    MemoryTracker();
    MemoryTracker(const MemoryTracker&);
    
    size_t m_totalAllocations;
    AllocationMap m_allocations;
};



#endif /* defined(__tsStudy__MemoryTracker__) */
