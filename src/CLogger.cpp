#include "CLogger/CLogger.hpp"

namespace CLogger {

std::ostream* CLoggerInstance::getOutputStream(CLogSeverity sev) const {
    return (sev >= CLogSeverity::WARNING) ? config.OutputError : config.Output;
}

void CLoggerInstance::writeLogMessage(const std::string& msg, CLogSeverity sev) const {
    if (sev < config.Verbosity) {
        return;
    }

    std::ostream* out = getOutputStream(sev);

    if (config.ShowSeverity) {
        (*out) << SeverityUtils::ToString(sev) << " ";
    }

    (*out) << ": " << msg << '\n';
}


void CLoggerInstance::log(const std::string& msg) {
    log(msg, CLogSeverity::LOG);
}
void CLoggerInstance::log(const std::string& msg, CLogSeverity sev) {
    writeLogMessage(msg, sev);
}

// static interface
void CLoggerInstance::Log(const std::string& msg) {
    if (!defaultLogger) {
        throw std::runtime_error("Default logger is not set.");
    }
    defaultLogger->log(msg);
}
void CLoggerInstance::Log(const std::string& msg, CLogSeverity sev) {
    if (!defaultLogger) {
        throw std::runtime_error("Default logger is not set.");
    }
    defaultLogger->log(msg, sev);
}

void CLoggerInstance::SetDefault(CLoggerInstance* logger) {
    defaultLogger = logger;
}
CLoggerInstance& CLoggerInstance::GetDefault() {
    if (!defaultLogger) {
        throw std::runtime_error("Default logger is not set.");
    }
    return *defaultLogger;
}

} // namespace CLogger