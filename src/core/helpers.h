#include <string>
#include <algorithm>


template<class F>
void repeat(unsigned times, F callback) {
    while (times--) callback();
}

std:: string getUpperString(std::string lowerString);
