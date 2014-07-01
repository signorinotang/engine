//
//  tsMemory.cpp
//  tsStudy
//
//  Created by signorinotang on 13-12-29.
//  Copyright (c) 2013 signorinotang. All rights reserved.
//

#include "tsMemory.h"
#include "tsMemoryTracker.h"

#ifndef TS_MEMORY_ALLOCATOR
# define TS_MEMORY_ALLOCATOR StdMemoryAllocator
#endif


class MemoryTracker;

class StdMemoryAllocator {
public:
    static void* allocate(size_t size) {
        return ::malloc(size);
    }
    static void  free(void* ptr) {
        ::free(ptr);
    }
};




void* Memory::allocate(size_t size) {
    void *ptr = TS_MEMORY_ALLOCATOR::allocate(size);
#ifdef TS_MEMORY_TRACKER
    MemoryTracker::instance().recordAllocation(ptr, size);
#endif
    return ptr;
}

void* Memory::allocate(size_t size, const char* file, int line, const char* func) {
    
    void *ptr = TS_MEMORY_ALLOCATOR::allocate(size);
#ifdef TS_MEMORY_TRACKER
    MemoryTracker::instance().recordAllocation(ptr, size, file, line, func);
#endif
    return ptr;
}


void  Memory::deallocate(void* ptr) {
    
#ifdef TS_MEMORY_TRACKER
    MemoryTracker::instance().recordDeallocation(ptr);
#endif
    TS_MEMORY_ALLOCATOR::free(ptr);
}



