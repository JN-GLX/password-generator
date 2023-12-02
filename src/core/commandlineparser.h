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

/*! \class CommandLineParser
 * \brief Classe pour la gestion des arguments de la ligne de commande
 */

class CommandLineParser
{
    public:
        CommandLineParser();
        virtual ~CommandLineParser();
        bool readCommandLineArguments(int argc, char **argv);
        void selectPasswordEngineFromOptArgs(char shortEngineName);
        bool checkMinPasswordLength(int passwordLength);
        void getPwdLengthFromOptArgs();
        void getNumberPasswordsFromOptArgs();
};

#endif