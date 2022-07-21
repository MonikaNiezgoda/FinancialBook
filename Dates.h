#ifndef DATES_H
#define DATES_H
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

#include "AuxiliaryMethods.h"

class Dates
{
public:
    string getTimeStr();
    bool checkDateFormat (string date);
    int convertDateToInteger(string date);
    bool checkStartDate (string date);
    bool checkMonthDate (string date);
    int separateMonthFromDateInt(int dateInt);
};

#endif
