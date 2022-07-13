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
