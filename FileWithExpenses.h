#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Dates.h"

using namespace std;

class FileWithExpenses
{
    const string FILE_NAME_WITH_EXPENSES;
    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    int lastExpenseId;
    AuxiliaryMethods auxiliaryMethods;
    Dates dates;

    void getExpenseData();
    Expense getNewExpenseData();
    unsigned int convertDateToInteger(string date);
    bool addExpenseToFile(Expense income);
    vector <Expense> loadExpensesLoggedInUser(int loggedInUserId);
    void showExpenseData(Expense income);

public:
  FileWithExpenses (string fileNameWithExpenses, int loggedInUserId) : FILE_NAME_WITH_EXPENSES(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
        {
        expenses = loadExpensesLoggedInUser(LOGGED_IN_USER_ID);
        };
        void addExpense();
        void showAllExpenses();
};
#endif