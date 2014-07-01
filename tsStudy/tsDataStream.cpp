//
//  tsDataStream.cpp
//  tsStudy
//
//  Created by signorinotang on 14-2-16.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "tsDataStream.h"

_ts_begin


DataStream & DataStream::operator >>(bool &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(s8 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(u8 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(s16 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(u16 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(s32 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(u32 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(s64 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(u64 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(f32 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(f64 &value) {
	if (read(&value, sizeof(value)) != sizeof(value)) {
		throw ReadException();
	}
	return *this;
}

DataStream & DataStream::operator >>(str8 &value) {
    z_u32 len;
    *this >> len;
    if(!len.value) {
        value.clear();
    } else {
        value.resize(len.value);
        if(read(&value[0], len.value) != len.value) {
            throw ReadException();
        }
    }
    return *this;
}











_ts_end
