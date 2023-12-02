/*
 * Password.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "Password.h"

using namespace StringUtils;
using namespace RandomUtils;

Password::Password() : passwordLength(DEFAULT_MINIMUM_PASSWORD_LENGTH), engineName(EngineName::Standard)
{

}

Password::~Password()
{

}

void Password::setPasswordEngine(EngineName selectedEngineName)
{
    engineName = selectedEngineName;
    EngineFactory engineFactory;
    passwordEngine = engineFactory.createEngine(engineName);
}

void Password::setPasswordLength(int length)
{
    passwordLength = length;
}

void Password::generatePasswordWithEngine()
{
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

int Password::getMinimumPasswordLength()
{
    return passwordEngine->MINIMUM_PASSWORD_LENGTH;
}