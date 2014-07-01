//
//  tsAtomic.cpp
//  tsStudy
//
//  Created by signorinotang on 14-1-6.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "tsAtomic.h"
#include <libkern/OSAtomic.h>

Atomic::Int32 Atomic::increase(Int32 &v) {
	return OSAtomicIncrement32Barrier(&v);
}

Atomic::Int64 Atomic::increase(Int64 &v) {
	return OSAtomicIncrement64Barrier(&v);
}

Atomic::Int32 Atomic::decrease(Int32 &v) {
	return OSAtomicDecrement32Barrier(&v);
}

Atomic::Int64 Atomic::decrease(Int64 &v) {
	return OSAtomicDecrement64Barrier(&v);
}

bool Atomic::compareAndSwap(Int32 &v, s32 swap, s32 comparand) {
	return OSAtomicCompareAndSwap32Barrier(comparand, swap, &v);
}

bool Atomic::compareAndSwap(Int64 &v, s64 swap, s64 comparand) {
	return OSAtomicCompareAndSwap64Barrier(comparand, swap, &v);
}