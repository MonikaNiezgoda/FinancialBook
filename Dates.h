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
    string getTimeStr();
    string todayDate;
    int todayDateInt;
    int separateMonthFromDateInt(int dateInt);
    int separateDaysFromDateInt(int dateInt);
    int getDaysAMonth(int monthInt, int dateInt);
    bool ifLeapYear(int dateInt);
public:
    Dates ();
    bool checkDateFormat (string date);
    int convertDateToInteger(string date);
    bool checkStartDate (string date);
    bool checkMonthDate (string date);
    string getTodayDate();
    bool checkDayMonth(string date);

};

#endif
