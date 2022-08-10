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

int Balance::showAllIncomesChosenDates(vector<Income> incomes, int startDate,int endDate)
{
    Income income;
    startDay=startDate;
    endDay=endDate;
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

int Balance::showAllExpensesChosenDates(vector<Expense> expenses, int startDate,int endDate)
{
    Expense expense;
    startDay=startDate;
    endDay=endDate;
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
