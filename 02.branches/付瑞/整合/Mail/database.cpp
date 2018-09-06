#include "database.h"
#include "QSqlDatabase"
#include "qstring.h"
#include "qdebug.h"
#include "QSqlQuery"
#include "QDateTime"
#include "user.h"
#include <QList>
#include "contact.h"

DataBase::DataBase()
{
}

bool DataBase::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("flowermail");
    db.setUserName("root");
    db.setPassword("123456");     //设置数据库连接账号的密码
    bool ok = db.open();
    if(ok){
        qDebug()<<"success connect database";
        return true;
    }
    else{
        qDebug()<<"fail connect database";
        return false;
    }
}

//create new mail

bool DataBase::userRegister(User user)
{

    QSqlQuery query;
    QString nickName="";
    QString phoneNum="";
    QString createline = QString("insert into user(userName,nickName,password,phoneNum) values('%1','%2','%3','%4')")
            .arg(user.getUserName()).arg(nickName).arg(user.getPassword()).arg(phoneNum);
    qDebug()<<createline;
    if(!query.exec(createline))
        return false;
    else
        return true;

}

int DataBase::userLogin(User user)
{

}

QList<User> DataBase::selectUser()
{
    QSqlQuery query;
    QList<User> userList;
    QString createline = QString("select * from user");
    qDebug()<<createline;
    if(!query.exec(createline))
        return NULL;
    else {
        while(query.next()){
            QString userName = query.value(1).toString();
            //QString nickName = query.value(2).toString();
            QString password = query.value(3).toString();
            //QString phoneNum = query.value(4).toString();
            User user(userName,password);
            userList.append(user);
        }
        return userList;
    }
}

User DataBase::selectUserByUserName(QString userName)
{
    QSqlQuery query;
    QString createline = QString("select * from user where userName = '%1'").arg(userName);
    qDebug()<<createline;
    if(query.exec(createline))
    {
        query.next();
        QString userName = query.value(1).toString();
        QString nickName = query.value(2).toString();
        QString password = query.value(3).toString();
        QString phoneNum = query.value(4).toString();
        User user(userName,nickName,password,phoneNum);
        qDebug()<<user.getUserName();
        return user;
    }
    else
    {
        User user("","","","");
        return user;
    }
}

bool DataBase::updateInformation(User user, QString userName)//
{
    QString nickName = user.getNickName();
    QString password = user.getPassword();
    QString phoneNum = user.getPhoneNum();
    QSqlQuery query;
    QString createline = QString("update user set nickName = '%1', password = '%2', phoneNum = '%3' where userName = '%4'")
            .arg(nickName).arg(password).arg(phoneNum).arg(userName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}

bool DataBase::addContact(QString userName, QString linkmanName, QString remarks)
{
    DataBase db;
    User contact = db.selectUserByUserName(linkmanName);
    QSqlQuery query;
    QString createline = QString("insert into contact(userName, linkmanName, groupList, remarks, phoneNum) values ('%1','%2','%3','%4','%5')")
            .arg(userName).arg(contact.userName).arg("").arg(remarks).arg("");
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}

QList<Contact> selectContact(QString userName)
{
    QSqlQuery query;
    QList<User> contactList;
    QString createline = QString("select * from contact where userName = '%1'").arg(userName);
    qDebug()<<createline;
    if(!query.exec(createline))
        return NULL;
    else {
        while(query.next()){
            QString userName = query.value(1).toString();
            QString linkmanName = query.value(2).toString();
            QString groupList = query.value(3).toString();
            QString remarks = query.value(4).toString();
            QString phoneNum = query.value(5).toString();
            Contact contact(userName,linkmanName,groupList,remarks,phoneNum);
            contactList.append(user);
        }
        return contactList;
    }
}
bool updateContactNickName(QString userName, QString linkmanName, QString newRemarks)
{
    QSqlQuery query;
    QString createline = QString("update contact set remarks = '%1' where userName = '%2' and linkmanName = '%3'")
            .arg(newRemarks).arg(userName).arg(linkmanName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}
bool deleteContact(QString userName, QString linkmanName)
{
    QSqlQuery query;
    QString createline = QString("delete from contact where where userName = '%1' and linkmanName = '%2'")
            .arg(userName).arg(linkmanName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}
bool addGroup(QString userName, QString groupName)
{
    QSqlQuery query;
    QString createline = QString("insert into contact(userName, groupName) values ('%1','%2') ")
            .arg(userName).arg(groupName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}
bool deleteGroup(QString userName, QString groupName)
{
    QSqlQuery query;
    QString createline = QString("delete from contact where where userName = '%1' and groupName = '%2'")
            .arg(userName).arg(groupName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}



