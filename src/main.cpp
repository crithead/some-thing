/// Some Thing - an AWS IoT Device

#include "dictionary.hpp"
#include "exceptions.hpp"
#include "helpers.hpp"
#include "logger.hpp"

using namespace zebra;

/// Program entry point
/// # Read config from file
/// # Parse command line options
/// # Intialize logging
/// # Start threads
/// # Wait for threads to exit
/// # Clean up
int main( int argc, char *argv[])
{
    Dictionary opts;
    Logger log;

    try {
        GetOptions(argc, argv, opts);
        ReadParametersFile(opts);
        InitLogger(log, opts);
        //log.debug(parameters);

        if (opts.GetBool("help")) {
            PrintUsage();
            return 0;
        }
    }
    catch (const Error& e) {

    }

    try {
        log.Notice("%s: Start services", __func__);
        // Start service threads here!
    }
    catch (const Error& e) {

    }

    try {
        // Wait for service threads to exit
        log.Notice("%s: Waiting on services", __func__);

    }
    catch (const Error& e) {

    }
    log.Notice("%s: Done", __func__);
    log.Close();

    return 0;
}
