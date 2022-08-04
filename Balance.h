#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Income.h"
#include "Dates.h"


class Balance
{
    //vector <Income> incomes;
    void showIncomeData(Income income);
    Dates dates;
    int currentYear, currentMonth, endDay, startDay;
   // FileWithIncomes fileWithIncomes;

public:
    void showAllIncomes(vector<Income> incomes);
    void showAllCurrentMonth(vector<Income> incomes);
};

#endif
