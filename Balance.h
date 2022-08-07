#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Income.h"
#include "Dates.h"
#include "Expense.h"


class Balance
{
    Dates dates;
    int currentYear, currentMonth, endDay, startDay, previousMonth;
    void showIncomeData(Income income);
    void showExpenseData(Expense expense);

public:
    void showAllIncomes(vector<Income> incomes);
    void showAllIncomesCurrentMonth(vector<Income> incomes);
    void showAllIncomesPreviousMonth(vector<Income> incomes);
    void showAllExpensesCurrentMonth(vector<Expense> expenses);
};

#endif
