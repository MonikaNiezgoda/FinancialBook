#include <iostream>

#include "FinancialBook.h"

using namespace std;

int main()
{
    FinancialBook financialBook("Incomes.xml", "Expenses.xml");
    char select;
    while (true)
    {
        if (!financialBook.isUserLoggedIn())
        {
            select = financialBook.selectOptionFromMainMenu();

            switch (select)
            {
            case '1':
                financialBook.registerUser();
                break;
            case '2':
                financialBook.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
            else
        {
            select = financialBook.selectOptionFromUserMenu();
            switch (select)
            {
            case '1':
                financialBook.addIncome();
                break;
            case '2':
                financialBook.addExpense();
                break;
            case '3':
                financialBook.showAllCurrentMonth();
                break;
            case '4':
                financialBook.showAllPreviousMonth();
                break;
            case '5':
                financialBook.showAllChosenDates();
                break;
            }
        }
    }
    return 0;
}
