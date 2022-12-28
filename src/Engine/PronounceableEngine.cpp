#include "Engine.h"

using namespace RandomUtils;
using namespace StringUtils;

PronounceableEngine::PronounceableEngine(void) : AlphaNumEngine()
{
    initializeRandomEngine();
    return;
}

PronounceableEngine::~PronounceableEngine()
{

}

std::string PronounceableEngine::generatePassword(int length) const
{
    std::string password = "";
    int numberOfPasses = computeNumberOfPasses(length);

    for (int cpt = 0; cpt < numberOfPasses; ++cpt)
    {
        repeat(2, [&] {password += generateLettersSequence();});
        password += getRandomDigits(1);
        password += getRandomSpecials(2);
    }

    password.erase(length, MINIMUM_PASSWORD_LENGTH * numberOfPasses - length);

    return password;
}

std::string PronounceableEngine::generateLettersSequence() const
{
    std::string letterSequence = getRandomConsonants(1);
    letterSequence += getRandomVowels(1);
    letterSequence += getRandomConsonants(1);

    return letterSequence;
}

std::string PronounceableEngine::getRandomSpecials(int nbSpecials) const
{
    std::string sourceString = PUNCTUATION;
    sourceString += SPECIALS;
    std::string specialsString = getRandomCharSequence(sourceString, nbSpecials);

    return specialsString;
}

int PronounceableEngine::computeNumberOfPasses(int length) const
{
    int numberOfPasses = 0;

    if (length % MINIMUM_PASSWORD_LENGTH == 0)
        numberOfPasses = length / MINIMUM_PASSWORD_LENGTH;
    else
        numberOfPasses = static_cast<int>(std::round(floor(length / MINIMUM_PASSWORD_LENGTH))) + 1;

    return numberOfPasses;
}