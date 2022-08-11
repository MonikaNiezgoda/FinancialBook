#ifndef FINANCIALBOOK_H
#define FINANCIALBOOK_H

#include <iostream>
#include <vector>

#include "UserMenager.h"
#include "AuxiliaryMethods.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Balance.h"


using namespace std;

class FinancialBook

{
    UserMenager userMenager;
    FileWithIncomes *fileWithIncomes;
    const string FILE_NAME_WITH_INCOMES;
    FileWithExpenses *fileWithExpenses;
    const string FILE_NAME_WITH_EXPENSES;
    Balance balance;


public:
     FinancialBook(string fileNameWithIncomes, string fileNameWithExpenses) :
    FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
    {
        fileWithIncomes = NULL;
        fileWithExpenses = NULL;
    };
    ~FinancialBook()
    {
        delete fileWithIncomes;
        fileWithIncomes = NULL;
        delete fileWithExpenses;
        fileWithExpenses = NULL;
    }

    void registerUser();
    void showAllUsers();
    void loginUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    void addIncome();
    void addExpense();
    void showAllIncomes();
    char selectOptionFromUserMenu();
    void showAllCurrentMonth();
    void showAllPreviousMonth();
    void showAllChosenDates();
    void logoutUser();
    void changePassword();
};

#endif
