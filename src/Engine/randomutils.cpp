#include "randomutils.h"

namespace RandomUtils
{
    std::default_random_engine randomEngine;

    void initializeRandomEngine()
    {
        randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }

    int getRandomNumber(int range) 
    {
        std::uniform_int_distribution<int> numberDistribution(1, range);
        return numberDistribution(randomEngine);
    }

    std::string getRandomCharSequence(std::string sourceString, int nbChars) 
    {
        std::string charSequence = "";
        for(int count = 0; count < nbChars; count++)
        {
            charSequence += getRandomCharFromString(sourceString);
        }
        return charSequence;
    }

    std::string getRandomCharFromString(std::string sourceString) 
    {
        std::uniform_int_distribution<int> charDistribution(1, sourceString.length()-1);
        std::string randomChar;
        randomChar = sourceString[charDistribution(randomEngine)];
        return randomChar;
    }

}