//
//  tsSingletonManager.h
//  tsStudy
//
//  Created by signorinotang on 14-1-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef __tsStudy__tsSingletonManager__
#define __tsStudy__tsSingletonManager__

#include "tsNonCopyable.h"
#include <list>

class SingletonManager : public NonCopyable {
public:
    ~SingletonManager();
    static SingletonManager& instance();
    
    void destroy_all();
    
    void _create(void *&ptr, void *(*creator)(), void(*destroyer)());
    void _destroyed(void (*destoyer)());
    
private:
    SingletonManager();
    SingletonManager(const SingletonManager&);
    
    std::list<void(*)()> m_destroyers;
};





#endif /* defined(__tsStudy__tsSingletonManager__) */
