#include "FinancialBook.h"

void FinancialBook::registerUser()
{
    userMenager.registerUser();
}

void FinancialBook::loginUser()
{
    userMenager.setLoggedInUserId(userMenager.loginUser());

    if(userMenager.isUserLoggedIn())
    {
        fileWithIncomes = new FileWithIncomes(FILE_NAME_WITH_INCOMES, userMenager.getLoggedInUserId());
        fileWithExpenses = new FileWithExpenses(FILE_NAME_WITH_EXPENSES, userMenager.getLoggedInUserId());
    }
}

bool FinancialBook::isUserLoggedIn()
{
    userMenager.isUserLoggedIn();
}

char FinancialBook::selectOptionFromMainMenu()
{
    AuxiliaryMethods auxiliaryMethods;
    char select;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = auxiliaryMethods.loadChar();

    return select;
}

void FinancialBook::addIncome()
{
    if(userMenager.isUserLoggedIn())
    {
        fileWithIncomes->addIncome();
    }
    else
    {
        cout<<"Aby dodac przychod, nalezy sie najpierw zalogowac"<< endl;
        system("pause");
    }
}

/*void FinancialBook::showAllIncomes()
{
    fileWithIncomes->showAllIncomes();
}*/

void FinancialBook::showAllUsers()
{
    userMenager.showAllUsers();
}


char FinancialBook::selectOptionFromUserMenu()
{
    AuxiliaryMethods auxiliaryMethods;
    char select;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = auxiliaryMethods.loadChar();

    return select;
}

void FinancialBook::addExpense()
{
    if(userMenager.isUserLoggedIn())
    {
        fileWithExpenses->addExpense();
    }
    else
    {
        cout<<"Aby dodac przychod, nalezy sie najpierw zalogowac"<< endl;
        system("pause");
    }
}

void FinancialBook::showAllCurrentMonth()
{

    fileWithIncomes->showAllIncomesCurrentMonth();
    fileWithExpenses->showAllExpensesCurrentMonth();
    system("cls");
    cout<<"Bilans w biezacym miesiacu to: "<<fileWithIncomes->getSumIncomes()-fileWithExpenses->getSumExpenses()<<endl;
    system("pause");
}

void FinancialBook::showAllPreviousMonth()
{
    fileWithIncomes->showAllIncomesPreviousMonth();
    fileWithExpenses->showAllExpensesPreviousMonth();
    system("cls");

    cout<<"Bilans w poprzednim miesiacu to: "<<setprecision(2) << fixed <<fileWithIncomes->getSumIncomes()-fileWithExpenses->getSumExpenses()<<endl;
    system("pause");
}

void FinancialBook::showAllChosenDates()
{
    Dates dates;
    system("cls");
    int startDate=dates.getStartDate();
    int endDate=dates.getEndDate();
    if(startDate<endDate)
    {
    fileWithIncomes->showAllIncomesChosenDates(startDate, endDate);
    fileWithExpenses->showAllExpensesChosenDates(startDate, endDate);
    system("cls");
    cout<<"Bilans w wybranym czasie to: "<<double(fileWithIncomes->getSumIncomes()-fileWithExpenses->getSumExpenses())<<endl;
    }
    else
    {
    cout<<"Data poczatkowa jest pozniejsza niz koncowa"<<endl;
    system("pause");
    }
}

void FinancialBook::logoutUser()
{
   userMenager.logoutUser();
}

void FinancialBook::changePassword()
{
    userMenager.changePassword();
}
