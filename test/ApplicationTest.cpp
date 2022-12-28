#include "ApplicationTest.h"

TEST_F(ApplicationTest, NumberOfPasswords) {
    int numberPwd = 10;
    app.setNumberOfPasswords(numberPwd);
    app.runGenerator();
    std::vector<std::string> passwordsList = app.getPasswordsList();
    EXPECT_EQ(passwordsList.size(), numberPwd);
}

TEST_F(ApplicationTest, LengthOfPassword) {
    int passwordLength = 15;
    app.setPasswordLength(passwordLength);
    app.setNumberOfPasswords(1);
    app.runGenerator();
    std::vector<std::string> passwordsList = app.getPasswordsList();
    EXPECT_EQ(passwordsList[0].length(), passwordLength);
}

TEST_F(ApplicationTest, SelectedEngine) {
    char shortEngineName = 'A';
    app.selectPasswordEngineFromOptArgs(shortEngineName);
    EXPECT_EQ(app.getPasswordEngine(), EngineName::Alphanumerique);
}