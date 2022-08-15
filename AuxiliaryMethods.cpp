#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadChar()
{
    string input = "";
    char sign = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        else
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int AuxiliaryMethods::convertStringToInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods:: changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::checkDotsInAmount (string amount)
{
    int dlugosc=amount.size();
    for (int i=0; i<amount.size(); i++)
    {
        if (amount[i]==',')
        {
            amount.replace(i,1,".");
        }
    }
    if (amount[dlugosc-2]=='.' )
    {
        amount=amount+"0";
        return amount;
    }
    if (amount[dlugosc-3]!='.' || amount[dlugosc-2]!='.' )
    {
        amount=amount+".00";
        return amount;
    }
    else
        return amount;

}

