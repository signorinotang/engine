//
//  tsTypes.h
//  tsStudy
//
//  Created by signorinotang on 14-1-6.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef tsStudy_tsTypes_h
#define tsStudy_tsTypes_h

#include "tsBaseDef.h"
#include <string>








//mac ox
typedef signed char             s8;
typedef signed short            s16;
typedef signed int              s32;
typedef signed long long        s64;
typedef unsigned char           u8;
typedef unsigned short          u16;
typedef unsigned int            u32;
typedef unsigned long long      u64;

typedef char                    c8;
typedef short                   c16;
typedef int                     c32;

//
typedef float                   f32;
typedef double                  f64;

//string
typedef std::basic_string<c8, std::char_traits<c8>, std::allocator<c8> > str8;
typedef std::basic_string<c16, std::char_traits<c16>, std::allocator<c16> > str16;
typedef std::basic_string<c32, std::char_traits<c32>, std::allocator<c32> > str32;
typedef std::wstring strw;




#endif
