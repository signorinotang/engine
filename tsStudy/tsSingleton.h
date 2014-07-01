//
//  tsSingleton.h
//  tsStudy
//
//  Created by signorinotang on 14-1-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef tsStudy_tsSingleton_h
#define tsStudy_tsSingleton_h

#include "tsSingletonManager.h"
#include "tsMemory.h"

template <class T>
class Singleton : public NonCopyable {
public:
    static T& instance() {
        if(!ms_instance) {
            SingletonManager::instance()._create(ms_instance, _create_instance, destory_instance);
        }
        return *(T*)ms_instance;
    }
    static void destory_instance() {
        if(ms_instance){
            ((T*)ms_instance)->~T();
            tsfree(ms_instance);
            ms_instance = 0;
            SingletonManager::instance()._destroyed(destory_instance);
        }
    }
    
private:
    //maybe not all singleton has memorytracker(inherit allocatedObject)
    //so use tsmalloc to has the memorytracker
    static void* _create_instance() {
        void* ptr = tsmalloc(T, 1); //allocated memory and has memorytracker
        new(ptr) T();      //call type T`s constructor initialize the ptr`s memory
        return ptr;
    }
    static void* ms_instance;
};

template <class T>
void* Singleton<T>::ms_instance = 0;


#endif
