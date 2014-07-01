//
//  tsAllocatedObject.cpp
//  tsStudy
//
//  Created by signorinotang on 14-1-5.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "tsAllocatedObject.h"
#include "tsMemory.h"

void* AllocatedObject::operator new(size_t size) {
    return Memory::allocate(size);
}

void* AllocatedObject::operator new(size_t size, const char* file, int line, const char* func) {
    return Memory::allocate(size, file, line, func);
}

void* AllocatedObject::operator new(size_t size, void* p) {
    return p;
}

void* AllocatedObject::operator new[](size_t size) {
    return Memory::allocate(size);
}

void* AllocatedObject::operator new[](size_t size, const char* file, int line, const char* func) {
    return Memory::allocate(size, file, line, func);
}

void  AllocatedObject::operator delete(void* p) {
    Memory::deallocate(p);
}
void  AllocatedObject::operator delete(void* p, const char*, int, const char*) {
    Memory::deallocate(p);
}

void  AllocatedObject::operator delete(void*, void*) {
    
}

void  AllocatedObject::operator delete[](void* p) {
    Memory::deallocate(p);
}

void  AllocatedObject::operator delete[](void* p, const char*, int, const char*) {
    Memory::deallocate(p);
}



