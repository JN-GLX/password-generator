#include "utils.h"
#include "Password/Password.h"

int askForPasswdLength()
{
    int pwdLength = 0;

    do
    {
        std::cout << "Longueur du mot de passe à générer : " << std::endl;
        std::cin >> pwdLength;
    } while (!checkPwdLength(pwdLength));

    return pwdLength;
}

void displayHelp(char* progName)
{
    std::cout << "Utilisation : " << progName << " [OPTION]" << std::endl;
    std::cout << "Générer un mot de passe prononçable de 9 caractères minimum." << std::endl << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << "  -l N        générer un mot de passe de N caractères." << std::endl;
    std::cout << "  -n N        générer N mots de passe." << std::endl;
    std::cout << "  -h          afficher cette aide." << std::endl;

}

bool checkPwdLength(int pwdLength)
{

    if ( pwdLength < Password::MIN_LENGTH_PWD)
    {
        std::cout << "La longueur du mot de passe doit être au minimum de " << Password::MIN_LENGTH_PWD
             << " caractères." << std::endl;
        return false;
    }
    return true;
}
