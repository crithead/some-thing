/// Helpers - Utility functions
#ifndef ZEBRA_LOGGER_HPP
#define ZEBRA_LOGGER_HPP

#include <string>

namespace zebra {

class Logger
{
public:

    enum Level {
        ERROR,
        WARNING,
        NOTICE,
        INFO,
        DEBUG,
    };

    static Level StringToLevel(const std::string& str);

    Logger() noexcept;
    Logger(Level) noexcept;
    Logger(Level, bool) noexcept;
    Logger(const Logger&) = delete;
    ~Logger() noexcept;

    void Close() noexcept;

    void Error(const char *fmt, ...) noexcept;
    void Warning(const char *fmt, ...) noexcept;
    void Notice(const char *fmt, ...) noexcept;
    void Info(const char *fmt, ...) noexcept;
    void Debug(const char *fmt, ...) noexcept;
    void Trace(const char *fmt, ...) noexcept;

    Level GetLevel() noexcept;
    bool GetTrace() noexcept;
    const std::string& GetFile() noexcept;
    void SetLevel(Level lvl) noexcept;
    void SetTrace(bool enable) noexcept;
    void SetFile(const std::string& fileName) noexcept;

private:
    Level level;
    bool trace;
    std::string fileName;
};

} // end namespace zebra

#endif // ZEBRA_LOGGER_HPP
