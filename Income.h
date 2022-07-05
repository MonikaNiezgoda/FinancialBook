#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    unsigned int date;
    string item;
    double amount;

public:
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(unsigned int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getIncomeId();
    int getUserId();
    unsigned int getDate();
    string getItem();
    double getAmount();
};
#endif
