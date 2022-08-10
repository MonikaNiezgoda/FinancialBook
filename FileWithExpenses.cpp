
#include "FileWithExpenses.h"

void FileWithExpenses::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE WYDATKU <<<" << endl << endl;
    expense = getNewExpenseData();

    expenses.push_back(expense);
    if (addExpenseToFile(expense)) // dopisaæ do pliku z przychodami
        cout << "Nowy wydatek zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku."<< endl;
    system("pause");
}

Expense FileWithExpenses::getNewExpenseData()
{
    Expense expense;
    char sign;
    int dateInt;

    expense.setExpenseId(lastExpenseId+1);
    lastExpenseId=expense.getExpenseId();
    expense.setUserId(LOGGED_IN_USER_ID);

    string date;
    cout << "Czy przychod z dnia dzisiejszego:";
    cout << endl << "Wcisnij 't' jesli tak, wcisnij 'n' jesli data jest inna: ";
    sign = auxiliaryMethods.loadChar();
    if (sign == 't')
    {
        cout<<"Dzisiejsza data to: ";
        date=dates.getTodayDate();
        cout<<date<<endl;
    }
    if(sign=='n')
    {
        cout<<"Podaj date: "; // jak sprawdzić czy data jest dobrze wpisana??
        date = auxiliaryMethods.loadLine();
        while (!dates.checkDateFormat(date))
        {
            cout<<"Wpisz jeszcze raz date w poprawnym formacie rrrr-mm-dd: ";
            date=auxiliaryMethods.loadLine();
        }
        while(!dates.checkStartDate(date))
        {
            cout<<"Data musi byc pozniejsza niz 2000-01-01. Wpisz date ponownie: ";
            date=auxiliaryMethods.loadLine();
        }
        while(!dates.checkDayMonth(date) || !dates.checkMonthDate(date))
        {
            cout<<"Wpisz date ponownie: ";
            date=auxiliaryMethods.loadLine();
        }
    }
    expense.setDate(date);

    string item;
    cout << "Podaj rodzaj wydatku: ";
    item = auxiliaryMethods.loadLine();
    expense.setItem(auxiliaryMethods.changeFirstLetterForUpperCaseAndOthersForLowerCase(item));// czy zamieniac pierwsza litere na duza?

    cout << "Podaj wartosc: ";
    expense.setAmount(auxiliaryMethods.checkDotsInAmount(auxiliaryMethods.loadLine())); //zmiana wartosci na z kropką

    return expense;
}


bool FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME_WITH_EXPENSES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("UserId", expense.getUserId());
        xml.AddElem("ExpenseId", expense.getExpenseId());
        xml.AddElem("Date", expense.getDate());
        xml.AddElem("Item", expense.getItem());
        xml.AddElem("Amount", expense.getAmount());

        xml.Save(FILE_NAME_WITH_EXPENSES);
        return true;
    }
    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("UserId", expense.getUserId());
        xml.AddElem("ExpenseId", expense.getExpenseId());
        xml.AddElem("Date", expense.getDate());
        xml.AddElem("Item", expense.getItem());
        xml.AddElem("Amount", expense.getAmount());

        xml.Save(FILE_NAME_WITH_EXPENSES);
        return true;
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << FILE_NAME_WITH_EXPENSES << " i zapisac w nim danych." << endl;
    return false;
}

vector <Expense> FileWithExpenses::loadExpensesLoggedInUser(int loggedInUserId)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    xml.Load(FILE_NAME_WITH_EXPENSES);
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("Expense"))
    {
        xml.IntoElem();

        if(xml.FindElem("UserId"))
        {
            while(LOGGED_IN_USER_ID==auxiliaryMethods.convertStringToInteger(xml.GetData()))
            {
                expense.setUserId(atoi(xml.GetData().c_str()));   //atoi(pojedynczaDanaUzytkownika.c_str())
                if(xml.FindElem("ExpenseId"))
                {
                    expense.setExpenseId(atoi(xml.GetData().c_str()));
                }
                if(xml.FindElem("Date"))
                {
                    expense.setDate(xml.GetData());
                }
                if(xml.FindElem("Item"))
                {
                    expense.setItem(xml.GetData());
                }
                if(xml.FindElem("Amount"))
                {
                    expense.setAmount(xml.GetData());
                }
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
    }
    lastExpenseId=expenses.size();

    return expenses;
}


void FileWithExpenses::showAllExpensesCurrentMonth()
{
   sumExpenses= balance.showAllExpensesCurrentMonth(expenses);
}

void FileWithExpenses::showAllExpensesPreviousMonth()
{
    sumExpenses=balance.showAllExpensesPreviousMonth(expenses);
}

int FileWithExpenses::getSumExpenses()
{
    return sumExpenses;
}
void FileWithExpenses::showAllExpensesChosenDates(int startDate,int endDate)
{
    sumExpenses=balance.showAllExpensesChosenDates(expenses, startDate, endDate);
}
