#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Password/Password.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <getopt.h>

/*! \class Application application.h "Définition".
 * \brief Classe principale du programme.
 *
 * La classe gère l'exécution du programme
 *
 */
class Application
{
    public:
        Application();

        Application(const Application& app) : passwordsList(app.passwordsList), \
                                              numberOfPasswords(app.numberOfPasswords), passwordLength(app.passwordLength), passwordGenerator(0)
        {
            passwordGenerator = new Password(*(app.passwordGenerator));
        }

        Application& operator=(const Application& app)
        {
            passwordsList = app.passwordsList;
            numberOfPasswords = app.numberOfPasswords;
            passwordLength = app.passwordLength;
            passwordGenerator = app.passwordGenerator;
            return *this;
        }

        virtual ~Application();
        bool readCommandLineArguments(int argc, char **argv);
        void selectPasswordEngineFromOptArgs(char shortEngineName);
        EngineName getPasswordEngine();
        bool checkMinPasswordLength(int passwordLength);
        void initializeGenerator();
        void runGenerator();
        void displayPasswordList();
        std::vector<std::string> getPasswordsList();
        void setNumberOfPasswords(int number);
        int getNumberOfPasswords();
        void setPasswordLength(int length);
        int getPasswordLength();
    protected:
        void getPwdLengthFromOptArgs();
        void getNumberPasswordsFromOptArgs();

        std::vector<std::string> passwordsList;
    private:
        int passwordLength;
        int numberOfPasswords;
        EngineName passwordEngine;
        Password *passwordGenerator;
};

#endif // APPLICATION_H
