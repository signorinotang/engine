//
//  MemoryTracker.cpp
//  tsStudy
//
//  Created by signorinotang on 13-12-29.
//  Copyright (c) 2013 signorinotang. All rights reserved.
//

#include <assert.h>
#include <sstream>
#include <iostream>
#include "tsMemoryTracker.h"

MemoryTracker& MemoryTracker::instance() {
    static MemoryTracker inc;
    return inc;
}

MemoryTracker::MemoryTracker()
:m_totalAllocations(0) {
    
}

MemoryTracker::~MemoryTracker() {
    reportLeaks();
}



void MemoryTracker::recordAllocation(void* p, size_t size, const char* file, unsigned int line, const char* func) {
    //lock
    m_allocations[p] = Allocation(size, file, line, func);
    m_totalAllocations += size;
    //unlock
}

void MemoryTracker::recordDeallocation(void *p) {
    //lock
    AllocationMap::iterator it = m_allocations.find(p);
    assert(it != m_allocations.end());
    m_totalAllocations -= it->second.size;
    m_allocations.erase(it);
    //unlock
}

void MemoryTracker::reportLeaks() {
    std::ostringstream oss;
    if(m_allocations.empty()) {
        oss << "Memory: No Memory Leaks" << std::endl;
    }else {
        oss << "Memory: Detected Memory Leaks" << "Total " << m_totalAllocations << " Bytes" << std::endl;
        oss << "Memory: Dumping allocations -> "<< std::endl;
        
        for (AllocationMap::iterator it = m_allocations.begin(); it != m_allocations.end(); ++it) {
            Allocation &alloc = it->second;
            if(alloc.file) {
                oss << alloc.file << " ";
            } else {
                oss << "(unknow source)";
            }
            
            if(alloc.line) {
                oss << alloc.line << " ";
            } else {
                oss << "(unknow line)";
            }
            
            if(alloc.func) {
                oss << alloc.func << " ";
            } else {
                oss << "(unknow function)";
            }
            oss << std::endl;
        }
    }
    
    std::cout << oss.str() << std::endl;
}



