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
