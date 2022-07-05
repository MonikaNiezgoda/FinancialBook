
#include "FileWithIncomes.h"

void FileWithIncomes::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) // dopisaæ do pliku z przychodami
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

    string data;
    cout << "Czy przychod z dnia dzisiejszego:";
    cout << endl << "Wcisnij 't' jesli tak, wcisnij 'n' jesli data jest inna: ";
            sign = auxiliaryMethods.loadChar();
            if (sign == 't')
            {
                //metoda pobranie dzisiejszej daty
            }
            if(sign=='n')
            {
                date = auxiliaryMethods.loadLine();
            }


    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));

    string nazwisko;
    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());

    return adresat;
}
