#include "CLogger/CLogger.hpp"

namespace CLogger{

void CLoggerInstance::LogMessage(const std::string& msg, const CLogger::CLogConfig& conf);

CLoggerInstance(CLogConfig conf = CLogConfig());

void Log(const std::string& msg);
void Log(const std::string& msg, CLogSeverity sev);

// static interface
static void Log(const std::string& msg);
static void Log(const std::string& msg, CLogSeverity sev);

static void SetDefault(CLoggerInstance* logger);
static CLoggerInstance& GetDefault();

}