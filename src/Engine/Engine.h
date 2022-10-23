#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

class Engine
{
public:
    Engine();

    virtual ~Engine();

    std::string generatePassword(int length);

private:
    std::string getRandomCharFromString(std::string sourceString);
    
    std::default_random_engine randomEngine;
    static constexpr const char* CONSONANTS = "bcdfghjklmnpqrstvwzx";
    static constexpr const char* VOWELS = "aeiouy";
    static constexpr const char* DIGITS = "0123456789";
};

class PronouncableEngine : Engine {

};