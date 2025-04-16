#include "CLogger/CLogger.hpp"
#include "CLogger/CLConfig.hpp"

namespace CLogger {

void CLoggerInstance::log(std::string& msg){
    std::cout << msg << std::endl;
}

} // namespace CLogger
