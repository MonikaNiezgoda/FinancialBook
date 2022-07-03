#include <iostream>

#include "FinancialBook.h"

using namespace std;

int main()
{
    FinancialBook financialBook;
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
    }
    return 0;
}
