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
        passwordGenerator(0)
        {
            passwordGenerator = new Password(*(app.passwordGenerator));
        }

        Application& operator=(const Application& app)
        {
            passwordsList = app.passwordsList;
            passwordGenerator = app.passwordGenerator;
            return *this;
        }

        virtual ~Application();
        EngineName getPasswordEngine();
        void initializeGenerator();
        void runGenerator();
        void displayPasswordList();
        std::vector<std::string> getPasswordsList();
        void setNumberOfPasswords(int number);
        int getNumberOfPasswords();
    protected:

        std::vector<std::string> passwordsList;
    private:
        EngineName passwordEngine;
        Password *passwordGenerator;

};

// const int DEFAULT_MINIMUM_PASSWORD_LENGTH = 6;

#endif // APPLICATION_H
