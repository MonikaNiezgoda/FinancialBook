#ifndef DATES_H
#define DATES_H
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Dates
{
public:
    string getTimeStr();
    bool checkDateFormat (string date);
};

#endif
