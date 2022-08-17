#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Dates.h"
#include "Balance.h"

using namespace std;

class FileWithIncomes
{
    const string FILE_NAME_WITH_INCOMES;
    const int LOGGED_IN_USER_ID;
    int lastIncomeId;
    float sumIncomes;
    void getIncomeData();
    Income getNewIncomeData();
    bool addIncomeToFile(Income income);
    vector <Income> loadIncomesLoggedInUser(int loggedInUserId);
    void showIncomeData(Income income);
    Dates dates;
    Balance balance;


public:
  FileWithIncomes (string fileNameWithIncomes, int loggedInUserId) : FILE_NAME_WITH_INCOMES(fileNameWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
        {
        incomes = loadIncomesLoggedInUser(LOGGED_IN_USER_ID);
        };
        vector <Income> incomes;
        void addIncome();
        void showAllIncomes();
        void showAllIncomesCurrentMonth();
        void showAllIncomesPreviousMonth();
        void showAllIncomesChosenDates(int startDate,int endDate);
        float getSumIncomes();
};
#endif
