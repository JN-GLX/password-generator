#ifndef PASSWORDTEST_H
#define PASSWORDTEST_H

#include "gtest/gtest.h"
#include "../src/Password/Password.h"

using namespace std;

class PasswordTest : public ::testing::Test {
  protected:
    void SetUp() override {
        
    }
    Password pwd;
};
#endif /* PASSWORDTEST_H */