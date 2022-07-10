#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
//#include <algorithm>
#include <sstream>
//#include <cstdlib>

#include "Income.h"
//#include "UserMenager.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Dates.h"

using namespace std;

class FileWithIncomes
{
    const string FILE_NAME_WITH_INCOMES;
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    //UserMenager userMenager;
    AuxiliaryMethods auxiliaryMethods;
    Dates dates;

    void getIncomeData();
    Income getNewIncomeData();
    unsigned int convertDateToInteger(string date);
    bool addIncomeToFile(Income income);
    vector <Income> loadIncomesLoggedInUser(int loggedInUserId);

public:
  FileWithIncomes (string fileNameWithIncomes, int loggedInUserId) : FILE_NAME_WITH_INCOMES(fileNameWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
        {
        incomes = loadIncomesLoggedInUser(LOGGED_IN_USER_ID);
        };
        void addIncome();
};
#endif
