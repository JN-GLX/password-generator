#include "application.h"

Application::Application() : m_pwdLength(9), m_nbPwd(1), m_argCount(0)
{
    //ctor
    m_passwd = new Password;
 }

Application::~Application()
{
    //dtor
    delete m_passwd;
}

bool Application::readArguments(int argc, char **argv)
{
    int option = getopt(argc, argv, "hl:n:");

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
        }
        option = getopt(argc, argv, "hl:n:");
    }
    return true;
}

void Application::getPwdLengthFromOptArgs()
{
    char * pEnd;
    int argPwdLength;

    argPwdLength = strtol(optarg, &pEnd, 10);
    if (argPwdLength == 0) {
        m_pwdLength = Password::MINIMUM_PASSWORD_LENGTH;
    } else {
        if (checkPwdLength(argPwdLength)) {
            m_pwdLength = argPwdLength;
        } else {
            displayErrorLength();
            m_pwdLength = askForPwdLength();
        }
    }
}

void Application::getNumberPasswordsFromOptArgs()
{
    char * pEnd;
    int argNumberPasswords;

    argNumberPasswords = strtol(optarg, &pEnd, 10);
    if (argNumberPasswords == 0) {
        m_nbPwd = 1;
    } else {
        m_nbPwd = argNumberPasswords;
    }    
}

bool Application::checkPwdLength(int pwdLength)
{
    if ( pwdLength < Password::MINIMUM_PASSWORD_LENGTH)
    {
        return false;
    }
    return true;
}

void Application::displayErrorLength() {
    std::cout << "La longueur du mot de passe doit être au minimum de " << Password::MINIMUM_PASSWORD_LENGTH
              << " caractères." << std::endl;
}

void Application::displayHelp(char *progName) {
    std::cout << "Utilisation : " << progName << " [OPTION]" << std::endl;
    std::cout << "Générer un mot de passe prononçable de 9 caractères minimum." << std::endl << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << "  -l N        générer un mot de passe de N caractères." << std::endl;
    std::cout << "  -n N        générer N mots de passe." << std::endl;
    std::cout << "  -h          afficher cette aide." << std::endl;
}

int Application::askForPwdLength() {
    int pwdLength = 0;
    do
    {
        std::cout << "Longueur du mot de passe à générer : " << std::endl;
        std::cin >> pwdLength;
        if (!checkPwdLength(pwdLength))
        {
            displayErrorLength();
            pwdLength = -1;
        }
    } while (pwdLength == 0);

    return pwdLength;
}

void Application::runGenerator() {
    // Initialisation du générateur de nombre aléatoires

    for (int i = 0; i < m_nbPwd; ++i) {
        m_listPwd.push_back(m_passwd->generateLongPassword(m_pwdLength));
    }
}

void Application::displayPwdList() {
    if (m_listPwd.empty())
    {
        std::cout << "Aucun mot de passe généré." << std::endl;
        return;
    }
    for (const auto& pwd: m_listPwd)
    {
        std::cout << pwd << std::endl;
    }
}


