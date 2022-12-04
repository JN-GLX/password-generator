#ifndef APPLICATIONTEST_H
#define APPLICATIONTEST_H

#include "gtest/gtest.h"
#include "../src/core/helpers.h"
#include "../src/core/application.h"
#include "../src/Password/Password.h"
#include "../src/Engine/Engine.h"
#include "../src/Engine/randomutils.h"

class ApplicationTest : public ::testing::Test {
  protected:
    void SetUp() override {
        app.setPasswordLength(Password::MINIMUM_PASSWORD_LENGTH);
        app.initializeGenerator();
    }
    Application app;
};
#endif
