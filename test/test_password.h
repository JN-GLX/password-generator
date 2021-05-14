#ifndef TEST_PASSWORD_H
#define TEST_PASSWORD_H

#include "cppunit/TestCase.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestSuite.h"
#include "cppunit/CompilerOutputter.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/ui/text/TestRunner.h"

#include "../src/Password/Password.h"
using namespace std;

#define CLASS_NAME Password;
#define CLASS_NAME_STRING "Password"
#define OUTPUT_XML_FILE "output.xml"

#define TEST_DECL(x) void test_##x()
#define TEST_ADD(name) \
    suite->addTest(new CppUnit::TestCaller<TestFixture>("test_"#name, \
        &TestFixture::test_##name));

class TestFixture : public CppUnit::TestFixture {
private:
    Password pwd;

public:
    void setUp();
    void tearDown();

    TEST_DECL(min_length);
//    TEST_DECL(generate_length);
//    TEST_DECL(two_vowels);
//    TEST_DECL(four_consonants);
//    TEST_DECL(has_digit);
//    TEST_DECL(has_two_specials);

};

#endif /* TEST_PASSWORD_H */