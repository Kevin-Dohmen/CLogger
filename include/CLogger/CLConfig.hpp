#pragma once

#include <string>

namespace CLogger {

struct CLConfig {
    int Verbosity = 0;
    bool ShowTime = false;
    bool ShowSeverity = false;

    CLConfig::CLConfig() 
      : Verbosity(CLogger::defaultConfig.Verbosity),
        ShowTime(CLogger::defaultConfig.ShowTime),
        ShowSeverity(CLogger::defaultConfig.ShowSeverity) {}

    CLConfig::CLConfig(const CLConfig& config) 
      : Verbosity(config.Verbosity),
        ShowTime(config.ShowTime),
        ShowSeverity(config.ShowSeverity) {}

    CLConfig::CLConfig(int verbosity, bool showTime, bool showLogLevel) 
      : Verbosity(verbosity),
        ShowTime(showTime),
        ShowSeverity(showLogLevel) {}
};

} // namespace CLogger