#pragma once

#include "core.h"

#include <chrono>
#include <sstream>
#include <string>

// Disable logging only if LUNAR_FASTLOAD && LUNAR_RELEASE
#if defined LUNAR_DEV || defined LUNAR_DEBUG
#define LUNAR_LOGGING_ENABLED
#endif

#ifdef LUNAR_LOGGING_ENABLED
#define LUNAR_LOG_TRACE(...)         lunar::Logger::Log(lunar::LogSeverity::Trace, __VA_ARGS__)
#define LUNAR_LOG_INFO(...)          lunar::Logger::Log(lunar::LogSeverity::Info, __VA_ARGS__)
#define LUNAR_LOG_PROFILE(...)       lunar::Logger::Log(lunar::LogSeverity::Profile, __VA_ARGS__)
#define LUNAR_LOG_WARN(...)          lunar::Logger::Log(lunar::LogSeverity::Warning, __VA_ARGS__)
#define LUNAR_LOG_ERROR(...)         lunar::Logger::Log(lunar::LogSeverity::Error, __VA_ARGS__)
#define LUNAR_LOG_FATAL(...)         lunar::Logger::Log(lunar::LogSeverity::Fatal, __VA_ARGS__)
#else
#define LUNAR_LOG_TRACE(...)
#define LUNAR_LOG_INFO(...)
#define LUNAR_LOG_PROFILE(...)
#define LUNAR_LOG_WARN(...)
#define LUNAR_LOG_ERROR(...)
#define LUNAR_LOG_FATAL(...)
#endif

namespace lunar
{
    enum class LogSeverity
    {
        Trace,
        Info,
        Profile,
        Warning,
        Error,
        Fatal
    };

    class Logger
    {
    public:
        template <typename T>
        static inline decltype(auto) FormatArg(T const& t) { return t; }

        static inline const char* FormatArg(std::string const& t) { return t.c_str(); }

        template <typename ... Args>
        static inline void Log(LogSeverity severity, const char* format, Args const& ... args)
        {
            char timeBuffer[11];
            std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            struct tm currentTimeInfo;
            localtime_s(&currentTimeInfo, &currentTime);
            std::strftime(timeBuffer, 11, "[%H:%M:%S]", &currentTimeInfo);

            std::stringstream log;
            log << timeBuffer << "[Lunar]" << GetSeverityTag(severity) << " " << format;

            const size_t bufferSize = snprintf(nullptr, 0, "%s", FormatArg(log.str().c_str()), FormatArg(args) ...) + 1;
            char* buffer = new char[bufferSize];
            snprintf(buffer, bufferSize, "%s", FormatArg(log.str().c_str()), FormatArg(args) ...);
            printf("%s%s%s\n", GetSeverityColor(severity), buffer, "\033[0;97m");
            delete[](buffer);
        }

        static inline const char* GetSeverityTag(LogSeverity severity)
        {
            switch (severity)
            {
            case LogSeverity::Trace:    return "[Trace]";
            case LogSeverity::Info:     return "[Info]";
            case LogSeverity::Profile:  return "[Profile]";
            case LogSeverity::Warning:  return "[Warning]";
            case LogSeverity::Error:    return "[Error]";
            case LogSeverity::Fatal:    return "[Fatal]";
            default:                    return "[Trace]";
            }
        }

        static inline const char* GetSeverityColor(LogSeverity severity)
        {
            switch (severity)
            {
            case LogSeverity::Trace:    return "\033[0;97m";
            case LogSeverity::Info:     return "\033[0;92m";
            case LogSeverity::Profile:  return "\033[0;96m";
            case LogSeverity::Warning:  return "\033[0;93m";
            case LogSeverity::Error:    return "\033[0;91m";
            case LogSeverity::Fatal:    return "\033[0;101m";
            default:                    return "\033[0;97m";
            }
        }
    };
}