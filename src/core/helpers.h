#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <algorithm>
#include <iostream>

//const int DEFAULT_MINIMUM_PASSWORD_LENGTH = 6;

void displayMessageErrorLength(int minimalPasswordLength);
void displayHelp(char *progName);
int askForPasswordLength(int minimalPasswordLength);
bool checkPasswordLength(int pwdLength, int minimalPwdLength);

#endif
