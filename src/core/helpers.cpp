#include "helpers.h"

namespace StringUtils
{
    std:: string getUpperString(std::string lowerString) 
    {
        std::string upperString = lowerString;
        std::transform(upperString.begin(), upperString.end(), upperString.begin(), ::toupper);
        return upperString;
    }

    std::string buildLowerUpperCharSequence(std::string lowerString)
    {
        std::string charSequence = lowerString + getUpperString(lowerString);
        return charSequence;
    }

    std::string buildAsciiCharSequence(char firstAsciiChar, int lastAsciiChar)
    {
        std::string asciiCharSequence = "";
        for (char asciiChar = firstAsciiChar; asciiChar <= lastAsciiChar; asciiChar++)
        {
            asciiCharSequence += asciiChar;
        }
        return asciiCharSequence;
    }
}
