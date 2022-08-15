
#include "FileWithIncomes.h"

void FileWithIncomes::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    if (addIncomeToFile(income)) // dopisaæ do pliku z przychodami
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu."<< endl;
    system("pause");
}

Income FileWithIncomes::getNewIncomeData()
{
    Income income;
    char sign;

    income.setIncomeId(lastIncomeId+1);
    lastIncomeId=income.getIncomeId();
    income.setUserId(LOGGED_IN_USER_ID);

    string date;
    cout << "Czy przychod z dnia dzisiejszego:";
    cout << endl << "Wcisnij 't' jesli tak, wcisnij 'n' jesli data jest inna: ";
    sign = AuxiliaryMethods::loadChar();
    if (sign == 't')
    {
        cout<<"Dzisiejsza data to: ";
        date=dates.getTodayDate();
        cout<<date<<endl;
    }
    if(sign=='n')
    {
        cout<<"Podaj date: ";
        date = AuxiliaryMethods::loadLine();
        while (!dates.checkDateFormat(date))
        {
            cout<<"Wpisz jeszcze raz date w poprawnym formacie rrrr-mm-dd: ";
            date=AuxiliaryMethods::loadLine();
        }
        while(!dates.checkStartDate(date))
        {
            cout<<"Data musi byc pozniejsza niz 2000-01-01. Wpisz date ponownie: ";
            date=AuxiliaryMethods::loadLine();
        }
        while(!dates.checkDayMonth(date) || !dates.checkMonthDate(date))
        {
            cout<<"Wpisz date ponownie: ";
            date=AuxiliaryMethods::loadLine();
        }
    }
    income.setDate(date);

    string item;
    cout << "Podaj rodzaj przychodu: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(item));// czy zamieniac pierwsza litere na duza?

    cout << "Podaj wartosc: ";
    income.setAmount(AuxiliaryMethods::checkDotsInAmount(AuxiliaryMethods::loadLine()));
    return income;
}


bool FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME_WITH_INCOMES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("UserId", income.getUserId());
        xml.AddElem("IncomeId", income.getIncomeId());
        xml.AddElem("Date", income.getDate());
        xml.AddElem("Item", income.getItem());
        xml.AddElem("Amount", income.getAmount());

        xml.Save(FILE_NAME_WITH_INCOMES);
        return true;
    }
    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("UserId", income.getUserId());
        xml.AddElem("IncomeId", income.getIncomeId());
        xml.AddElem("Date", income.getDate());
        xml.AddElem("Item", income.getItem());
        xml.AddElem("Amount", income.getAmount());

        xml.Save(FILE_NAME_WITH_INCOMES);
        return true;
    }
    else
    return false;
}

vector <Income> FileWithIncomes::loadIncomesLoggedInUser(int loggedInUserId)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    xml.Load(FILE_NAME_WITH_INCOMES);
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("Income"))
    {
        xml.IntoElem();

        if(xml.FindElem("UserId"))
        {
            while(LOGGED_IN_USER_ID==AuxiliaryMethods::convertStringToInteger(xml.GetData()))
            {
                income.setUserId(atoi(xml.GetData().c_str()));   //atoi(pojedynczaDanaUzytkownika.c_str())
                if(xml.FindElem("IncomeId"))
                {
                    income.setIncomeId(atoi(xml.GetData().c_str()));
                }
                if(xml.FindElem("Date"))
                {
                    income.setDate(xml.GetData());
                }
                if(xml.FindElem("Item"))
                {
                    income.setItem(xml.GetData());
                }
                if(xml.FindElem("Amount"))
                {
                    income.setAmount(xml.GetData());
                }
                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
    }
    lastIncomeId=incomes.size();

    return incomes;
}

void FileWithIncomes::showAllIncomesCurrentMonth()
{
    sumIncomes=balance.showAllIncomesCurrentMonth(incomes);
}


void FileWithIncomes::showAllIncomesPreviousMonth()
{
    sumIncomes=balance.showAllIncomesPreviousMonth(incomes);
}

void FileWithIncomes::showAllIncomesChosenDates(int startDate,int endDate)
{
    sumIncomes=balance.showAllIncomesChosenDates(incomes, startDate, endDate);
}

int FileWithIncomes::getSumIncomes()
{
    return sumIncomes;
}

