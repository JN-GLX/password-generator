#include "application.h"
#include "helpers.h"

Application::Application() : passwordLength(DEFAULT_MINIMUM_PASSWORD_LENGTH), numberOfPasswords(1)
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

bool Application::checkMinPasswordLength(int passwordLength)
{
    return(passwordLength >= passwordGenerator->getMinimumPasswordLength());
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
        break;
    case 'N':
        passwordEngine = EngineName::Numerique;
        break;
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
