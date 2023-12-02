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
#include "stringutils.h"

static constexpr const char* STANDARD_ENGINE = "Standard";
static constexpr const char* ALPHANUM_ENGINE = "Alphanumerique";
static constexpr const char* PRONOUNCEABLE_ENGINE = "Prononçable";
static constexpr const char* NUMERIC_ENGINE = "Numerique";

enum class EngineName
{
        Standard,
        Alphanumerique,
        Prononçable,
        Numerique
};

class Engine
{
public:
    Engine();
    virtual std::string generatePassword(int) const = 0;
    virtual ~Engine();
    static const int MINIMUM_PASSWORD_LENGTH = 8;
protected:
    std::string defaultSourceString;
};

class StandardEngine : public Engine
{
public:
    StandardEngine();
    virtual ~StandardEngine();
    std::string generatePassword(int length) const override;
};

class AlphaNumEngine : public Engine
{
public:

    AlphaNumEngine();
    virtual ~AlphaNumEngine();

    std::string generatePassword(int length) const override;
protected:
};

class PronounceableEngine : public AlphaNumEngine
{
public:
    PronounceableEngine();
    virtual ~PronounceableEngine();
    std::string generatePassword(int length) const override;
    static const int MINIMUM_PASSWORD_LENGTH = 9;
private:
    int computeNumberOfPasses(int length) const;
    std::string generateLettersSequence() const;
};

class NumericEngine: public AlphaNumEngine
{
public:
    NumericEngine();
    virtual ~NumericEngine();
    std::string generatePassword(int length) const override;
    static const int MINIMUM_PASSWORD_LENGTH = 6;
private:
};

class EngineFactory
{
public:
    Engine* createEngine(EngineName engineName)
    {
        Engine *passwordEngine = nullptr;
        switch (engineName)
        {
        case EngineName::Standard: {
            passwordEngine = new StandardEngine();
        }break;
        case EngineName::Alphanumerique: {
            passwordEngine = new AlphaNumEngine();
        }break;
        case EngineName::Prononçable: {
            passwordEngine = new PronounceableEngine();
        }break;
        case EngineName::Numerique: {
            passwordEngine = new NumericEngine();
        }break;
        default:
            break;
        }
        return passwordEngine;
    }
};
#endif
