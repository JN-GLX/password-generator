/*
 * Password.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "Password.h"

Password::Password()
{
    // Initialisation  des listes de caractères pour le générateur
}

Password::~Password()
{
    // TODO Auto-generated destructor stub
}

std::string Password::createBasePwd()
{
    std::string password = "";
    std::string consonants = CONSONANTS;
    consonants += UPPER_CONSONANTS;
    std::string vowels = VOWELS;
    vowels += UPPER_VOWELS;
    std::string specials = PUNCTUATION;
    specials += SPECIALS;

/*!< Génération de 2 séquences consonne-voyelle-consonne */
    for(int cpt = 0; cpt < 2; ++cpt)
    {
        password += consonants[rand() % consonants.length()];
        password += vowels[rand() % vowels.length()];
        password += consonants[rand() % consonants.length()];
    }
/*!< Ajout d'un chiffre aléatoire de 0 à 9 */
    password += std::to_string(rand() % 10);

/*!< Ajout de 2 caractères spéciaux */
    for (int cpt = 0; cpt < 2; ++cpt)
    {
        password += specials[rand() % specials.length()];
    }
    return password;

}
/** @brief Implémentation de la méthode generatePwd
  *
  * \param length : longueur du mot de passe
  * \return mot de passe prononçable de longueur *length*
  */
std::string Password::generatePwd(int length)
{
    std::string password = "";
    if (length >= MIN_LENGTH_PWD)
    {
        password = createBasePwd();
    }

    return password;
}
