/*
 * Password.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "Password.h"

using namespace StringUtils;
using namespace RandomUtils;

Password::Password() : passwordLength(MINIMUM_PASSWORD_LENGTH), engineName(EngineName::Standard)
{
    this->engineFactory = new EngineFactory();
}

Password::~Password()
{
    delete engineFactory;
}

void Password::setPasswordEngine(EngineName selectedEngineName)
{
    engineName = selectedEngineName;
}

EngineName Password::getPasswordEngine()
{
    return engineName;
}

void Password::setPasswordLength(int length)
{
    passwordLength = length;
}

int Password::getPasswordLength()
{
    return passwordLength;    
}

void Password::generatePasswordWithEngine()
{
    Engine* passwordEngine = engineFactory->createEngine(engineName);
    
    if ( passwordEngine == nullptr)
    {
        throw std::runtime_error("Moteur de génération non défini.");
        return;
    }
    
    try
    {
        password = passwordEngine->generatePassword(passwordLength);
    }
    catch (std::exception& ex)
    {
        std::cout << "Erreur lors de la génération d'un mot de passe." << ex.what() << std::endl;
    }
}

std::string Password::getPassword()
{
    return password;
}