/// Dictionary of string -> string

#include <stdexcept>
#include <string>
#include <unordered_map>

#include "dictionary.hpp"
#include "exceptions.hpp"

namespace zebra {

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(const Dictionary& dict)
{
    this->data = dict.data;
}

Dictionary::~Dictionary()
{
    this->data.clear();
}

String Dictionary::Get(const String& key) const
{
    try {
        return String {this->data.at(key)};
    }
    catch (const std::out_of_range& e) {
        throw KeyNotFound();
    }
}

String Dictionary::Get(const String& key, const String& defaultValue) const noexcept
{
    if (HasKey(key)) {
        return String {this->data.at(key)};
    }
    else {
        return String {defaultValue};
    }
}

bool Dictionary::GetBool(const String& key) const
{
    try {
        const String& value = this->data.at(key);
        if (value.empty() || value == "false" || value == "0") {
            return false;
        }
        return true;
    }
    catch (const std::out_of_range& e) {
        throw KeyNotFound();
    }
}

bool Dictionary::GetBool(const String& key, bool defaultValue) const noexcept
{
    try {
        const String& value = this->data.at(key);
        if (value.empty() || value == "false" || value == "0") {
            return false;
        }
        return true;
    }
    catch (const std::out_of_range& e) {
        return defaultValue;
    }
}

float Dictionary::GetFloat(const String& key) const
{
    try {
        const String& value = this->data.at(key);
        return std::stof(value);
    }
    catch (const std::invalid_argument&) {
        throw ConversionError();
    }
    catch (const std::out_of_range& e) {
        throw KeyNotFound();
    }
}

float Dictionary::GetFloat(const String& key, float defaultValue) const noexcept
{
    try {
        const String& value = this->data.at(key);
        return std::stof(value);
    }
    catch (const std::invalid_argument&) {
        return defaultValue;
    }
    catch (const std::out_of_range&) {
        return defaultValue;
    }
}

int Dictionary::GetInt(const String& key) const
{
    try {
        const String& value = this->data.at(key);
        return std::stoi(value);
    }
    catch (const std::invalid_argument&) {
        throw ConversionError();
    }
    catch (const std::out_of_range&) {
        throw KeyNotFound();
    }
}

int Dictionary::GetInt(const String& key, int defaultValue) const noexcept
{
    try {
        const String& value = this->data.at(key);
        return std::stoi(value);
    }
    catch (const std::invalid_argument&) {
        return defaultValue;
    }
    catch (const std::out_of_range&) {
        return defaultValue;
    }
}

bool Dictionary::HasKey(const String& key) const noexcept
{
    return this->data.count(key) == 1;
}


void Dictionary::Insert(const String& key, const String& value)
{
    this->data[key] = value;
}

size_t Dictionary::Size() const noexcept
{
    return this->data.size();
}

} // end namespace zebra
