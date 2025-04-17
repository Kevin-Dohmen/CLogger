#include "CLogger/ClogConfig.hpp"

namespace CLogger {

CLogConfig::CLogConfig() : Verbosity(0), ShowSeverity(false) {};

void CLogConfig::SetDefault(CLogConfig* config) {
    defaultConfig = config;
}
CLogConfig& CLogConfig::GetDefault(){
    return *defaultConfig;
}

} // namespace CLogger