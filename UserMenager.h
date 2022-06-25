#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>

using namespace std;


class UserMenager
{
    int loggedInUserId;
    vector <User> users;

    int getNewUserId();
    bool isLoginExist(string login);
    User getNewUserData();

public:
    UserMenager(string fileNameWithUsers) : plikZUzytkownikami(fileNameWithUsers){
    loggedInUserId = 0;
    users = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void registerUser();
    //int logowanieUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //int wylogowanieUzytkownika();
    //void ustawIdZalogowanegoUzytkownika (int noweId);
    int getLoggedInUserId ();
    //bool czyUzytkownikJestZalogowany();
};

#endif
