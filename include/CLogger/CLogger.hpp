#pragma once
#define CLogger_H

#include <string>
#include <ostream>

#include "CLogger/CLogConfig.hpp"
#include "CLogger/CLogSeverity.hpp"

namespace CLogger {

class CLoggerInstance {
private:
    CLogConfig config;
    static CLoggerInstance* defaultLogger;

    std::ostream* getOutputStream(CLogSeverity sev) const;
    void writeLogMessage(const std::string& msg, CLogSeverity sev) const;
public:
    CLoggerInstance(CLogConfig conf = CLogConfig())
        : config(std::move(config)) {}

    void log(const std::string& msg);
    void log(const std::string& msg, CLogSeverity sev);

    // static interface
    static void Log(const std::string& msg);
    static void Log(const std::string& msg, CLogSeverity sev);

    static void SetDefault(CLoggerInstance* logger);
    static CLoggerInstance& GetDefault();
};

} // namespace CLogger
