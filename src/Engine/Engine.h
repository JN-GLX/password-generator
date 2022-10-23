#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>
#include "randomutils.h"

class Engine
{
public:
    Engine();

    virtual ~Engine();

    std::string generatePassword(int length);

    std::string getRandomConsonants(int nbConsonants);
    std::string getRandomVowels(int nbVowels);
    std::string getRandomDigits(int nbDigits);
};

class PronouncableEngine : Engine {

};