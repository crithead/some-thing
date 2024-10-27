/// Dictionary of string -> string
#ifndef ZEBRA_DICTIONARY_HPP
#define ZEBRA_DICTIONARY_HPP

#include <string>
#include <unordered_map>

#include "exceptions.hpp"

using String = std::string;

namespace zebra {

/// A string-string dictionary
class Dictionary
{
public:
    /// Default constructor.
    Dictionary();
    /// Copy constructor.
    Dictionary(const Dictionary& dict);
    /// Destructor.
    ~Dictionary();

    /// @brief Get a value
    /// @param key The key
    /// @return The value
    /// @throws KeyNotFound when the key is not present
    String Get(const String& key) const;

    /// @brief Get a value or default
    /// @param key The key.
    /// @param value A default value, if key is missing.
    /// @return The value
    String Get(const String& key, const String& value) const noexcept;

    bool GetBool(const String& key) const;
    bool GetBool(const String& key, bool value) const noexcept;
    float GetFloat(const String& key) const;
    float GetFloat(const String& key, float value) const noexcept;
    int GetInt(const String& key) const;
    int GetInt(const String& key, int value) const noexcept;

    /// @brief Test if the key exists in the Dictionary
    /// @param key The key to check for.
    /// @retval true The key exists in the Dictionary.
    /// @retval false The key does not exist in the Dictionary.
    bool HasKey(const String& key) const noexcept;

    /// @brief Insert a value with the corresponding key.
    /// If the key already exists, its value will be over-written with the
    /// new value.
    /// @param key The key.
    /// @param value The value.
    void Insert(const String& key, const String& value);

    /// @brief Get the number of keys in the Dictionary.
    /// @return The number of keys in the dictionary.
    size_t Size() const noexcept;

private:
    std::unordered_map<String, String> data;
};

} // end namespace zebra

#endif // ZEBRA_DICTIONARY_HPP
