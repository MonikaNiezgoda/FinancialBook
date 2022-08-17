#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

#include "Income.h"
#include "Dates.h"
#include "Expense.h"


class Balance
{
    int currentYear, currentMonth, endDay, startDay, previousMonth;
    float sumIncomes, sumExpenses, balance;
    float showIncomeData(Income income);
    float showExpenseData(Expense expense);
    Dates dates;

public:

    void showAllIncomes(vector<Income> incomes);
    float showAllIncomesCurrentMonth(vector<Income> incomes);
    float showAllIncomesPreviousMonth(vector<Income> incomes);
    float showAllExpensesCurrentMonth(vector<Expense> expenses);
    float showAllExpensesPreviousMonth(vector<Expense> expenses);
    float showAllIncomesChosenDates(vector<Income> incomes, int startDay,int endDay);
    float showAllExpensesChosenDates(vector<Expense> expenses, int startDate,int endDate);
    float getSumIncomes();

};

#endif
