#include "Engine.h"

using namespace RandomUtils;
using namespace StringUtils;

StandardEngine::StandardEngine(void) : Engine()
{
    initializeRandomEngine();
    defaultSourceString = StringUtils::buildAsciiCharSequence(DEFAULT_FIRST_ASCII_CHAR, DEFAULT_LAST_ASCII_CHAR);
    return;
}

StandardEngine::~StandardEngine()
{

}

std::string StandardEngine::generatePassword(int passwordLength) const
{
    std::string password = getRandomCharSequence(defaultSourceString, passwordLength);
    return password;
}

