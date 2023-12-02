/*
 * Password_test.cpp
 *
 *  Created on: 21 nov. 2020
 *      Author: jean-noel
 */

#include "PasswordTest.h"

using namespace std;
using namespace StringUtils;

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