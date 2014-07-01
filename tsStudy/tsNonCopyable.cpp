//
//  tsNonCopyable.cpp
//  tsStudy
//
//  Created by signorinotang on 14-1-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "tsNonCopyable.h"

NonCopyable::NonCopyable() {
    
}


NonCopyable::NonCopyable(const NonCopyable&) {
    
}

NonCopyable& NonCopyable::operator = (const NonCopyable&) {
    return *this;
}