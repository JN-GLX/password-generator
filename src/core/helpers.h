#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <algorithm>


template<class F>
void repeat(unsigned times, F callback) {
    while (times--) callback();
}

namespace StringUtils
{
    static constexpr const char* CONSONANTS = "bcdfghjklmnpqrstvwzx";
    static constexpr const char* VOWELS = "aeiouy";
    static constexpr const char* DIGITS = "0123456789";
    static const int DEFAULT_FIRST_ASCII_CHAR = 33;
    static const int DEFAULT_LAST_ASCII_CHAR = 126;

    std::string getUpperString(std::string lowerString);
    std::string buildLowerUpperCharSequence(std::string lowerString);
    std::string buildAsciiCharSequence(char firstAsciiChar, char lastAsciiChar);
}
#endif
