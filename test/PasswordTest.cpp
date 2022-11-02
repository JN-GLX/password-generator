/*
 * Password_test.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "PasswordTest.h"

using namespace std;

TEST_F(PasswordTest, IsLengthCorrect) {
    int pwdLength = 15;
    pwd.setPasswordLength(pwdLength);

    EXPECT_EQ(pwdLength, pwd.getPasswordLength());
}

TEST_F(PasswordTest, SetPasswordEngine) {
    pwd.setPasswordEngine(EngineName::Alphanumerique);

    EXPECT_EQ(pwd.getPasswordEngine(), EngineName::Alphanumerique);
}

TEST_F(PasswordTest, GetPassword) {
    pwd.generatePasswordWithEngine();
    string password = pwd.getPassword();

    EXPECT_GE(password.length(), 0);
}

TEST_F(PasswordTest, HasGivenLength) {
    int pwdLength = 15;
    pwd.setPasswordLength(pwdLength);
    pwd.generatePasswordWithEngine();
    string password = pwd.getPassword();

    EXPECT_EQ(password.length(), pwdLength);
}

TEST_F(PasswordTest, TwoPasswordsAreDifferent) {
    pwd.generatePasswordWithEngine();
    string firstPassword = pwd.getPassword();
    pwd.generatePasswordWithEngine();
    string secondPassword = pwd.getPassword();

    EXPECT_NE(firstPassword, secondPassword);
}