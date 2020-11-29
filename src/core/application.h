#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Password/Password.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <getopt.h>

/*! \class Application application.h "Définition".
 * \brief Classe principale du programme.
 *
 * La classe gère l'exécution du programme
 *
 */
class Application
{
    public:
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe Application
     *
     */
        Application();
    /*!
     * \brief Destructeur
     *
     * Destructeur de la classe Application;
     */
        virtual ~Application();
    /*!
     * \fn readArguments
     * \brief Lecture des arguments de la ligne de commande
     *
     * Lit les valeurs indiquées par les options -l et -n
     * et les affecte aux variables m_pwdLength et m_nbPwd
     *
     * \param argc : nombre d'arguments
     * \param argv : liste des arguments
     *
     * \return Vrai si les options sont valides, Faux sinon
    */
    bool readArguments(int argc, char **argv);
    /*!
     * \fn runGenerator
     * \brief Lancement du générateur de mot de passe
     *
     * Initialise le générateur de nombres aléatoires et
     * génère \see m_nbPwd mots de passe de longueur \see m_lengthPwd
     * Chaque mot de passe généré est stocké dans \see m_listPwd
     */
    void runGenerator();
    /*!
     * @fn displayPwdList
     * \brief Affiche la liste des mots de passe générés
     *
     * Affiche sur la sortie standard le contenu de \see m_listPwd
     */
    void displayPwdList();
protected:
    /*!
     * @fn checkPwdLength
     * @brief Vérifie la longueur  passée en paramètre
     * @param pwdLength : longueur
     * @return Vrai si la longueur est supérieur ou égale à la
     * longueur minimale, Faux sinon.
     */
    static bool checkPwdLength(int pwdLength);
    /*!
     * @fn displayErrorLength
     * @brief Affiche un message d'erreur sur la sortie standard
     * indiquant que la longueur du mot de passe est invalide
     */
    static void displayErrorLength();
    /*!
     * @fn displayHelp
     * @brief Affiche l'aide du programme
     * @param progName : nom de l'exécutable
     */
    static void displayHelp(char *progName);
    /*!
     * @fn askForPwdLength
     * @brief Demande la saisie de la longueur du mot de passe à générer
     * @return la longueur saisie
     */
    static int askForPwdLength();

public:

private:
    int m_argCount; //!< Member variable "m_argCount"
//    std::vector<std::string> m_argList; //!< Member variable "m_argList"
    /*!
     * /brief Variables membres
     *
     * /var m_pwdLength : longueur du mot de passe à générer
     * /var m_nbPwd : nombre de mots de passe à générer
     * /var m_listPwd : liste des mots de passe générés
     * /var m_passwd : le générateur de mot de passe
     */
    int m_pwdLength;
    int m_nbPwd;
    std::vector<std::string> m_listPwd;
    Password *m_passwd;
};

#endif // APPLICATION_H
