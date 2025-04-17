#pragma once

#include <ostream>
#include <iostream>

#include "CLogger/CLogSeverity.hpp"

namespace CLogger {

class CLogConfig {
private:
    static CLogConfig* defaultConfig;
public:
    CLogSeverity Verbosity = CLogSeverity::LOG;
    bool ShowSeverity;

    std::ostream* Output = &std::cout;
    std::ostream* OutputError = &std::cerr;

    CLogConfig() = default;
    CLogConfig(CLogSeverity verbosity, bool showSeverity, std::ostream* out, std::ostream* outErr) 
        : Verbosity(verbosity), ShowSeverity(showSeverity), Output(out), OutputError(outErr) {}

    static void SetDefault(CLogConfig* config);
    static CLogConfig& GetDefault();
};

} // namespace CLogger
