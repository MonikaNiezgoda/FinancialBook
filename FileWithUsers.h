#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
//#include "UserMenager.h"
#include "Markup.h"
//#include "MetodyPomocnicze.h"
//#include "PlikTekstowy.h"

using namespace std;

class FileWithUsers
{
    const string FILE_NAME_WITH_USERS="Users.xml";

 public:

    void addUserToData(User user);
    //FileWithUsers(string fileNameWithUsers) :  FILE_NAME_WITH_USERS("Users.xml")  {};
    vector <User> loadUsersFromFile();
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);

};

#endif // PLIKZUZYTKOWNIKAMI_H
