/*!
 * \file Password.h
 * \brief Générateur de mot de passe prononçable
 * \author jn-glx
 * \date 21 nov. 2020
 * \version 0.1
 *
 */

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

#include "helpers.h"
#include "randomutils.h"
#include "Engine.h"

#ifndef SRC_PASSWORD_H_
#define SRC_PASSWORD_H_

/*! \class Password Password.h "Définition".
 * \brief Classe représentant le mot de passe.
 *
 * La classe gère la génération d'un mot de passe
 *
 */
class Password
{
public:
    Password();
    Password(const Password& pwd) : passwordLength(pwd.passwordLength), engineName(pwd.engineName) \
    {
        setPasswordEngine(pwd.engineName);
    }
    void setPasswordEngine(EngineName selectedEngineName);
    EngineName getPasswordEngine();
    void setPasswordLength(int length);
    int getPasswordLength();
    void generatePasswordWithEngine();
    std::string getPassword();
    virtual ~Password();
public:
    /*! Longueur minimale du mot de passe */
    static const int MINIMUM_PASSWORD_LENGTH = 9;
private:
    int passwordLength;
    std::string password;
    EngineName engineName;
    EngineFactory* engineFactory;
};
#endif /* SRC_PASSWORD_H_ */
