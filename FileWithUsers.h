#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    const string FILE_NAME_WITH_USERS="Users.xml";

 public:

    void addUserToFile(User user);
    //FileWithUsers(string fileNameWithUsers) :  FILE_NAME_WITH_USERS("Users.xml")  {};
    vector <User> loadUsersFromFile();
    void changeUserPasswordInFile(int userId, string newPassword);

};

#endif // PLIKZUZYTKOWNIKAMI_H
