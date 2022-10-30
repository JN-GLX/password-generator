#ifndef ENGINETEST_H
#define ENGINETEST_H

#include "gtest/gtest.h"
#include "../src/Engine/Engine.h"
#include "../src/Engine/randomutils.h"
#include "../src/core/helpers.h"

const int MINIMAL_PASSWORD_LENGTH = 9;

class StandardEngineTest : public ::testing::Test {
    protected:
        void SetUp() override {
            password = passwordEngine.generatePassword(MINIMAL_PASSWORD_LENGTH);
        }
        StandardEngine passwordEngine;
        std::string password;
};

class AlphaNumEngineTest : public ::testing::Test 
{
    protected:
        void SetUp() override 
        {
            password = alphanumPasswordEngine.generatePassword(MINIMAL_PASSWORD_LENGTH);
        }
        AlphaNumEngine alphanumPasswordEngine;
        std::string password;
};
#endif
