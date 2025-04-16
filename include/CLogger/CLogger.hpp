#pragma once

#include "CLogger/CLoggerInstance.hpp"
#include "CLogger/CLogSeverity.hpp"

#include <string>
#include <iostream>

namespace CLogger {

    // -=-=-=-=-=- Types -=-=-=-=-=-

    struct CLConfig;
    class CLoggerInstance;
    enum CLogSeverity;

    // -=-=-=-=-=- Functies -=-=-=-=-=-

    CLConfig defaultConfig(0, false, false);
    CLoggerInstance defaultLogger = CLoggerInstance::getDefaultLogger();

    static inline void log(std::string& msg){
        defaultLogger.log(msg);
    }
}
