#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <algorithm>
#include <iostream>

template<class F>
void repeat(unsigned times, F callback) {
    while (times--) callback();
}

namespace StringUtils
{
    static constexpr const char* CONSONANTS = "bcdfghjklmnpqrstvwzx";
    static constexpr const char* VOWELS = "aeiouy";
    static constexpr const char* DIGITS = "0123456789";
    static constexpr const char* PUNCTUATION = ".,?;:!_-";
    static constexpr const char* SPECIALS = "()[]={}#+&*%@$<>";
    static const int DEFAULT_FIRST_ASCII_CHAR = 33;
    static const int DEFAULT_LAST_ASCII_CHAR = 126;

    std::string getUpperString(const std::string& lowerString);
    std::string buildLowerUpperCharSequence(const std::string& lowerString);
    std::string buildAsciiCharSequence(const char& firstAsciiChar, const char& lastAsciiChar);
}

#endif