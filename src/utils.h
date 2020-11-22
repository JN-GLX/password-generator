#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

int askForPasswdLength();

void displayHelp(char *progName);

bool checkPwdLength(int pwdLength);

#endif // UTILS_H_INCLUDED
