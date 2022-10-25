#include "Engine.h"

using namespace RandomUtils;
using namespace StringUtils;

Engine::Engine() 
{
    initializeRandomEngine();
}

Engine::~Engine() 
{

}

std::string Engine::generatePassword(int passwordLength) 
{
    int firstAsciiChar = 33;
    int lastAsciiChar = 126;

    std::string sourceString = buildAsciiSequence(firstAsciiChar, lastAsciiChar);
    std::string password = getRandomCharSequence(sourceString, passwordLength);
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