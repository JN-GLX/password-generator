#ifndef ENGINETEST_H
#define ENGINETEST_H

#include "gtest/gtest.h"
#include "../src/Engine/Engine.h"

using namespace std;

class EngineTest : public ::testing::Test {
    protected:
        void SetUp() override {

        }
        Engine passwordEngine;
};
#endif
