/// Unit tests for the Some Thing - an AWS IoT Device

#include <exception>

#define BOOST_TEST_MODULE Some Thing
#include <boost/test/included/unit_test.hpp>

#include "dictionary.hpp"
#include "helpers.hpp"
#include "logger.hpp"

// Helpers
BOOST_AUTO_TEST_SUITE(helpers_suite);

BOOST_AUTO_TEST_CASE(get_options_defaults)
{
    const int ARGC = 1;
    const char *const ARGV[] = {"/usr/local/bin/tester", NULL};
    zebra::Dictionary opts;

    try {
        zebra::GetOptions(ARGC, ARGV, opts);
    } catch (const std::exception& e) {
        BOOST_CHECK_MESSAGE(false, e.what());
    }

    BOOST_WARN_MESSAGE(ARGV[ARGC] == NULL, "Invalid ARGC/ARGV");
    BOOST_TEST(opts.Size() == 4);
    BOOST_TEST(opts.GetBool("help") == false);
    BOOST_TEST(opts.GetBool("verbose") == false);
    BOOST_TEST(opts.GetBool("trace") == false);
    BOOST_TEST(opts.Get("log-level") == "NOTICE");
}

BOOST_AUTO_TEST_CASE(get_options_help_one_long)
{
    const int ARGC = 2;
    const char *const ARGV[] = {"/usr/local/bin/tester", "--help", NULL};
    zebra::Dictionary opts;

    try {
        zebra::GetOptions(ARGC, ARGV, opts);
    } catch (const std::exception& e) {
        BOOST_CHECK_MESSAGE(false, e.what());
    }

    BOOST_WARN_MESSAGE(ARGV[ARGC] == NULL, "Invalid ARGC/ARGV");
    BOOST_TEST(opts.Size() == 4);
    BOOST_TEST(opts.GetBool("help") == true);
}

BOOST_AUTO_TEST_CASE(get_options_help_one_short)
{
    const int ARGC = 2;
    const char *const ARGV[] = {"/usr/local/bin/tester", "-h", NULL};
    zebra::Dictionary opts;

    try {
        zebra::GetOptions(ARGC, ARGV, opts);
    } catch (const std::exception& e) {
        BOOST_CHECK_MESSAGE(false, e.what());
    }

    BOOST_WARN_MESSAGE(ARGV[ARGC] == NULL, "Invalid ARGC/ARGV");
    BOOST_TEST(opts.Size() == 4);
    BOOST_TEST(opts.GetBool("help") == true);
}

BOOST_AUTO_TEST_CASE(get_options_help_many_long)
{
    const int ARGC = 4;
    const char *const ARGV[] = {"/usr/local/bin/tester", "--trace",
                                "--verbose", "--help", NULL};
    zebra::Dictionary opts;

    try {
        zebra::GetOptions(ARGC, ARGV, opts);
    } catch (const std::exception& e) {
        BOOST_CHECK_MESSAGE(false, e.what());
    }

    BOOST_WARN_MESSAGE(ARGV[ARGC] == NULL, "Invalid ARGC/ARGV");
    BOOST_TEST(opts.Size() == 4);
    BOOST_TEST(opts.GetBool("help"));
    BOOST_TEST(opts.GetBool("trace"));
    BOOST_TEST(opts.GetBool("verbose"));
}

BOOST_AUTO_TEST_CASE(get_options_help_combo_short)
{
    const int ARGC = 2;
    const char *const ARGV[] = {"/usr/local/bin/tester", "-hTv", NULL};
    zebra::Dictionary opts;

    try {
        zebra::GetOptions(ARGC, ARGV, opts);
    } catch (const std::exception& e) {
        BOOST_CHECK_MESSAGE(false, e.what());
    }

    BOOST_WARN_MESSAGE(ARGV[ARGC] == NULL, "Invalid ARGC/ARGV");
    BOOST_TEST(opts.Size() == 4);
    BOOST_TEST(opts.GetBool("help"));
    BOOST_TEST(opts.GetBool("trace"));
    BOOST_TEST(opts.GetBool("verbose"));
}

BOOST_AUTO_TEST_CASE(read_parameters_file_1)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(init_logger_1)
{
    zebra::Dictionary params;
    params.Insert("log-level", "info");
    params.Insert("log-trace", "true");
    params.Insert("log-file", "some-thing.log");
    zebra::Logger log;
    InitLogger(log, params);
    BOOST_TEST(log.GetLevel() == zebra::Logger::Level::INFO);
    BOOST_TEST(log.GetTrace() == true);
    BOOST_TEST(log.GetFile() == String {"some-thing.log"});
}

BOOST_AUTO_TEST_SUITE_END();    // End Helpers suite

// Dictionary
BOOST_AUTO_TEST_SUITE(dictionary_suite);

BOOST_AUTO_TEST_CASE(dictionary_insert_1)
{
    zebra::Dictionary dict;
    dict.Insert("one", "1");
    BOOST_TEST(dict.Size() == 1);
    dict.Insert("two", "2");
    BOOST_TEST(dict.Size() == 2);
    dict.Insert("three", "3");
    BOOST_TEST(dict.Size() == 3);
    dict.Insert("two", "22");
    BOOST_TEST(dict.Size() == 3);
}

BOOST_AUTO_TEST_CASE(dictionary_get_1)
{
    zebra::Dictionary dict;
    dict.Insert("one", "1");
    BOOST_TEST(dict.Get("one") == "1");
}

BOOST_AUTO_TEST_CASE(dictionary_get_2)
{
    zebra::Dictionary dict;
    dict.Insert("one", "1");
    dict.Insert("two", "2");
    BOOST_TEST(dict.Get("two") == "2");
}

BOOST_AUTO_TEST_SUITE_END();    // End Dictionary suite

// Logger
BOOST_AUTO_TEST_SUITE(logger_suite);

BOOST_AUTO_TEST_CASE(logger_insert_1)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(logger_get_1)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(logger_get_2)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END();    // End Logger suite
