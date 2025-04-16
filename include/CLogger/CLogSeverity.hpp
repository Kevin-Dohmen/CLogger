#pragma once

#include <array>
#include <string>

namespace CLogger {

enum class CLogSeverity {
    LOG,
    INFO,
    DEBUG,
    WARNING,
    ERROR,
    FATAL,
    COUNT // To represent the number of severity levels
};

constexpr std::array<const char*, static_cast<size_t>(CLogSeverity::COUNT)> _SeverityLookup{
    "[LOG]",
    "[INFO]",
    "[DEBUG]",
    "[WARNING]",
    "[ERROR]",
    "[FATAL]"
};

constexpr const char* CLogSeverityToString(CLogSeverity sev) {
    return _SeverityLookup[static_cast<size_t>(sev)];
}

} // namespace CLogger
