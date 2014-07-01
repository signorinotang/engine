//
//  tsLog.cpp
//  tsStudy
//
//  Created by signorinotang on 14-1-30.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "tsLog.h"

_ts_begin

Log::Log()
: m_level(kInformation) {
#ifdef DEBUG
    m_level = kDebug;
#endif
}

Log::~Log() {
    for (Printers::iterator it = m_printers.begin(); it != m_printers.end(); ++it) {
        (*it)->drop();
    }
}

void Log::addPrinter(LogPrinter *printer, bool grab){
    assert(printer);
    if(grab) {
        printer->grab();
    }
    m_printers.push_back(printer);
}

void Log::removePrinter(LogPrinter *printer) {
    for (Printers::iterator it = m_printers.begin(); it != m_printers.end(); ++it) {
        if (*it == printer) {
            printer->drop();
            m_printers.erase(it);
            break;
        }
    }
}

void Log::removeAllPrinters() {
    for (Printers::iterator it = m_printers.begin(); it != m_printers.end(); ++it) {
        (*it)->drop();
    }
    m_printers.clear();
}

bool Log::checkLevel(Level ll) {
    return ll >= m_level;
}

void Log::setLevel(Level ll) {
    m_level = ll;
}

Log::Level Log::getLevel() const {
    return m_level;
}

void Log::_output(Log::Level ll, const str8 &content) {
    for (Printers::iterator it = m_printers.begin(); it != m_printers.end(); ++it) {
        (*it)->print(ll, content);
    }
}

/************************stream*****************/
Log::stream::stream(Level ll)
: m_log(Log::instance())
, m_level(ll) {
    
}

Log::stream::stream(Log &log, Level ll)
: m_log(log)
, m_level(ll) {
    
}

Log::stream::~stream() {
    m_log._output(m_level, m_oss.str());
}

Log::stream & Log::stream::operator <<(bool v) {
	m_oss << (v ? "true" : "false");
    return *this;
}

Log::stream & Log::stream::operator <<(s8 v) {
	m_oss << (s32)v;
    return *this;
}

Log::stream & Log::stream::operator <<(u8 v) {
	m_oss << (u32)v;
    return *this;
}

Log::stream & Log::stream::operator <<(s16 v) {
	m_oss << (s32)v;
    return *this;
}

Log::stream & Log::stream::operator <<(u16 v) {
	m_oss << (u32)v;
    return *this;
}

Log::stream & Log::stream::operator <<(s32 v) {
    m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(u32 v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(s64 v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(u64 v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(f32 v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(f64 v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(const c8 *v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(const str8 &v) {
	m_oss << v;
    return *this;
}

Log::stream & Log::stream::operator <<(const c16 *v) {
//	size_t len = std::char_traits<c16>::length(v);
//	str8 t;
//	t.reserve(len);
//	Unicode::convert(v, len, t);
//	m_oss << t;
    return *this;
}

Log::stream & Log::stream::operator <<(const str16 &v) {
//	str8 t;
//	t.reserve(v.length());
//	Unicode::convert(v.c_str(), v.length(), t);
//	m_oss << t;
    return *this;
}

Log::stream & Log::stream::operator <<(const c32 *v) {
//	size_t len = std::char_traits<c32>::length(v);
//	str8 t;
//	t.reserve(len);
//	Unicode::convert(v, len, t);
//	m_oss << t;
    return *this;
}

Log::stream & Log::stream::operator <<(const str32 &v) {
//	str8 t;
//	t.reserve(v.length());
//	Unicode::convert(v.c_str(), v.length(), t);
//	m_oss << t;
   return *this;
}


//********LogPrinter************

void LogPrinter::print(Log::Level ll, const str8 &content) {
    //m_lock.lock();
    _print(ll, content);
    //m_lock.unlock();
}

//*****LogPrinterSTDOUT*******
void LogPrinterSTDOUT::_print(Log::Level ll, const str8 & content) {
    const c8* format = 0;
    switch (ll) {
        case Log::kDebug:
            format = "DEBUG: %s\n";
            break;
        case Log::kInformation:
            format = "INFOR: %s\n";
            break;
        case Log::kWarning:
            format = "WARNING: %s\n";
            break;
        case Log::kError:
            format = "ERROR: %s\n";
            break;
        case Log::kFatalError:
            format = "FATALERROR: %s\n";
            break;
    }
    printf(format, content.c_str());
}

_ts_end 



















