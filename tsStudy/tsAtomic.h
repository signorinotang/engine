//
//  tsAtomic.h
//  tsStudy
//
//  Created by signorinotang on 14-1-6.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef __tsStudy__tsAtomic__
#define __tsStudy__tsAtomic__

#include "tsTypes.h"


class Atomic {
public:
    typedef volatile s32 Int32;
    typedef volatile s64 Int64;
    static Int32 increase(Int32& v);
    static Int64 increase(Int64& v);
    static Int32 decrease(Int32& v);
    static Int64 decrease(Int64& v);
    static bool compareAndSwap(Int32& v, Int32 swap, Int32 comparand);
    static bool compareAndSwap(Int64& v, Int64 swap, Int64 comparand);
    
};



#endif /* defined(__tsStudy__tsAtomic__) */
