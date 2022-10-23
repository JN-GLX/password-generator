#include <string>
#include <algorithm>


template<class F>
void repeat(unsigned times, F callback) {
    while (times--) callback();
}

namespace StringUtils
{
    std:: string getUpperString(std::string lowerString);
}

