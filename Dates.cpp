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
    AuxiliaryMethods auxiliaryMethods;
    unsigned int dateInt;
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
