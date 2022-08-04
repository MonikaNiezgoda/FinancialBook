#include "Balance.h"

void Balance::showAllCurrentMonth(vector<Income> incomes)
{
    Income income;
    currentMonth=dates.separateMonthFromDateInt(dates.getTodayDateInt());
    currentYear=dates.separateYearFromDateInt(dates.getTodayDateInt());
    startDay=currentYear*10000+currentMonth*100+0;
    endDay=currentYear*10000+currentMonth*100+dates.getDaysAMonth(currentMonth,dates.getTodayDateInt());


    system("cls");
    if (!incomes.empty())
    {
sort(incomes.begin(), incomes.end(),income.CompareByDate);
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {

            showIncomeData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Spis przychodow jest pusty." << endl << endl;
    }
    system("pause");

}

void Balance::showIncomeData(Income income)
{
    if (dates.convertDateToInteger(income.getDate())<endDay && dates.convertDateToInteger(income.getDate())>startDay)
    {
    cout << "Data:               " << income.getDate() << endl;
    cout << "Przychod:           " << income.getItem() << endl;
    cout << "Wartosc:     " << income.getAmount() << endl;
    cout<<endl;
    }
}
