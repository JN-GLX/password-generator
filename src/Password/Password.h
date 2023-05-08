/*!
 * \file Password.h
 * \brief Générateur de mot de passe
 * \author jn-glx
 * \date 2 nov. 2022
 * \version 1.0
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

class Password
{
public:
    Password();
    Password(const Password& pwd) : passwordLength(pwd.passwordLength), engineName(pwd.engineName) \
    {
        setPasswordEngine(pwd.engineName);
    }
    void setPasswordEngine(EngineName selectedEngineName);
    void setPasswordLength(int length);
    void generatePasswordWithEngine();
    int getMinimumPasswordLength();
    std::string getPassword();
    virtual ~Password();
private:
    int passwordLength;
    std::string password;
    EngineName engineName;
    Engine *passwordEngine;
};
#endif /* SRC_PASSWORD_H_ */
