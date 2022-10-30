#ifndef ENGINE_H
#define ENGINE_H
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
#include "helpers.h"

class Engine
{
public:
    Engine();

    virtual ~Engine();

    std::string generatePassword(int length);

protected:
    std::string buildAsciiSequence(char firstAsciiChar, char lastAsciiChar);
private:
    std::string defaultSourceString;
};

class StandardEngine : public Engine
{
public:
    StandardEngine();
    virtual ~StandardEngine();
    std::string generatePassword(int length);
protected:
    std::string buildAsciiSequence(char firstAsciiChar, char lastAsciiChar);
private:
    std::string defaultSourceString;
};

class AlphaNumEngine : public Engine
{
public:

    AlphaNumEngine();
    virtual ~AlphaNumEngine();

    std::string generatePassword(int length);

    std::string getRandomConsonants(int nbConsonants);
    std::string getRandomVowels(int nbVowels);
    std::string getRandomDigits(int nbDigits);
};

class PronounceableEngine : Engine {

};
#endif
