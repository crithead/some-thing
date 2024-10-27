/// Thing Exception Classes
#ifndef ZEBRA_EXCEPTION_HPP
#define ZEBRA_EXCEPTION_HPP

#include <exception>

namespace zebra
{

/// General program error.
class Error : public std::exception
{
};

/// File not found.
class FileNotFound : public Error
{
};

/// Key not found.
class KeyNotFound : public Error
{
};

///
class ConversionError : public Error
{
};

}    // end namespace zebra

#endif    // ZEBRA_EXCEPTION_HPP
