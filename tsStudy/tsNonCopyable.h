//
//  NonCopyable.h
//  tsStudy
//
//  Created by signorinotang on 14-1-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef tsStudy_NonCopyable_h
#define tsStudy_NonCopyable_h

class NonCopyable {
public:
    NonCopyable();
private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator = (const NonCopyable&);
};




#endif
