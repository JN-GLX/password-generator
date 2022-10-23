#include "Engine.h"
#include "helpers.h"

Engine::Engine() {
    randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

Engine::~Engine() {

}

std::string Engine::generatePassword(int length) {
    std::string password = "";

    std::string sourceString = CONSONANTS;
    sourceString += getUpperString(sourceString);
    
    std::uniform_int_distribution<int> nbConsonantsDistribution(1, length-2);
    int nbConsonants = nbConsonantsDistribution(randomEngine);
    for(int count = 0; count < nbConsonants; count++)
    {
        password += getRandomCharFromString(sourceString);
    }

    std::uniform_int_distribution<int> numberDistribution(1, length-nbConsonants);
    int nbVowels = numberDistribution(randomEngine);
    sourceString = VOWELS;
    sourceString += getUpperString(sourceString);

    for(int count =0; count < nbVowels; count++)
    {
        password += getRandomCharFromString(sourceString);
    }

    for(int count=0; count < length - (nbConsonants + nbVowels); count++)
    {
        password += getRandomCharFromString(DIGITS);
    }
    

    return password;
}

std::string Engine::getRandomCharFromString(std::string sourceString) {
    std::uniform_int_distribution<int> charDistribution(1, sourceString.length()-1);
    std::string randomChar;
    randomChar = sourceString[charDistribution(randomEngine)];

    return randomChar;
}