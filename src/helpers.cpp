/// Helper functions

#include <getopt.h>

#include <iostream>

#include "dictionary.hpp"
#include "logger.hpp"

namespace zebra {

void GetOptions(int argc, const char * const *argv, Dictionary& opts)
{
    static struct option LONG_OPTIONS[] = {
        { "help", no_argument, NULL, 'h' },
        { "log-level", required_argument, NULL, 'l' },
        { "log-file", required_argument, NULL, 'L' },
        { "trace", no_argument, NULL, 'T' },
        { "verbose", no_argument, NULL, 'v' },
        { nullptr, 0, 0, 0 }
    };
    static const char OPTIONS[] = "hl:L:Tv";

    // Set some default option values
    opts.Insert("help", "false");
    opts.Insert("trace", "false");
    opts.Insert("verbose", "false");
    opts.Insert("log-level", "NOTICE");

    // Disable getopt error output
    ::opterr = 0;

    int opt_index = 0;
    while (true) {
        int opt = getopt_long(argc, const_cast<char * const *> (argv),
                              OPTIONS, LONG_OPTIONS, &opt_index);
        std::cout << "opt = " << opt << ", " << static_cast<char>(opt) << std::endl;
        if (opt == -1) {
            break;
        }
        switch (opt) {
            case 'h':
                opts.Insert("help", "true");
                break;
            case 'T':
                opts.Insert("trace", "true");
                break;
            case 'v':
                opts.Insert("verbose", "true");
                break;
            case 'l':
                try {
                    // Do conversion to verify the string.
                    const std::string logLevel {optarg};
                    Logger::StringToLevel(logLevel);
                    opts.Insert("log-level", logLevel);
                }
                catch (const ConversionError&) {
                    // Ignore bad log level
                }
                break;
            case 'L': {
                const std::string logFile {optarg};
                opts.Insert("log-file", logFile);
                break;
            }
            case ':':
                std::cout << "missing argument: " << optopt << std::endl;
                break;
            case '?':
                std::cout << "case ?: " << optopt << std::endl;
                break;
            default:
                std::cout << "case default: " << optopt << std::endl;
                break;
        }
    }
}

void PrintUsage(void)
{
    std::cout << "Some Thing - an AWS IoT thing simulator" << std::endl;
    std::cout << std::endl;
    std::cout << "OPTIONS" << std::endl;
    std::cout << "  -h, --help      Print a usage message and exit" << std::endl;

    std::cout << "  -l <level>,     Set the log level (ERROR, WARNING, NOTICE,"
            " INFO, DEBUG)" << std::endl;
    std::cout << "  --log-level <level>" << std::endl;
    std::cout << "  -L <file>,      Write the log to this file" << std::endl;
    std::cout << "  --log-file <file>" << std::endl;

    std::cout << "  -T, --trace     Enable trace logging" << std::endl;
    std::cout << "  -v, --verbose   Enable verbose logging" << std::endl;
}

void ReadParametersFile(Dictionary& dict)
{

}

void InitLogger(Logger& logger, const Dictionary& parameters)
{

}

} // end namespace zebra
