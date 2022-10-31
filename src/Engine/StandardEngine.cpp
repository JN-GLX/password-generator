#include "Engine.h"

using namespace RandomUtils;
using namespace StringUtils;

StandardEngine::StandardEngine(void) : Engine()
{
    initializeRandomEngine();
    defaultSourceString = buildAsciiSequence(DEFAULT_FIRST_ASCII_CHAR, DEFAULT_LAST_ASCII_CHAR);
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

std::string StandardEngine::buildAsciiSequence(char firstAsciiChar, char lastAsciiChar) const
{
    std::string asciiCharSequence = "";
    for (char asciiChar = firstAsciiChar; asciiChar <= lastAsciiChar; asciiChar++)
    {
        asciiCharSequence += asciiChar;
    }
    return asciiCharSequence;    
}