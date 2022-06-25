#include "UserMenager.h"

void UserMenager::userRegistration()
{
    User user = getNewUserData();
    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

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
