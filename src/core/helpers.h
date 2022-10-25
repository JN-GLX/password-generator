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

    std::string getUpperString(std::string lowerString);
    std::string buildLowerUpperCharSequence(std::string lowerString);
    std::string buildAsciiCharSequence(char firstAsciiChar, char lastAsciiChar);
}

