#include <iostream>
#include "src/Password/Password.h"
using namespace std;

int main()
{
    // Initialisation du générateur de nombre aléatoires
    srand(time(0));
    Password passwd;
    string pwd;

    // Générations de 10 mots de passe
    for (int i = 0; i < 10; ++i)
    {
        pwd = passwd.createBasePwd();
        cout << i << ":" << pwd << endl;
    }
    return 0;
}
