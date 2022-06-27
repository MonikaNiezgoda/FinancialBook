#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>

#include "FileWithUsers.h"
#include "User.h"

using namespace std;


class UserMenager
{
    int loggedInUserId;
    vector <User> users;
    //const string FILE_NAME_WITH_USERS;

    int getNewUserId();
    bool isLoginExist(string login);
    User getNewUserData();

public:
    UserMenager() /*: FILE_NAME_WITH_USERS(fileNameWithUsers)*/{
    loggedInUserId = 0;
    //users = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void userRegistration();
    //int logowanieUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //int wylogowanieUzytkownika();
    //void ustawIdZalogowanegoUzytkownika (int noweId);
    int getLoggedInUserId ();
    bool isLoginExist();
};

#endif
