#pragma once

#include "CLogger/CLogger.hpp"
#include "CLogger/CLConfig.hpp"

namespace CLogger {

class CLoggerInstance {
private:
    std::string _Name;
    CLConfig _Config;

    static CLoggerInstance _DefaultLogger;

    void logMessage(const std::string& msg, const CLogSeverity sev){

        if (_Config.ShowSeverity = true) {
            std::cout << CLogSeverityToString(sev);
        }

        std::cout << msg << std::endl;
    }

public:

    CLoggerInstance()
      : _Name(""),
        _Config(CLogger::defaultConfig) {}
    CLoggerInstance(const CLConfig& config)
      : _Name(""),
        _Config(config) {}
    CLoggerInstance(const std::string& name)
      : _Name(name),
        _Config(CLogger::defaultConfig) {}
    CLoggerInstance(const std::string& name, const CLConfig& config)
      : _Name(name),
        _Config(config) {}
    
    static inline CLoggerInstance& getDefaultLogger() {
        return _DefaultLogger;
    }

    static void setDefaultLogger(CLoggerInstance& clogger) {
        _DefaultLogger = clogger;
    }
    
    void log(std::string& msg);
    void warning(std::string& msg);
};

} // namespace CLogger
