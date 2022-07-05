#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "UserMenager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes
{
    const string FILE_NAME_WITH_USERS="Incomes.xml";
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    UserMenager userMenager;
    AuxiliaryMethods auxiliaryMethods;

    void getIncomeData();
    Income getNewIncomeData();

public:
    FileWithIncomes
        {
        //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        LOGGED_IN_USER_ID=userMenager.getLoggedInUserId();
        };
        void addIncome();
};
#endif
