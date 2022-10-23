#ifndef ENGINETEST_H
#define ENGINETEST_H

#include "gtest/gtest.h"
#include "../src/Engine/Engine.h"
#include "../src/Engine/randomutils.h"
#include "../src/core/helpers.h"

const int MINIMAL_PASSWORD_LENGTH = 9;

class EngineTest : public ::testing::Test {
    protected:
        void SetUp() override {
            password = passwordEngine.generatePassword(MINIMAL_PASSWORD_LENGTH);
        }
        Engine passwordEngine;
        std::string password;
};

#endif
