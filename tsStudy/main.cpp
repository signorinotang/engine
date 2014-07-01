//
//  main.cpp
//  tsStudy
//
//  Created by signorinotang on 13-12-22.
//  Copyright (c) 2013 signorinotang. All rights reserved.
//

#include <iostream>
#include "tsLog.h"

using namespace ts;

int main(int argc, const char * argv[])
{
    Log::instance().addPrinter(tsnew LogPrinterSTDOUT(), false);
  
    return 0;
}

