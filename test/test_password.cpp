/*
 * Password_test.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "test_password.h"
using namespace std;

/**
 * @brief Initialisation du test
 * Fonction appelée avant chaque test
 */
void TestFixture::setUp() {
    
}

void TestFixture::tearDown() {

}

void TestFixture::test_min_length() {
    string password = pwd.createBasePwd();

    CPPUNIT_ASSERT(password.length() == pwd.MIN_LENGTH_PWD);   
}

CppUnit::TestSuite *make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
    cout << "=============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "=============================================" << endl;

    TEST_ADD(min_length);

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