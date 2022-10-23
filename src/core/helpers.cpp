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
}
