#include "Balance.h"

int Balance::showAllIncomesCurrentMonth(vector<Income> incomes)
{
    Income income;
    currentMonth=dates.separateMonthFromDateInt(dates.getTodayDateInt());
    currentYear=dates.separateYearFromDateInt(dates.getTodayDateInt());
    startDay=currentYear*10000+currentMonth*100+1;
    endDay=currentYear*10000+currentMonth*100+dates.getDaysAMonth(currentMonth,dates.getTodayDateInt());

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),income.CompareByDate);
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
             sumIncomes+=showIncomeData(*itr);
        }
        cout << endl;
        cout<<"Suma przychodow w biezacym miesiacu to: "<<sumIncomes<<endl<<endl;
        system("pause");
        return sumIncomes;
    }
    else
    {
        cout << endl << "Spis przychodow jest pusty." << endl << endl;
        system("pause");
        return 0;
    }
}

int Balance::showIncomeData(Income income)
{
    if (dates.convertDateToInteger(income.getDate())<endDay+1 && dates.convertDateToInteger(income.getDate())>startDay-1)
    {
        cout << "Data:               " << income.getDate() << endl;
        cout << "Przychod:           " << income.getItem() << endl;
        cout << "Wartosc:     " << income.getAmount() << endl;
        cout<<endl;
        return auxiliaryMethods.convertStringToInteger(income.getAmount());
    }
    else return 0;
}
int Balance::showExpenseData(Expense expense)
{
    if (dates.convertDateToInteger(expense.getDate())<endDay && dates.convertDateToInteger(expense.getDate())>startDay)
    {
        cout << "Data:               " << expense.getDate() << endl;
        cout << "Wydatek:           " << expense.getItem() << endl;
        cout << "Wartosc:     " << expense.getAmount() << endl;
        cout<<endl;
        return auxiliaryMethods.convertStringToInteger(expense.getAmount());
    }
    else return 0;
}

int Balance::showAllIncomesPreviousMonth(vector<Income> incomes)
{
    Income income;
    previousMonth=dates.separateMonthFromDateInt(dates.getTodayDateInt())-1;
    currentYear=dates.separateYearFromDateInt(dates.getTodayDateInt());
    startDay=currentYear*10000+previousMonth*100+0;
    endDay=currentYear*10000+previousMonth*100+dates.getDaysAMonth(previousMonth,dates.getTodayDateInt());

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),income.CompareByDate);
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            sumIncomes+=showIncomeData(*itr);
        }
        cout << endl;
        cout<<"Suma przychodow w poprzednim miesiacu to: "<<sumIncomes<<endl<<endl;
        system("pause");
        return sumIncomes;
    }
    else
    {
        cout << endl << "Spis przychodow jest pusty." << endl << endl;
        system("pause");
        return 0;
    }
}

int Balance::showAllExpensesCurrentMonth(vector<Expense> expenses)
{
    Expense expense;
    currentMonth=dates.separateMonthFromDateInt(dates.getTodayDateInt());
    currentYear=dates.separateYearFromDateInt(dates.getTodayDateInt());
    startDay=currentYear*10000+currentMonth*100+0;
    endDay=currentYear*10000+currentMonth*100+dates.getDaysAMonth(currentMonth,dates.getTodayDateInt());

    system("cls");
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),expense.CompareByDate);
        cout << "             >>> WYDATKI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            sumExpenses+=showExpenseData(*itr);
        }
        cout << endl;
        cout<<"Suma wydatkow w biezacym miesiacu to: "<<sumExpenses<<endl<<endl;
        system("pause");
        return sumExpenses;
    }
    else
    {
        cout << endl << "Spis wydatkow jest pusty." << endl << endl;
        system("pause");
        return 0;
    }
}


int Balance::showAllExpensesPreviousMonth(vector<Expense> expenses)
{
    Expense expense;
    previousMonth=dates.separateMonthFromDateInt(dates.getTodayDateInt())-1;
    currentYear=dates.separateYearFromDateInt(dates.getTodayDateInt());
    startDay=currentYear*10000+previousMonth*100+0;
    endDay=currentYear*10000+previousMonth*100+dates.getDaysAMonth(previousMonth,dates.getTodayDateInt());

    system("cls");
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),expense.CompareByDate);
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            sumExpenses+=showExpenseData(*itr);
        }
        cout << endl;
        cout<<"Suma wydatkow w poprzednim miesiacu to: "<<sumExpenses<<endl<<endl;
        system("pause");
        return sumExpenses;
    }
    else
    {
        cout << endl << "Spis wydatkow jest pusty." << endl << endl;
        system("pause");
        return 0;
    }
}

int Balance::showAllIncomesChosenDates(vector<Income> incomes)
{
    Income income;
    string startDate, endDate;
    cout<<"Podaj date poczatkowa: ";
    startDate = auxiliaryMethods.loadLine();
    startDay=dates.checkDateString(startDate);
       /* while (!dates.checkDateFormat(startDate))
        {
            cout<<"Wpisz jeszcze raz date w poprawnym formacie rrrr-mm-dd: ";
            startDate=auxiliaryMethods.loadLine();
        }
        while(!dates.checkStartDate(startDate))
        {
            cout<<"Data musi byc pozniejsza niz 2000-01-01. Wpisz date ponownie: ";
            startDate=auxiliaryMethods.loadLine();
        }
        while(!dates.checkDayMonth(startDate) || !dates.checkMonthDate(startDate))
        {
            cout<<"Wpisz date ponownie: ";
            startDate=auxiliaryMethods.loadLine();
        }
    startDay=dates.convertDateToInteger(startDate);*/
cout<<"Podaj date koncowa: ";
 endDate = auxiliaryMethods.loadLine();
        while (!dates.checkDateFormat(endDate))
        {
            cout<<"Wpisz jeszcze raz date w poprawnym formacie rrrr-mm-dd: ";
            endDate=auxiliaryMethods.loadLine();
        }
        while(!dates.checkStartDate(endDate))
        {
            cout<<"Data musi byc pozniejsza niz 2000-01-01. Wpisz date ponownie: ";
            endDate=auxiliaryMethods.loadLine();
        }
        while(!dates.checkDayMonth(endDate) || !dates.checkMonthDate(endDate))
        {
            cout<<"Wpisz date ponownie: ";
            endDate=auxiliaryMethods.loadLine();
        }
    endDay=dates.convertDateToInteger(endDate);
    cout<<endDay<<endl;
    system("pause");

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),income.CompareByDate);
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            sumIncomes+=showIncomeData(*itr);
        }
        cout << endl;
        cout<<"Suma przychodow w wybranym okresie to: "<<sumIncomes<<endl<<endl;
        system("pause");
        return sumIncomes;
    }
    else
    {
        cout << endl << "Spis przychodow jest pusty." << endl << endl;
        system("pause");
        return 0;
    }
}
