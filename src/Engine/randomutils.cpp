#include "randomutils.h"

using namespace StringUtils;

namespace RandomUtils
{
    std::default_random_engine randomEngine;

    void initializeRandomEngine()
    {
        randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }

    int getRandomNumber(const int& range)
    {
        std::uniform_int_distribution<int> numberDistribution(1, range);
        return numberDistribution(randomEngine);
    }

    std::string getRandomCharSequence(const std::string& sourceString, const int& nbChars)
    {
        std::string charSequence = "";
        for(int count = 0; count < nbChars; count++)
        {
            charSequence += getRandomCharFromString(sourceString);
        }
        return charSequence;
    }

    std::string getRandomCharFromString(const std::string& sourceString)
    {
        std::uniform_int_distribution<int> charDistribution(1, sourceString.length()-1);
        std::string randomChar;
        randomChar = sourceString[charDistribution(randomEngine)];
        return randomChar;
    }

    std::string getRandomSpecials(const int nbSpecials)
    {
        std::string sourceString = PUNCTUATION;
        sourceString += SPECIALS;
        std::string specialsString = getRandomCharSequence(sourceString, nbSpecials);

        return specialsString;
    }

std::string getRandomConsonants(const int nbConsonants)
{
    std::string sourceString = buildLowerUpperCharSequence(CONSONANTS);
    std::string randomConsonants = getRandomCharSequence(sourceString, nbConsonants);

    return randomConsonants;
}

std::string getRandomVowels(const int nbVowels)
{
    std::string sourceString = buildLowerUpperCharSequence(VOWELS);
    std::string randomVowels = getRandomCharSequence(sourceString, nbVowels);

    return randomVowels;
}

std::string getRandomDigits(const int nbDigits)
{
    std::string randomDigits = getRandomCharSequence(DIGITS, nbDigits);
    return randomDigits;
}
}