#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class AuxiliaryMethods
{
public:
    static string loadLine();
    static char loadChar();
    static int convertStringToInteger(string number);
    static string konwerjsaIntNaString(int numer);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
};

#endif
