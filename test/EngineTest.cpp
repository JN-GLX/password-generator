#include <algorithm>
#include "EngineTest.h"

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

TEST_F(EngineTest, HasTwoVowels) {
    string password = passwordEngine.generatePassword();
    const string vowels ("aeiouyAEIOUY");
    int nbVowels = countNbChar(password, vowels);
    EXPECT_EQ(nbVowels, 2);
}