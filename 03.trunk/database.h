#ifndef DATABASE_H
#define DATABASE_H
#include "mail.h"
#include <QList>
#include "contact.h"
#include "user.h"

#include "qstring.h"
#include "group.h"

class DataBase
{
public:
    DataBase();
    //database connec
    bool connectDB();
    //user option

    //mail option
    bool mailCreate(Mail *mail);
    bool mailDraft(Mail mail);
    bool mailRemove(QList<int> mailidlist);
    bool mailDelete(QList<int> mailidlist);

    bool mailReaded(QList<int> mailidlist);
    bool mailStar(QList<int> mailidlist);
    QList<Mail> senderMailSelected(QString username);
    QList<Mail> deletedMailSelected(QString username);
    QList<Mail> receiverMailSelected(QString username);
    QList<Mail> draftMailSelected(QString username);

    Mail mailSelectedByMailid(int mailid);
    //Mail mailReedit(int mailid);

    //user
    bool userRegister(User user);
    int userLogin(User user);
    bool userLogout(User user);
    bool updateInformation(User user, QString userName);//username can't change
    QList<User> selectUser();
    User selectUserByUserName(QString userName);
    bool addContact(QString userName, QString linkmanName, QString remarks, QString groupName);
    QList<Contact> selectContact(QString userName);//list show info

    bool updateContactNickName(QString userName, QString linkmanName, QString newRemarks);//change remarks

    bool deleteContact(QString userName, QString linkmanName);
    bool deleteGroup(QString userName, QString groupName);
    bool addGroup(QString userName, QString groupName);

    QList<Contact> selectContactByGroup(QString userName, QString groupName);
    QList<QString> groupSelected(QString username);
    bool groupConfig(QString username,QString groupname);

    bool groupDelete(QString username,QString groupname);

    bool contactListDelete(QList<QString> contactList);

    bool userConfirm(QString username);

    QList<QString> selectGroupName(QString username);

    bool contactConfim(QString username,QString contactname);
};

#endif // DATABASE_H
