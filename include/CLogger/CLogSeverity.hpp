#pragma once

#include <string>
#include <array>

namespace CLogger {

enum class CLogSeverity {
    LOG,
    INFO,
    DEBUG,
    WARNING,
    ERROR,
    FATAL,
    COUNT
};

namespace SeverityUtils {
    constexpr std::array<std::string_view, static_cast<size_t>(CLogSeverity::COUNT)> SeverityToString{
        "[LOG]",
        "[INFO]",
        "[DEBUG]",
        "[WARNING]",
        "[ERROR]",
        "[FATAL]"
    };
        
    constexpr std::string_view ToString(CLogSeverity sev) {
        return SeverityToString[static_cast<size_t>(sev)];
    }

    static_assert(SeverityToString.size() == static_cast<size_t>(CLogSeverity::COUNT),
        "SeverityToString array size must match the number of CLogSeverity enum values.");
}

} // namespace CLogger
