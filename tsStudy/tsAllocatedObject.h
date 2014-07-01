//
//  tsAllocatedObject.h
//  tsStudy
//
//  Created by signorinotang on 14-1-5.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef __tsStudy__tsAllocatedObject__
#define __tsStudy__tsAllocatedObject__

#include <iostream>
#include "tsMemory.h"

class AllocatedObject {
public:
    void* operator new(size_t size);
    void* operator new(size_t size, const char* file, int line, const char* func);
    void* operator new(size_t size, void* p);
    void* operator new[](size_t size);
    void* operator new[](size_t size, const char* file, int line, const char* func);
    void  operator delete(void* p);
    void  operator delete(void* p, const char*, int, const char*);
    void  operator delete(void*, void*);
    void  operator delete[](void* p);
    void  operator delete[](void* p, const char*, int, const char*);
};







#endif /* defined(__tsStudy__tsAllocatedObject__) */
