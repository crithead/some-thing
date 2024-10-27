/// Helpers - Utility functions
#ifndef ZEBRA_HELPERS_HPP
#define ZEBRA_HELPERS_HPP

namespace zebra {

class Dictionary;
class Logger;

/// @brief Parse command line into a Dictionary.
/// @param[in] argc Argument count
/// @param[in] argv Argument vector
/// @param[out] dict A reference to a Dictionary
void GetOptions(int argc, const char * const *argv, Dictionary& dict);

/// @brief Print usage information.
void PrintUsage(void);

/// @brief Load configuration parameters from a JSON file into the Dictionary.
/// Looks for the file in
/// # The dictionary's value of "parameters-file"
/// # "./parameters.json"
/// @param dict The Dictionary to populate.
void ReadParametersFile(Dictionary& dict);

/// @brief Initialize a Logger from values in the parameters dictionary.
/// Parameters used:
/// * log-trace
/// * log-level
/// * log-file
/// @param[in/out] logger The Logger to configure.
/// @param[in] parameters The parameters to use.
void InitLogger(Logger& logger, const Dictionary& parameters);

} // end namespace zebra

#endif // ZEBRA_HELPERS_HPP
