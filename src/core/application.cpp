#include "application.h"
#include "helpers.h"

Application::Application() : passwordLength(9), numberOfPasswords(1)
{
    //ctor
    passwordGenerator = new Password();
    passwordEngine = EngineName::Standard;
 }

Application::~Application()
{
    //dtor
    delete passwordGenerator;
}

bool Application::readCommandLineArguments(int argc, char **argv)
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

void Application::getPwdLengthFromOptArgs()
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

void Application::getNumberPasswordsFromOptArgs()
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

void Application::setNumberOfPasswords(int number)
{
    this->numberOfPasswords = number;
}

int Application::getNumberOfPasswords()
{
    return(this->numberOfPasswords);
}

void Application::setPasswordLength(int length)
{
    this->passwordLength = length;
    passwordGenerator->setPasswordLength(this->passwordLength);
}

int Application::getPasswordLength()
{
    return(this->passwordLength);
}

void Application::initializeGenerator()
{
    passwordGenerator->setPasswordLength(this->passwordLength);
    try
    {
        passwordGenerator->setPasswordEngine(passwordEngine);

    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur lors de l'initialisation du générateur:" << e.what() << '\n';
    }
}

void Application::selectPasswordEngineFromOptArgs(char shortEngineName)
{
    switch (shortEngineName)
    {
    case 'A':
        passwordEngine = EngineName::Alphanumerique;
        break;
    case 'S':
        passwordEngine = EngineName::Standard;
        break;
    case 'P':
        passwordEngine = EngineName::Prononçable;
    default:        
        break;
    } 
}

EngineName Application::getPasswordEngine()
{
    return passwordEngine;
}

void Application::runGenerator() {

    for (int count = 0; count < numberOfPasswords; ++count) {
        passwordGenerator->generatePasswordWithEngine();
        passwordsList.push_back(passwordGenerator->getPassword());
    }
}

void Application::displayPasswordList() {
    if (passwordsList.empty())
    {
        std::cout << "Aucun mot de passe généré." << std::endl;
        return;
    }
    for (const auto& pwd: passwordsList)
    {
        std::cout << pwd << std::endl;
    }
}

std::vector<std::string> Application::getPasswordsList()
{
    return passwordsList;
}
