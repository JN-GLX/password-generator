#include "helpers.h"

namespace StringUtils
{
    std:: string getUpperString(const std::string& lowerString) 
    {
        std::string upperString = lowerString;
        std::transform(upperString.begin(), upperString.end(), upperString.begin(), ::toupper);
        return upperString;
    }

    std::string buildLowerUpperCharSequence(const std::string& lowerString)
    {
        std::string charSequence = lowerString + getUpperString(lowerString);
        return charSequence;
    }
}

bool checkPasswordLength(int pwdLength, int minimalPwdLength)
{
    if ( pwdLength < minimalPwdLength)
    {
        return false;
    }
    return true;
}

void displayMessageErrorLength(int minimalPasswordLength) {
    std::cout << "La longueur du mot de passe doit être au minimum de " << minimalPasswordLength
              << " caractères." << std::endl;
}

void displayHelp(char *progName) {
    std::cout << "Utilisation : " << progName << " [OPTION]" << std::endl;
    std::cout << "Générer un mot de passe de 9 caractères minimum." << std::endl << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << "  -l N        générer un mot de passe de N caractères." << std::endl;
    std::cout << "  -n N        générer N mots de passe." << std::endl;
    std::cout << "  -e S|A|P    moteur de génération: Standard|Alphanumérique|Prononçable." << std::endl;
    std::cout << "  -h          afficher cette aide." << std::endl;
}

int askForPasswordLength(int minimalPasswordLength) {
    int pwdLength = 0;
    do
    {
        std::cout << "Longueur du mot de passe à générer : " << std::endl;
        std::cin >> pwdLength;
        if (!checkPasswordLength(pwdLength, minimalPasswordLength))
        {
            displayMessageErrorLength(minimalPasswordLength);
            pwdLength = -1;
        }
    } while (pwdLength == 0);

    return pwdLength;
}
