#include "UserMenager.h"

void UserMenager::registerUser()
{
    FileWithUsers fileWithUsers;
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

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
    while(isLoginExist(user.getLogin()));

    string password;
    cout<<"Podaj haslo: ";
    cin>>password;
    user.setPassword(password);

    string name;
    cout<<"Podaj imie: ";
    cin>>name;
    user.setName(name);

    string surname;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    user.setSurname(surname);

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
    }
    return false;
}

int UserMenager::loginUser()
{
    string login = "", password = "";
    system("cls");

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempt << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId=users[i].getID();
                    return loggedInUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
           return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

bool UserMenager::isUserLoggedIn()
{
    if(loggedInUserId > 0)
        return true;
    else
        return false;
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

void UserMenager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i=0; i<users.size();i++)
    {
        if (users[i].getID() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

int UserMenager::getLoggedInUserId()
{
    return loggedInUserId;
}

void UserMenager::setLoggedInUserId(int newId)
{
    loggedInUserId = newId;
}

int UserMenager::logoutUser()
{
    loggedInUserId = 0;
}


