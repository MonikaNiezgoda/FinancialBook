#include "Dates.h"

string Dates::getTimeStr(){
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    string s(30, '\0');
    strftime(&s[0], s.size(), "%Y-%m-%d", localtime(&now));
    return s;
}


bool Dates::checkDateFormat (string date)
{
    if (date[4]!='-' || date[7]!='-' || date.length()!=10)
    {
        cout<<"Niepoprawny format daty"<<endl;
        return false;
    }
    else
    {
        return true;
    }
}

int Dates::convertDateToInteger(string date)
{
    date= date+'-';
    AuxiliaryMethods auxiliaryMethods;
    int dateInt;
    int  year, month, day;
    string singlePartDate = "";
    int numberSinglePartDate = 1;

    for (int signPosition = 0; signPosition < date.length(); signPosition++)
    {
        if (date[signPosition] != '-')
        {
            singlePartDate += date[signPosition];
        }
        else
        {
            switch(numberSinglePartDate)
            {
            case 1:
            {
                year=auxiliaryMethods.convertStringToInteger(singlePartDate);
                break;
            }
            case 2:
            {
                month=auxiliaryMethods.convertStringToInteger(singlePartDate);
                break;
            }
            case 3:
            {
                day=auxiliaryMethods.convertStringToInteger(singlePartDate);
                break;
            }
            }
            singlePartDate = "";
            numberSinglePartDate++;
        }
    }
    dateInt=year*10000+month*100+day;
    return dateInt;
}

bool Dates::checkStartDate (string date)
{
    int dateInt;
    dateInt=convertDateToInteger(date+'-');
    if (dateInt<20000101)
    {
        cout<<"Niepoprawna data"<<endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool Dates::checkMonthDate (string date)
{
    int dateInt, loadMonth, todayMonth;
    dateInt=convertDateToInteger(date+'-');
    loadMonth=separateMonthFromDateInt(dateInt);
    todayMonth=separateMonthFromDateInt(todayDateInt);

    if(loadMonth<0 || loadMonth>12 || loadMonth>todayMonth)
    {
        cout<<"Niepoprawna data"<<endl;
        return false;
    }
    else
        return true;
}

int Dates::separateMonthFromDateInt(int dateInt)
{
    int monthInt = (dateInt%10000)/100;
    return monthInt;
}

int Dates::separateDaysFromDateInt(int dateInt)
{
    int loadDays;
    loadDays=dateInt%100;
    return loadDays;
}

int Dates::separateYearFromDateInt(int dateInt)
{
    int year= dateInt/10000;
    return year;
}


string Dates::getTodayDate()
{
    return todayDate;
}

int Dates::getTodayDateInt()
{
    return todayDateInt;
}

bool Dates::ifLeapYear(int dateInt)
{
    int year =separateYearFromDateInt(dateInt);
   if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    return true;
   else
    return false;
}

int Dates::getDaysAMonth(int monthInt, int dateInt)
{
int daysMonth;
if(monthInt%2==0)
{
    if(monthInt==2)
    {
        if (ifLeapYear(dateInt))
            daysMonth=29;
        else
            daysMonth=28;
    }
    else
    {
        daysMonth=30;
    }
}
else
    daysMonth=31;

    return daysMonth;
}

bool Dates::checkDayMonth(string date)
{
    int dateInt, loadDays, loadMonth, daysMonth;
    dateInt=convertDateToInteger(date+'-');
    loadDays=separateDaysFromDateInt(dateInt);
    loadMonth=separateMonthFromDateInt(dateInt);
    daysMonth=getDaysAMonth(loadMonth, dateInt);
    if (loadDays>daysMonth)
    {
        cout<<"Niepoprawna data"<<endl;
        return false;
    }
    else
        return true;
}


