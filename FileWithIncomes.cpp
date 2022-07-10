
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

    //adresat.ustawId( (plikZAdresatami.pobierzIdOstatniegoAdresata()+1) );
    income.setUserId(LOGGED_IN_USER_ID);
    income.setIncomeId(1);

    string date;
    cout << "Czy przychod z dnia dzisiejszego:";
    cout << endl << "Wcisnij 't' jesli tak, wcisnij 'n' jesli data jest inna: ";
            sign = auxiliaryMethods.loadChar();
           if (sign == 't')
            {
                cout<<"Dzisiejsza data to: ";
                date=dates.getTimeStr();
                cout<<date<<endl;
            }
            if(sign=='n')
            {
                cout<<"Podaj date: "; // jak sprawdzić czy data jest dobrze wpisana??
                date = auxiliaryMethods.loadLine()+'-';
            }
            income.setDate(date);

    string item;
    cout << "Podaj rodzaj przychodu: ";
    item = auxiliaryMethods.loadLine();
    income.setItem(item);// czy zamieniac pierwsza litere na duza?

    cout << "Podaj wartosc: ";
     income.setAmount(auxiliaryMethods.loadLine()); //zmiana wartosci na z kropką
    return income;
}

unsigned int FileWithIncomes::convertDateToInteger(string date)
{
    AuxiliaryMethods auxiliaryMethods;
    unsigned int dateInt;
    int  year, month, day;
    string singlePartDate = "";
    int numberSinglePartDate = 1;

    for (int signPosition = 0; signPosition < date.length(); signPosition++)
    {
        if (date[signPosition] != '-')
        {
            singlePartDate += date[signPosition];
        }
         else
        {
            switch(numberSinglePartDate)
            {
            case 1:
                {
                year=auxiliaryMethods.convertStringToInteger(singlePartDate);
                break;
                }

            case 2:
                {
                month=auxiliaryMethods.convertStringToInteger(singlePartDate);
                break;
                }
            case 3:
                {
                day=auxiliaryMethods.convertStringToInteger(singlePartDate);
                break;
                }
            }
            singlePartDate = "";
            numberSinglePartDate++;
        }
    }
    dateInt=year*10000+month*100+day;
    return dateInt;
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
        xml.AddElem("IncomeId", income.getIncomeId());
        xml.AddElem("UserId", income.getUserId());
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
        xml.AddElem("IncomeId", income.getIncomeId());
        xml.AddElem("UserId", income.getUserId());
        xml.AddElem("Date", income.getDate());
        xml.AddElem("Item", income.getItem());
        xml.AddElem("Amount", income.getAmount());

        xml.Save(FILE_NAME_WITH_INCOMES);
        return true;
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << FILE_NAME_WITH_INCOMES << " i zapisac w nim danych." << endl;
        return false;
}
