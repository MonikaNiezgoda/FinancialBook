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

    xml.Save(FILE_NAME_WITH_USERS);
}

    else
    cout << "Nie udalo sie otworzyc pliku " << FILE_NAME_WITH_USERS << " i zapisac w nim danych." << endl;

}
