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
    int currentYear, currentMonth, endDay, startDay, previousMonth;
    int sumIncomes, sumExpenses, balance;
    int showIncomeData(Income income);
    int showExpenseData(Expense expense);
    Dates dates;
    AuxiliaryMethods auxiliaryMethods;

public:
    Balance()
    {
        sumExpenses=0;
        sumIncomes=0;
    }

    void showAllIncomes(vector<Income> incomes);
    int showAllIncomesCurrentMonth(vector<Income> incomes);
    int showAllIncomesPreviousMonth(vector<Income> incomes);
    int showAllExpensesCurrentMonth(vector<Expense> expenses);
    int showAllExpensesPreviousMonth(vector<Expense> expenses);
    int showAllIncomesChosenDates(vector<Income> incomes, int startDay,int endDay);
    int showAllExpensesChosenDates(vector<Expense> expenses, int startDate,int endDate);

};

#endif
