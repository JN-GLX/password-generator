#include "Engine.h"
#include "helpers.h"

using namespace RandomUtils;
using namespace StringUtils;

Engine::Engine() 
{
    initializeRandomEngine();
}

Engine::~Engine() 
{

}

std::string Engine::generatePassword(int passwordLength) 
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

std::string Engine::getRandomConsonants(int nbConsonants) 
{
    std::string sourceString = CONSONANTS;
    sourceString += getUpperString(sourceString);

    std::string randomConsonants = getRandomCharSequence(sourceString, nbConsonants);

    return randomConsonants;
}

std::string Engine::getRandomVowels(int nbVowels) 
{
    std::string sourceString = VOWELS;
    sourceString += getUpperString(sourceString);

    std::string randomVowels = getRandomCharSequence(sourceString, nbVowels);

    return randomVowels;
}

std::string Engine::getRandomDigits(int nbDigits) 
{
    std::string randomDigits = getRandomCharSequence(DIGITS, nbDigits);
    return randomDigits;
}