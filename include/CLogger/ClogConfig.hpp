#pragma once

#include <string>

namespace CLogger {

class CLogConfig {
private:
    static CLogConfig* defaultConfig;
public:
    int Verbosity;
    bool ShowSeverity;

    CLogConfig();

    static void SetDefault(CLogConfig* config);
    static CLogConfig& GetDefault();
};

} // namespace CLogger
