#ifndef ENGINETEST_H
#define ENGINETEST_H

#include "gtest/gtest.h"
#include "../src/Engine/Engine.h"

using namespace std;

const string VOWELS ("aeiouyAEIOUY");
const string CONSONANTS ("bcdfghjklmnpqrstvwzxBCDFGHJKLMNPQRSTVWZX");
const string DIGITS ("0123456789");
const int MINIMAL_PASSWORD_LENGTH = 9;


class EngineTest : public ::testing::Test {
    protected:
        void SetUp() override {
            password = passwordEngine.generatePassword(MINIMAL_PASSWORD_LENGTH);
        }
        Engine passwordEngine;
        string password;
};
#endif
