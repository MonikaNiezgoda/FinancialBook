#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    string date;
    string item;
    string amount;

public:
    void setExpenseId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();

    static bool CompareByDate( Expense& l, Expense& r);
};
#endif
