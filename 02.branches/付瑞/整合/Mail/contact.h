#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact();
    Contact(QString userName, QString linkmanName, QString groupList, QString remarks, QString phoneNum);

    QString getUserName();
    QString getLinkmanName();
    QString getGroupList();
    QString getRemarks();
    QString getPhoneNum();
    void setUserName(QString userName);
    void setLinkmanName(QString linkmanName);
    void setGroupList(QString groupList);
    void setRemarks(QString remarks);
    void setPhoneNum(QString phoneNum);

private:
    QString userName;
    QString linkmanName;
    QString groupList;
    QString remarks;
    QString phoneNum;

};

#endif // CONTACT_H
