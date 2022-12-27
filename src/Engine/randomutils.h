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
#include "helpers.h"

namespace RandomUtils
{
    void initializeRandomEngine();

    int getRandomNumber(const int& range);
    std::string getRandomCharSequence(const std::string& sourceString, const int& nbChars);
    std::string getRandomCharFromString(const std::string& sourceString);
    std::string getRandomSpecials(const int nbSpecials);
    std::string getRandomConsonants(const int nbConsonants);
    std::string getRandomVowels(const int nbVowels);
    std::string getRandomDigits(const int nbDigits);

}
#endif /*RANDOMUTILS_H*/