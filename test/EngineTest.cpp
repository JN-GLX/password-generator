#include <algorithm>
#include "EngineTest.h"

using namespace std;
using namespace RandomUtils;
using namespace StringUtils;

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

TEST_F(EngineTest, HasGivenLength)
{
    int passwordLength = 15;
    password = passwordEngine.generatePassword(passwordLength);

    EXPECT_EQ(password.length(), passwordLength);    
}

TEST_F(EngineTest, TwoPasswordsAreDifferent) {
    string otherPassword = passwordEngine.generatePassword(MINIMAL_PASSWORD_LENGTH);
    EXPECT_NE(password, otherPassword);
}

TEST_F(AlphaNumEngineTest, HasGivenLength) {
    int passwordLength = 15;
    password = alphanumPasswordEngine.generatePassword(passwordLength);

    EXPECT_EQ(password.length(), passwordLength);
}

TEST_F(AlphaNumEngineTest, HasVowel) {
    std::string vowelsString = buildLowerUpperCharSequence(VOWELS);

    int nbVowels = countNbChar(password, vowelsString);

    EXPECT_GE(nbVowels, 1);
}

TEST_F(AlphaNumEngineTest, HasConsonant) {
    std::string consonantsString = buildLowerUpperCharSequence(CONSONANTS);
    
    int nbConsonants = countNbChar(password, consonantsString);

    EXPECT_GE(nbConsonants, 1);
}

TEST_F(AlphaNumEngineTest, HasDigit) {
    int nbDigits = countNbChar(password, DIGITS);
    EXPECT_GE(nbDigits, 1);
}

TEST_F(AlphaNumEngineTest, TwoPasswordsAreDifferent) {
    string otherPassword = alphanumPasswordEngine.generatePassword(MINIMAL_PASSWORD_LENGTH);
    EXPECT_NE(password, otherPassword);
}

TEST(StringsUtils, StringIsUpper) 
{
    string lowerString = "abcdef";
    string upperString = "ABCDEF";

    EXPECT_EQ(upperString, getUpperString(lowerString));
}
/*
TEST_F(EngineTest, HasTwoVowels) {
    string password = passwordEngine.generatePassword();
    const string vowels ("aeiouyAEIOUY");
    int nbVowels = countNbChar(password, vowels);
    EXPECT_EQ(nbVowels, 2);
}
*/