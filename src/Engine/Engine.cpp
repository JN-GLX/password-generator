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
    sourceString += UPPER_CONSONANTS;
    sourceString += VOWELS;
    sourceString += UPPER_VOWELS;
    
    for(int count=0; count < length-1; count++)
    {
        password += getRandomCharFromString(sourceString);
    }
    password += getRandomCharFromString(DIGITS);

    return password;
}

std::string Engine::getRandomCharFromString(std::string sourceString) {
    std::uniform_int_distribution<int> charDistribution(1, sourceString.length()-1);
    std::string randomChar;
    randomChar = sourceString[charDistribution(randomEngine)];

    return randomChar;
}