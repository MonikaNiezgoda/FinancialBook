#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>

#include "FileWithUsers.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserMenager
{
    int loggedInUserId;
    vector <User> users;
    //const string FILE_NAME_WITH_USERS;
    FileWithUsers fileWithUsers;

    int getNewUserId();
    bool isLoginExist(string login);
    User getNewUserData();

public:
    UserMenager() /*: FILE_NAME_WITH_USERS(fileNameWithUsers)*/{
    loggedInUserId = 0;
    users = fileWithUsers.loadUsersFromFile();
    };
    void registerUser();
    int loginUser();
    bool isUserLoggedIn();
    void changePassword();
    int getLoggedInUserId();
    void setLoggedInUserId(int newId);
    bool isLoginExist();
    void showAllUsers();
    int logoutUser();
};

#endif
