#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int id;
    string login;
    string password;
public:
    void setID(int newID);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getID();
    string getLogin();
    string getPassword();
};

#endif
