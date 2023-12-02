#include "commandlineparser.h"

bool CommandLineParser::readCommandLineArguments(int argc, char **argv)
{
    int option = getopt(argc, argv, "hl:n:e:");
    while (option != -1) {
        switch (option) {
            case 'h':
            default :
                displayHelp(argv[0]);
                return false;
            case 'l':
                getPwdLengthFromOptArgs();
                break;
            case 'n':
                getNumberPasswordsFromOptArgs();
                break;
            case 'e':
                selectPasswordEngineFromOptArgs(optarg[0]);
                break;
        }
        option = getopt(argc, argv, "hl:n:e:");
    }
    return true;
}

void CommandLineParser::getPwdLengthFromOptArgs()
{
    char * pEnd;
    int argPwdLength;

    argPwdLength = strtol(optarg, &pEnd, 10);
    if (argPwdLength == 0) {
        setPasswordLength(DEFAULT_MINIMUM_PASSWORD_LENGTH);
    } else {
        if (checkPasswordLength(argPwdLength, DEFAULT_MINIMUM_PASSWORD_LENGTH)) {
            setPasswordLength(argPwdLength);
        } else {
            displayMessageErrorLength(DEFAULT_MINIMUM_PASSWORD_LENGTH);
            setPasswordLength(askForPasswordLength(DEFAULT_MINIMUM_PASSWORD_LENGTH));
        }
    }
}

void CommandLineParser::getNumberPasswordsFromOptArgs()
{
    char * pEnd;
    int argNumberPasswords;

    argNumberPasswords = strtol(optarg, &pEnd, 10);
    if (argNumberPasswords == 0) {
        setNumberOfPasswords(1);
    } else {
        setNumberOfPasswords(argNumberPasswords);
    }
}
