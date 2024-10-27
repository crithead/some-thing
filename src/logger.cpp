/// Logger
/// @todo Make this thread safe by spawning a writer thread and putting
/// messages on a queuea for the thread to write

#include <cstdarg>
#include <cstdio>
#include <vector>

#include "exceptions.hpp"
#include "logger.hpp"

namespace zebra {

Logger::Level Logger::StringToLevel(const std::string& str)
{
    struct LevelName { const char *name; Logger::Level value; };
    static const std::vector<LevelName> LEVEL_NAME_TABLE = {
        { "ERROR", Logger::Level::ERROR, },
        { "WARNING", Logger::Level::WARNING, },
        { "NOTICE", Logger::Level::NOTICE, },
        { "INFO", Logger::Level::INFO, },
        { "DEBUG", Logger::Level::DEBUG, },
        { nullptr, Logger::Level::ERROR }
    };

    for (auto& i : LEVEL_NAME_TABLE) {
        if (str == i.name) {
            return i.value;
        }
    }

    throw ConversionError();
}

Logger::Logger() noexcept : level(Level::NOTICE), trace(false),
        fileName("thing.log")
{}

Logger::Logger(Level lvl) noexcept : level(lvl), trace(false),
        fileName("thing.log")
{}

Logger::Logger(Level lvl, bool trc) noexcept : level(lvl), trace(trc),
        fileName("thing.log")
{}

Logger::~Logger() noexcept {}

void Logger::Close() noexcept
{
    this->trace = false;
    this->level = Level::DEBUG;
}

void Logger::Error(const char *fmt, ...) noexcept
{
    if (this->level >= Level::ERROR) {
        va_list v;
        va_start(v, fmt);
        vfprintf(stderr, fmt, v);
        va_end(v);
        fputc('\n', stderr);
    }
}

void Logger::Warning(const char *fmt, ...) noexcept
{
    if (this->level >= Level::WARNING) {
        va_list v;
        va_start(v, fmt);
        vfprintf(stderr, fmt, v);
        va_end(v);
        fputc('\n', stderr);
    }
}

void Logger::Notice(const char *fmt, ...) noexcept
{
    if (this->level >= Level::NOTICE) {
        va_list v;
        va_start(v, fmt);
        vfprintf(stderr, fmt, v);
        va_end(v);
        fputc('\n', stderr);
    }
}

void Logger::Info(const char *fmt, ...) noexcept
{
    if (this->level >= Level::INFO) {
        va_list v;
        va_start(v, fmt);
        vfprintf(stderr, fmt, v);
        va_end(v);
        fputc('\n', stderr);
    }
}

void Logger::Debug(const char *fmt, ...) noexcept
{
    if (this->level >= Level::DEBUG) {
        va_list v;
        va_start(v, fmt);
        vfprintf(stderr, fmt, v);
        va_end(v);
        fputc('\n', stderr);
    }
}

void Logger::Trace(const char *fmt, ...) noexcept
{
    if (this->trace) {
        va_list v;
        va_start(v, fmt);
        vfprintf(stderr, fmt, v);
        va_end(v);
        fputc('\n', stderr);
    }
}

Logger::Level Logger::GetLevel() noexcept
{
    return this->level;
}

bool Logger::GetTrace() noexcept
{
    return this->trace;
}

const std::string& Logger::GetFile() noexcept
{
    return const_cast<const std::string&>(this->fileName);
}

void Logger::SetLevel(Logger::Level lvl) noexcept
{
    if (lvl >= Logger::Level::ERROR && lvl <= Logger::Level::DEBUG)
    {
        this->level = lvl;
    }
    else if (lvl < Logger::Level::ERROR)
    {
        this->level = Logger::Level::ERROR;
    }
    else if (lvl > Logger::Level::DEBUG)
    {
        this->level = Logger::Level::DEBUG;
    }
}

void Logger::SetTrace(bool enable) noexcept
{
    this->trace = enable;
}

void Logger::SetFile(const std::string& newFileName) noexcept
{
    this->fileName = newFileName;
}

} // end namespace zebra
