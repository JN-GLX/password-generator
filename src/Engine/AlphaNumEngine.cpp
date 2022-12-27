#include "Engine.h"
#include "helpers.h"

using namespace RandomUtils;
using namespace StringUtils;

AlphaNumEngine::AlphaNumEngine(void) : Engine()
{
    initializeRandomEngine();
    return;
}

AlphaNumEngine::~AlphaNumEngine()
{

}

std::string AlphaNumEngine::generatePassword(int passwordLength) const
{
    std::string password = "";

    int nbConsonants = getRandomNumber(passwordLength-2);
    password = getRandomConsonants(nbConsonants);

    int nbVowels = getRandomNumber(passwordLength - nbConsonants - 1);
    password += getRandomVowels(nbVowels);

    int nbDigits = passwordLength - (nbConsonants + nbVowels);
    password += getRandomDigits(nbDigits);

    return password;
}

