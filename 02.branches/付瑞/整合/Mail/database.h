#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "contact.h"
#include <QList>

class DataBase
{
public:
    DataBase();
    //database connec
    bool connectDB();

    //User
    bool userRegister(User user);
    int userLogin(User user);
    bool userLogout(User user);
    bool updateInformation(User user, QString userName);//username can't change
    QList<User> selectUser();
    User selectUserByUserName(QString userName);
    bool addContact(QString userName, QString linkmanName, QString remarks);
    QList<Contact> selectContact(QString userName);//list show info

    bool updateContactNickName(QString userName, QString linkmanName, QString newRemarks);//change remarks

    bool deleteContact(QString userName, QString linkmanName);
    bool deleteGroup(QString userName, QString groupName);
    bool addGroup(QString userName, QString groupName);

};

#endif // DATABASE_H
