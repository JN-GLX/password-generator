/*
 * Password_test.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "test_password.h"
#include <algorithm>

using namespace std;

/**
 * @fn int countNbChar(const std::string& inputString, const std::string searchPattern)
 * @brief Fonction pour compter le nombre de caractères présents dans la
 * chaîne 'inputString' appartenant au motif de recherche 'searchPattern'.
 * 
 * Utilise la fonction count_if de la STL avec comme prédicat une fonction lambda 
 * renvoyant 'true' quand un caractère de la chaîne est présent dans le motif.
 * @param[in] inputString La chaîne dans laquelle compter les caractères.
 * @param[in] searchPattern Le motif de recherche (voyelles, consonnes, chiffres,...).
 * @return Le nombre de caractères trouvés appartenant au motif.
 */
int countNbChar(const std::string& inputString, const std::string searchPattern)
{
    return std::count_if(inputString.begin(), inputString.end(), [&](char c) {
        return (searchPattern.find(c) == std::string::npos) ? false : true;
    });
}

/**
 * @brief Teste que le mot de passe créé 
 * fait bien la longueur minimale par défaut (MINIMUM_PASSWORD_LENGTH)
 * 
 */
TEST_F(PasswordTest, defaultMinimalLength) {
    string password = pwd.createBasePwd();

    EXPECT_EQ(password.length(), 9);
}

TEST_F(PasswordTest, HasGivenLength) {
    int pwdLength = 15;
    string password = pwd.generatePwd(pwdLength);

    EXPECT_EQ(password.length(), pwdLength);
}

TEST_F(PasswordTest, HasTwoVowels) {
    string password = pwd.createBasePwd();
    const string vowels ("aeiouyAEIOUY");
    int nbVowels = countNbChar(password, vowels);
    EXPECT_EQ(nbVowels, 2);
}

TEST_F(PasswordTest, HasFourConsonants) {
    string password = pwd.createBasePwd();
    const string consonants = "bcdfghjklmnpqrstvwzxBCDFGHJKLMNPQRSTVWZX";
    int nbConsonants = countNbChar(password, consonants);

    EXPECT_EQ(nbConsonants, 4);
}

TEST_F(PasswordTest, HasDigit) {
    string password = pwd.createBasePwd();
    const string digits ("0123456789");
    int nbDigits = countNbChar(password, digits);

    EXPECT_EQ(nbDigits, 1);
}

TEST_F(PasswordTest, HasTwoSpecials) {
    string password = pwd.createBasePwd();
    const string specials (".,?;:!_-()[]={}#+&*%@$<>");
    int nbSpecials = countNbChar(password, specials);

    EXPECT_EQ(nbSpecials, 2);
}

TEST_F(PasswordTest, TwoRandomConsonantsAreDifferent) {
    string firstConsonant = pwd.getRandomConsonant();
    string secondConsonant = pwd.getRandomConsonant();

    EXPECT_NE(firstConsonant, secondConsonant);
}

TEST_F(PasswordTest, StringIsUpper) {
    string lowerString = "abcdef";
    string upperString = "ABCDEF";

    EXPECT_EQ(upperString, pwd.getUpperString(lowerString));
}

TEST_F(PasswordTest, TwoPasswordsAreDifferent) {
    string firstPassword = pwd.createBasePwd();
    string secondPassword = pwd.createBasePwd();

    EXPECT_NE(firstPassword, secondPassword);
}