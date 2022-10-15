#ifndef TEST_PASSWORD_H
#define TEST_PASSWORD_H

#include "gtest/gtest.h"
#include "../src/Password/Password.h"

using namespace std;

class PasswordTest : public ::testing::Test {
  protected:
    void SetUp() override {
        
    }
    Password pwd;
};
#endif /* TEST_PASSWORD_H */