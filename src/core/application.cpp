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
                m_pwdLength = atoi(optarg);
                if (m_pwdLength == 0) {
                    m_pwdLength = Password::MIN_LENGTH_PWD;
                } else {
                    if (!checkPwdLength(m_pwdLength)) {
                        m_pwdLength = askForPwdLength();
                    } else {
                        displayErrorLength();
                        return false;
                    }
                }
                break;
            case 'n':
                m_nbPwd = atoi(optarg);
                if (m_nbPwd == 0) {
                    m_nbPwd = 1;
                }
                break;
        }
        option = getopt(argc, argv, "hl:n:");
    }
    return true;
}
bool Application::checkPwdLength(int pwdLength)
{
    if ( pwdLength < Password::MIN_LENGTH_PWD)
    {
        return false;
    }
    return true;
}

void Application::displayErrorLength() {
    std::cout << "La longueur du mot de passe doit être au minimum de " << Password::MIN_LENGTH_PWD
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
        }
    } while (pwdLength == 0);

    return pwdLength;
}

void Application::runGenerator() {
    // Initialisation du générateur de nombre aléatoires
    srand(time(0));

    for (int i = 0; i < m_nbPwd; ++i) {
        m_listPwd.push_back(m_passwd->generatePwd(m_pwdLength));
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


