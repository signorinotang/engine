//
//  tsSingletonManager.cpp
//  tsStudy
//
//  Created by signorinotang on 14-1-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "tsSingletonManager.h"
#include "tsMemoryTracker.h"

SingletonManager::SingletonManager() {
#ifdef TS_MEMORY_TRACKER
    MemoryTracker::instance();
#endif
}

SingletonManager::~SingletonManager() {
    destroy_all();
}

void SingletonManager::destroy_all() {
    while (!m_destroyers.empty()) {
        m_destroyers.back()();
    }
}

SingletonManager& SingletonManager::instance(){
    static SingletonManager s_ins;
    return s_ins;
}

void SingletonManager::_create(void *&ptr, void *(*creator)(), void (*destroyer)()) {
    //scopedLock
    if(!ptr) {
        ptr = creator();
        m_destroyers.push_back(destroyer);
    }
}

void SingletonManager::_destroyed(void (*destoyer)()){
    //scopedLock
    for (std::list<void (*)()>::iterator it = m_destroyers.begin(); it != m_destroyers.end(); ++it) {
        if (*it == destoyer) {
            m_destroyers.erase(it);
            break;
        }
    }
}


