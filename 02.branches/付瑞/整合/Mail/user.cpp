#include "user.h"

User::User()
{

}

User::User(QString userName,QString password)
    :userName(userName),password(password)
{}

User::User(QString userName,QString nickName,QString password,QString phoneNum)
    :userName(userName),nickName(nickName),password(password),phoneNum(phoneNum)
{}

User::User(QString userName,QString nickName,QString password)
    :userName(userName),nickName(nickName),password(password)
{}

QString User::getUserName()
{
    return userName;
}

QString User::getNickName()
{
    return nickName;
}
QString User::getPassword()
{
    return password;
}
QString User::getPhoneNum()
{
    return phoneNum;
}
void User::setUserName(QString userName)
{
    this->userName=userName;
}
void User::setNickName(QString nickName)
{
    this->nickName=nickName;
}
void User::setPassword(QString password)
{
    this->password=password;
}
void User::setPhoneNum(QString phoneNum)
{
    this->phoneNum=phoneNum;
}
