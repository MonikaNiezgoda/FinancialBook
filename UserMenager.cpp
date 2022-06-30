#include "UserMenager.h"

void UserMenager::userRegistration()
{
    FileWithUsers fileWithUsers;
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToData(user);

    cout<<endl<<"Konto zalozono pomyslnie"<<endl<<endl;
    system("pause");
}

User UserMenager::getNewUserData()
{
    User user;
    user.setID(getNewUserId());

    string login;
    do
    {
        cout<<"Podaj login: ";
        cin>>login;
        user.setLogin(login);
    }
    while(isLoginExist(user.getLogin())==true);

    string password;
    cout<<"Podaj haslo: ";
    cin>>password;
    user.setPassword(password);

    return user;
}

int UserMenager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getID()+ 1;

}
bool UserMenager::isLoginExist(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        return false;
    }
}

void UserMenager::showAllUsers()
{
    for (int i=0; i<users.size(); i++)
    {
        cout<<users[i].getID()<<endl;
        cout<<users[i].getLogin()<<endl;
        cout<<users[i].getPassword()<<endl;
    }
}


