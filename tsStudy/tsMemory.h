//
//  tsMemory.h
//  tsStudy
//
//  Created by signorinotang on 13-12-29.
//  Copyright (c) 2013 signorinotang. All rights reserved.
//

#ifndef __tsStudy__tsMemory__
#define __tsStudy__tsMemory__

#include <iostream>

class Memory {
public:
    static void* allocate(size_t size); //size_t  unsigned long
    static void* allocate(size_t size, const char* file, int line, const char* func);
    static void  deallocate(void* ptr);
};


#ifdef TS_MEMORY_TRACKER
#   define tsnew new(__FILE__,__LINE__,__FUNCTION__)
#   define tsmalloc(type, count) (type*)Memory::allocate(sizeof(type)*(count), __FILE__, __LINE__, __FUNCTION__)
#   define tsfree(p) Memory::deallocate(p)
#endif





#endif /* defined(__tsStudy__tsMemory__) */
