/*
 * Password.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "Password.h"
#include "helpers.h"

Password::Password() {

     rdEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

Password::~Password() {

}

std::string Password::createBasePwd() {

    std::string password;

/*!< Génération de 2 séquences consonne-voyelle-consonne */
    repeat(2, [&] { password += generateLettersSequence(); });

/*!< Ajout d'un chiffre aléatoire de 0 à 9 */
    password += getRandomDigit();

/*!< Ajout de 2 caractères spéciaux */
    password += getTwoRandomSpecialsChars();
    return password;
}

/** @brief Implémentation de la méthode generatePwd
  *
  * \param length : longueur du mot de passe
  * \return mot de passe prononçable de longueur *length*
  */
std::string Password::generatePwd(int length) {
    std::string password;
    std::string basePwd = "";
    int nbPass; /*!< Nombre de passes */

    /*!< Calcul du nombre de passes nécessaire pour générer le mot de passe de longueur length */
    nbPass = length % has_min_length_PWD == 0 ? length / has_min_length_PWD :
             static_cast<int>(std::round(floor(length / has_min_length_PWD))) + 1;

    for (int cpt = 0; cpt < nbPass; ++cpt) {
        while (basePwd.length() < 9)
        {
            basePwd = createBasePwd();
        }
        password += basePwd;
        basePwd = "";
    }

    /*!< Si la longueur n'est pas un multiple de has_min_length_PWD (modulo > 0),
     * on retire le nombre de caractères nécessaires
     */
    password.erase(length, has_min_length_PWD * nbPass - length);

    return password;
}

std::string Password::generateLettersSequence() {
    std::string lettersSequence;

    lettersSequence += getRandomConsonant();
    lettersSequence += getRandomVowel();
    lettersSequence += getRandomConsonant();

    return lettersSequence;
}

std::string Password::getRandomDigit() {
    std::uniform_int_distribution<int> intDis(0, 9);
    return std::to_string(intDis(rdEngine));
}

std::string Password::getTwoRandomSpecialsChars() {
    std::string specialsSequence;

    repeat(2,[&] {specialsSequence += getRandomSpecial();});
    return specialsSequence;
}

std::string Password::getRandomConsonant() {
    std::string consonants = CONSONANTS;
    consonants += getUpperString(consonants);

    return getRandomCharFromString(consonants);
}

std::string Password::getRandomVowel() {
    std::string vowels = VOWELS;
    vowels += getUpperString(vowels);

    return getRandomCharFromString(vowels);
}

std::string Password::getRandomSpecial() {
    std::string specials = PUNCTUATION;
    specials += SPECIALS;

    return getRandomCharFromString(specials);
}

std::string Password::getUpperString(std::string lowerString) {
    std::string upperString = lowerString;
    std::transform(upperString.begin(), upperString.end(), upperString.begin(), ::toupper);

    return upperString;
}

std::string Password::getRandomCharFromString(std::string sourceString) {
    std::uniform_int_distribution<int> charDistribution(1, sourceString.length()-1);
    std::string randomChar;
    randomChar = sourceString[charDistribution(rdEngine)];

    return randomChar;
}