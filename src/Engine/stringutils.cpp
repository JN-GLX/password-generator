#include "stringutils.h"

namespace StringUtils
{
    std:: string getUpperString(const std::string& lowerString)
    {
        std::string upperString = lowerString;
        std::transform(upperString.begin(), upperString.end(), upperString.begin(), ::toupper);
        return upperString;
    }

    std::string buildLowerUpperCharSequence(const std::string& lowerString)
    {
        std::string charSequence = lowerString + getUpperString(lowerString);
        return charSequence;
    }
}
