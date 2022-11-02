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

static constexpr const char* STANDARD_ENGINE = "Standard";
static constexpr const char* ALPHANUM_ENGINE = "Alphanumerique";
static constexpr const char* PRONOUNCEABLE_ENGINE = "Prononçable";

enum class EngineName
{
        Standard,
        Alphanumerique,
        Prononçable
};

class Engine
{
public:
    Engine();
    virtual std::string generatePassword(int) const = 0;
    virtual ~Engine();

protected:
    std::string defaultSourceString;
};

class StandardEngine : public Engine
{
public:
    StandardEngine();
    virtual ~StandardEngine();
    std::string generatePassword(int length) const override;
protected:
    std::string buildAsciiSequence(char firstAsciiChar, char lastAsciiChar) const;
private:
    std::string defaultSourceString;
};

class AlphaNumEngine : public Engine
{
public:

    AlphaNumEngine();
    virtual ~AlphaNumEngine();

    std::string generatePassword(int length) const override;

    std::string getRandomConsonants(int nbConsonants) const;
    std::string getRandomVowels(int nbVowels) const;
    std::string getRandomDigits(int nbDigits) const;
};

class PronounceableEngine : public AlphaNumEngine
{
public:
    PronounceableEngine();
    virtual ~PronounceableEngine();

    std::string generatePassword(int length) const override;

    std::string getRandomSpecials(int nbSpecials) const;
    std::string generateLettersSequence() const;

protected:
    int computeNumberOfPasses(int length) const;

private: 
    static const int MINIMUM_PASSWORD_LENGTH = 9;
};

class EngineFactory 
{
public:
    Engine* createEngine(EngineName engineName)
    {
        Engine *passwordEngine = nullptr;
        switch (engineName)
        {
        case EngineName::Standard:
            passwordEngine = new StandardEngine();
            break;
        case EngineName::Alphanumerique:
            passwordEngine = new AlphaNumEngine();
            break;
        case EngineName::Prononçable:
            passwordEngine = new PronounceableEngine();
            break;
        default:            
            break;
        }
        return passwordEngine;
    }
};
#endif
