#include <iostream>
#include "Password/Password.h"
#include "utils.h"
using namespace std;

int main()
{

    Password passwd;
    string pwd;
    int pwdLength = 0;

    // Initialisation du générateur de nombre aléatoires
    srand(time(0));

    // Demande de la longueur du mot de passe à générer
    pwdLength = askForPasswdLength();

    // Générations de 10 mots de passe
    for (int i = 0; i < 10; ++i)
    {
        pwd = passwd.generatePwd(pwdLength);
        cout << i << ":" << pwd << endl;
    }
    return 0;
}
