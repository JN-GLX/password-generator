#include "Engine.h"

using namespace RandomUtils;
using namespace StringUtils;

Engine::Engine() 
{
    initializeRandomEngine();
    defaultSourceString = buildAsciiSequence(DEFAULT_FIRST_ASCII_CHAR, DEFAULT_LAST_ASCII_CHAR);
}

Engine::~Engine() 
{

}

std::string Engine::generatePassword(int passwordLength) 
{
    std::string password = getRandomCharSequence(defaultSourceString, passwordLength);
    return password;
}

std::string Engine::buildAsciiSequence(char firstAsciiChar, char lastAsciiChar)
{
    std::string asciiCharSequence = "";
    for (char asciiChar = firstAsciiChar; asciiChar <= lastAsciiChar; asciiChar++)
    {
        asciiCharSequence += asciiChar;
    }
    return asciiCharSequence;    
}