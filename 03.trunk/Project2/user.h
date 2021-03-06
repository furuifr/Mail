#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    User(QString userName, QString password);
    User(QString userName, QString nickName, QString password, QString phoneNum);
    User(QString userName, QString nickName, QString password);
    QString getUserName();
    QString getNickName();
    QString getPassword();
    QString getPhoneNum();
    void setUserName(QString userName);
    void setNickName(QString nickName);
    void setPassword(QString password);
    void setPhoneNum(QString phoneNum);

private:
    QString userName;
    QString nickName;
    QString password;
    QString phoneNum;
};

#endif // USER_H
