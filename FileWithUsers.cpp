#include "FileWithUsers.h"


void FileWithUsers::addUserToData(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME_WITH_USERS);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", user.getID() );
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Password", user.getPassword());
        xml.AddElem("Name", user.getName());
        xml.AddElem("Surname", user.getSurname());

        xml.Save(FILE_NAME_WITH_USERS);
    }
    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", user.getID() );
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Password", user.getPassword());
        xml.AddElem("Name", user.getName());
        xml.AddElem("Surname", user.getSurname());

        xml.Save(FILE_NAME_WITH_USERS);
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << FILE_NAME_WITH_USERS << " i zapisac w nim danych." << endl;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;
    bool bSuccess = xml.Load( "users.xml");
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        if (xml.FindElem("UserId"))
        {
            user.setID(atoi(xml.GetData().c_str()));   //atoi(pojedynczaDanaUzytkownika.c_str())
            if(xml.FindElem("Login"))
            {
                user.setLogin(xml.GetData());
            }
            if(xml.FindElem("Password"))
            {
                user.setPassword(xml.GetData());
            }
            if(xml.FindElem("Name"))
            {
                user.setName(xml.GetData());
            }
            if(xml.FindElem("Surname"))
            {
                user.setSurname(xml.GetData());
            }
            xml.OutOfElem();
        }
        users.push_back(user);
    }
    return users;
}
