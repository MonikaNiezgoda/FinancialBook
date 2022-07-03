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
