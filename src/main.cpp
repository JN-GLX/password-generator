
#include "Password/Password.h"
#include "utils.h"
using namespace std;

int main(int argc, char** argv)
{
    Password passwd;
    string pwd = "";
    int option = 0;
    int pwdLength = Password::MIN_LENGTH_PWD;
    int pwdNumber = 1;

    /*!< Analyse des arguments de la ligne de commande */
    while ((option = getopt(argc, argv, "hl:n:")) != -1)
    {
        switch (option)
        {
        case 'h':
        default :
            displayHelp(argv[0]);
            return -1;

        case 'l':
            pwdLength = atoi(optarg);
            if (pwdLength == 0)
            {
                pwdLength = Password::MIN_LENGTH_PWD;
            }
            else
            {
                if (!checkPwdLength(pwdLength))
                {
                    pwdLength = askForPasswdLength();
                }
            }
            break;
        case 'n':
            pwdNumber = atoi(optarg);
            if ((pwdNumber == 0))
            {
                pwdNumber = 1;
            }
            break;
        }
    }
    // Initialisation du générateur de nombre aléatoires
    srand(time(0));

    // Générations de x mots de passe
    for (int i = 0; i < pwdNumber; ++i)
    {
        pwd = passwd.generatePwd(pwdLength);
        cout << pwd << endl;
    }
    return 0;
}
