#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

namespace RandomUtils
{
    void initializeRandomEngine();

    int getRandomNumber(int range);
    std::string getRandomCharSequence(std::string sourceString, int nbChars);
    std::string getRandomCharFromString(std::string sourceString);
}
#endif /*RANDOMUTILS_H*/