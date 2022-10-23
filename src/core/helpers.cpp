#include "helpers.h"

std:: string getUpperString(std::string lowerString) {
    std::string upperString = lowerString;
    std::transform(upperString.begin(), upperString.end(), upperString.begin(), ::toupper);

    return upperString;
}