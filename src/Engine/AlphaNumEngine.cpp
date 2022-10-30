#include "Engine.h"
#include "helpers.h"

using namespace RandomUtils;
using namespace StringUtils;

AlphaNumEngine::AlphaNumEngine(void) : Engine()
{
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

std::string AlphaNumEngine::getRandomConsonants(int nbConsonants) const
{
    std::string sourceString = buildLowerUpperCharSequence(CONSONANTS);
    std::string randomConsonants = getRandomCharSequence(sourceString, nbConsonants);

    return randomConsonants;
}

std::string AlphaNumEngine::getRandomVowels(int nbVowels) const
{
    std::string sourceString = buildLowerUpperCharSequence(VOWELS);
    std::string randomVowels = getRandomCharSequence(sourceString, nbVowels);

    return randomVowels;
}

std::string AlphaNumEngine::getRandomDigits(int nbDigits) const
{
    std::string randomDigits = getRandomCharSequence(DIGITS, nbDigits);
    return randomDigits;
}