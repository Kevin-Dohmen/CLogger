#include "CLogger/ClogConfig.hpp"

namespace CLogger {

void CLogConfig::SetDefault(CLogConfig* config) {
    defaultConfig = config;
}
CLogConfig& CLogConfig::GetDefault(){
    return *defaultConfig;
}

} // namespace CLogger