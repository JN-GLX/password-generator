#include "Engine.h"
#include "helpers.h"

Engine::Engine() 
{
    randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
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

std::string Engine::getRandomCharFromString(std::string sourceString) 
{
    std::uniform_int_distribution<int> charDistribution(1, sourceString.length()-1);
    std::string randomChar;
    
    randomChar = sourceString[charDistribution(randomEngine)];

    return randomChar;
}

int Engine::getRandomNumber(int range) 
{
    std::uniform_int_distribution<int> numberDistribution(1, range);
    return numberDistribution(randomEngine);
}

std::string Engine::getRandomCharSequence(std::string sourceString, int nbChars) 
{
    std::string charSequence = "";
    
    for(int count = 0; count < nbChars; count++)
    {
        charSequence += getRandomCharFromString(sourceString);
    }

    return charSequence;
}