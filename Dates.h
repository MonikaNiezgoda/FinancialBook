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
    int separateDaysFromDateInt(int dateInt);
    bool ifLeapYear(int dateInt);

public:
    Dates()
    {
        todayDate=getTimeStr();
        todayDateInt=convertDateToInteger(todayDate+'-');
    }
    bool checkDateFormat (string date);
    int convertDateToInteger(string date);
    bool checkStartDate (string date);
    bool checkMonthDate (string date);
    string getTodayDate();
    int getTodayDateInt();
    bool checkDayMonth(string date);
    int separateYearFromDateInt(int dateInt);
    int separateMonthFromDateInt(int dateInt);
    int getDaysAMonth(int monthInt, int dateInt);
    int checkDateString(string date);
    int getStartDate();
    int getEndDate();
};

#endif
