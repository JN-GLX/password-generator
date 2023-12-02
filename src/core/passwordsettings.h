#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include "../Password/Password.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <getopt.h>

/*! \class PasswordSettings
 * \brief Classe pour la gestion des paramètres du mot de passe
 */
class PasswordSettings
{
    public:
        PasswordSettings();
        PasswordSettings(const PasswordSettings &pwdSets) : numberOfPasswords(pwdSets.numberOfPasswords), passwordLength(pwdSets.passwordLength)
        {}
        PasswordSettings& operator=(const PasswordSettings& pwdSets)
        {
            numberOfPasswords = pwdSets.numberOfPasswords;
            passwordLength = pwdSets.passwordLength;
            return *this;
        }

        virtual ~PasswordSettings();

        void setNumberOfPasswords(int number);
        int getNumberOfPasswords();
        void setPasswordLength(int length);
        int getPasswordLength();
    private:
        int passwordLength;
        int numberOfPasswords;

};