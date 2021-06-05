/*
 * Password.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "Password.h"

Password::Password() {
}

Password::~Password() {

}

std::string Password::createBasePwd() {
    std::string password;
    std::string consonants = CONSONANTS;
    consonants += UPPER_CONSONANTS;
    std::string vowels = VOWELS;
    vowels += UPPER_VOWELS;
    std::string specials = PUNCTUATION;
    specials += SPECIALS;
    int position[2];


    std::uniform_int_distribution<int> consDis(1, consonants.length());
    std::uniform_int_distribution<int> vowDis(1, vowels.length());

/*!< Génération de 2 séquences consonne-voyelle-consonne */
    for (int cpt = 0; cpt < 2; ++cpt) {
        password += consonants[consDis(rdEngine)];
        password += vowels[vowDis(rdEngine)];
        password += consonants[consDis(rdEngine)];
    }
/*!< Ajout d'un chiffre aléatoire de 0 à 9 */
    std::uniform_int_distribution<int> intDis(1, 9);
    password += std::to_string(intDis(rdEngine));


/*!< Ajout de 2 caractères spéciaux */
    std::uniform_int_distribution<int> specDis(1, specials.length());
    for (int cpt = 0; cpt < 2; ++cpt) {
        position[cpt] = specDis(rdEngine);
        if (cpt > 0) /*!< Si c'est le deuxième caractère */
        {
            while (position[cpt] == position[cpt - 1]) /*!< On ne veut pas que ce soit le même que le premier */
            {
                position[cpt] = specDis(rdEngine);
            }
        }
        password += specials[position[cpt]];
    }
    return password;

}

/** @brief Implémentation de la méthode generatePwd
  *
  * \param length : longueur du mot de passe
  * \return mot de passe prononçable de longueur *length*
  */
std::string Password::generatePwd(int length) {
    std::string password;
    int nbPass; /*!< Nombre de passes */

    /*!< Calcul du nombre de passes nécessaire pour générer le mot de passe de longueur length */
    nbPass = length % has_min_length_PWD == 0 ? length / has_min_length_PWD :
             static_cast<int>(std::round(floor(length / has_min_length_PWD))) + 1;

    for (int cpt = 0; cpt < nbPass; ++cpt) {
        password += createBasePwd();
    }

    /*!< Si la longueur n'est pas un multiple de has_min_length_PWD (modulo > 0),
     * on retire le nombre de caractères nécessaires
     */
    password.erase(length, has_min_length_PWD * nbPass - length);

    return password;
}
