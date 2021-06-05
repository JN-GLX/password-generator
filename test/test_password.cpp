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
 * @brief Initialisation du test
 * Fonction appelée avant chaque test
 */
void TestFixture::setUp() {
    
}

void TestFixture::tearDown() {

}

/**
 * @brief Teste que le mot de passe créé 
 * fait bien la longueur minimale par défaut (has_min_length_PWD)
 * 
 */
void TestFixture::test_has_min_length() {
    string password = pwd.createBasePwd();

    CPPUNIT_ASSERT(password.length() == pwd.has_min_length_PWD);   
}

/**
 * @brief Teste que le mot de passe généré est bien 
 * de la longueur demandée
 * 
 */
void TestFixture::test_has_given_length(){
    int pwdLength = 15;
    string password = pwd.generatePwd(pwdLength);

    CPPUNIT_ASSERT(pwdLength == password.length());    
}

/**
 * @brief Teste la présence de deux voyelles dans un mot de passe de 9 caractères.
 * 
 */
void TestFixture::test_has_two_vowels() {
    string password = pwd.createBasePwd();
    const string vowels ("aeiouyAEIOUY");
    
    int nbVowels = countNbChar(password, vowels);
    CPPUNIT_ASSERT_EQUAL(2, nbVowels);
}

/**
 * @brief Teste la présence de 4 consonnes dans un mot de passe de 9 caractères.
 * 
 */
void TestFixture::test_has_four_consonants() {
    string password = pwd.createBasePwd();
    const string consonants = "bcdfghjklmnpqrstvwzxBCDFGHJKLMNPQRSTVWZX";

    int nbConsonants = countNbChar(password, consonants);
    CPPUNIT_ASSERT_EQUAL(4, nbConsonants);
}

/**
 * @brief Teste la présence d'un chiffre dans un mot de passe de 9 caractères.
 * 
 */
void TestFixture::test_has_digit() {
    string password = pwd.createBasePwd();
    const string digits ("0123456789");

    int nbDigits = countNbChar(password, digits);
    CPPUNIT_ASSERT_EQUAL(1, nbDigits);
}

void TestFixture::test_has_two_specials() {
    string password = pwd.createBasePwd();
    const string specials (".,?;:!_-()[]={}#+&*%@$<>");

    int nbSpecials = countNbChar(password, specials);
    CPPUNIT_ASSERT_EQUAL(2, nbSpecials);
}

CppUnit::TestSuite *make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
    cout << "=============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "=============================================" << endl;

    TEST_ADD(has_min_length);
    TEST_ADD(has_given_length);  
    TEST_ADD(has_two_vowels);
    TEST_ADD(has_four_consonants);
    TEST_ADD(has_digit);
    TEST_ADD(has_two_specials);

    return suite;
}

int main(int argc, char *argv[]) {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::XmlOutputter *xml_outputter = NULL;

    CppUnit::TestSuite *suite = make_suite();
    runner.addTest(suite);

    runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), cout));
    
    // Exécute tous les tests
    runner.run();

    ofstream xml_out(OUTPUT_XML_FILE);
    xml_outputter = new CppUnit::XmlOutputter(&runner.result(), xml_out);
    xml_outputter->write();
    xml_out.close();

}