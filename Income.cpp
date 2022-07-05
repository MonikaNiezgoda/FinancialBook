#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId >= 0)
    incomeId = newIncomeId;
}

void Income::setUserId(int newUserId)
{
    userId=newUserId;
}
void Income::setDate(unsigned int newDate)
{
    date=newDate;
}
void Income::setItem(string newItem)
{
    item=newItem;
}
void Income::setAmount(double newAmount)
{
    amount = newAmount;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}

unsigned int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}
double Income::getAmount()
{
    return amount;
}

