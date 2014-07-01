//
//  tsLog.h
//  tsStudy
//
//  Created by signorinotang on 14-1-30.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef __tsStudy__tsLog__
#define __tsStudy__tsLog__

#include "tsSingleton.h"
#include "tsTypes.h"
#include "tsRefCounted.h"
#include <vector>
#include <sstream>


#define TS_LOG_DEBUG(x) \
{\
Log& _log = Log::instance();\
if(_log.checkLevel(Log::kDebug)) {\
    Log::stream(_log,Log::kDebug) << x;\
}\
}

#define TS_LOG_INFO(x) \
{\
Log& _log = Log::instance();\
if(_log.checkLevel(Log::kInformation)) {\
    Log::stream(_log,Log::kInformation) << x;\
}\
}

#define TS_LOG_WARNING(x) \
{\
Log& _log = Log::instance();\
if(_log.checkLevel(Log::kWarning)) {\
    Log::stream(_log,Log::kWarning) << x;\
}\
}

#define TS_LOG_ERROR(x) \
{\
Log& _log = Log::instance();\
if(_log.checkLevel(log::kError)) {\
    Log::stream(_log,Log::kError) << x;\
}\
}

#define TS_LOG_FATALERROR(x) \
{\
Log& _log = Log::instance();\
if(_log.checkLevel(Log::kFatalError)) {\
    Log::stream(_log, Log::kFatalError) << x;\
}\
}


_ts_begin

class LogPrinter;

class Log : public Singleton<Log> {
    friend class Singleton<Log>;
public:
    enum Level {
        kDebug = 0,
        kInformation,
        kWarning,
        kError,
        kFatalError
    };
    
    class stream {
        friend class Log;
    public:
        stream(Level);
        stream(Log&, Level);
        ~stream();
        
        stream& operator << (bool v);
        stream& operator << (s8 v);
        stream& operator << (u8 v);
        stream& operator << (s16 v);
        stream& operator << (u16 v);
        stream& operator << (s32 v);
        stream& operator << (u32 v);
        stream& operator << (s64 v);
        stream& operator << (u64 v);
        stream& operator << (f32 v);
        stream& operator << (f64 v);
        stream& operator << (const c8* v);
        stream& operator << (const str8& v);
        stream& operator << (const c16* v);
        stream& operator << (const str16& v);
        stream& operator << (const c32* v);
        stream& operator << (const str32& v);
    private:
        //std::ostringstream oss;
        std::basic_ostringstream<c8> m_oss;
        Level m_level;
        Log& m_log;
    };
    ~Log();
    void addPrinter(LogPrinter* printer, bool grab = true);
    void removePrinter(LogPrinter* printer);
    void removeAllPrinters();
    
    bool checkLevel(Level ll);
    
    void setLevel(Level ll);
    Level getLevel() const;
    
private:
    Log();
    void _output(Level ll, const str8 &content);
    
    friend class stream;
    
    typedef std::vector<LogPrinter *> Printers;
    Printers m_printers;
    Level m_level;
};


class LogPrinter : public RefCounted {
public:
    void print(Log::Level, const str8&);
protected:
    virtual void _print(Log::Level, const str8&) = 0;
private:
    //FastMutex m_lock;
};

class LogPrinterSTDOUT : public LogPrinter {
protected:
    virtual void _print(Log::Level, const str8&);
};

_ts_end

#endif /* defined(__tsStudy__tsLog__) */
