#pragma once
#define CLogger_H

#include <string>

#include "CLogger/CLogConfig.hpp"
#include "CLogger/CLogSeverity.hpp"

namespace CLogger {

class CLoggerInstance {
private:
    CLogConfig config;
    static CLoggerInstance* defaultLogger;

    static void LogMessage(const std::string& msg, const CLogConfig& conf);
public:
    CLoggerInstance(CLogConfig conf = CLogConfig());

    void Log(const std::string& msg);
    void Log(const std::string& msg, CLogSeverity sev);

    // static interface
    static void Log(const std::string& msg);
    static void Log(const std::string& msg, CLogSeverity sev);

    static void SetDefault(CLoggerInstance* logger);
    static CLoggerInstance& GetDefault();
};

} // namespace CLogger
