#include "User.h"

void User::setID(int newID)
{
    if (newID >= 0)
    id = newID;
}
void User::setLogin(string newLogin)
{
    login=newLogin;
}
void User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getID()
{
    return id;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
