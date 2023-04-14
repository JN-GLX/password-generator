#include "Engine.h"
#include "helpers.h"

using namespace RandomUtils;
using namespace StringUtils;

NumericEngine::NumericEngine(void) : AlphaNumEngine()
{
    initializeRandomEngine();
    return;
}

NumericEngine::~NumericEngine()
{

}

std::string NumericEngine::generatePassword(int length) const
{
    std::string password = "";

    for (int cpt = 0; cpt < length; cpt++)
    {
        password += getRandomDigits(1);
    }

    return password;
}