#ifndef PASSWORDTEST_H
#define PASSWORDTEST_H

#include "gtest/gtest.h"
#include "../src/Password/Password.h"
#include "../src/Engine/Engine.h"
#include "../src/Engine/randomutils.h"
#include "../src/Engine/stringutils.h"

using namespace std;

class PasswordTest : public ::testing::Test {
  protected:
    void SetUp() override {
        pwd.setPasswordEngine(EngineName::Standard);
        pwd.setPasswordLength(DEFAULT_MINIMUM_PASSWORD_LENGTH);
    }
    Password pwd;
};
#endif /* PASSWORDTEST_H */