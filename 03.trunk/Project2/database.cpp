#include "database.h"
#include "QSqlDatabase"
#include "qstring.h"
#include "qdebug.h"
#include "QSqlQuery"
#include "QDateTime"


DataBase::DataBase()
{
}

bool DataBase::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("58.87.108.226");
    db.setPort(3306);
    db.setDatabaseName("flowermail");
    db.setUserName("root");
    db.setPassword("123456");
    qDebug()<<"before open";
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
bool DataBase::mailCreate(Mail *mail)
{
    QSqlQuery query;
    QString createline = QString("insert into mail(theme,content,sendername,receivername,deleted,star,draft,readed,time) values('%1','%2','%3','%4','%5','%6','%7','%8','%9')").arg(mail->getTheme()).arg(mail->getContent()).arg(mail->getSenderName()).arg(mail->getReceiverName()).arg(mail->getDeleted()).arg(mail->getStar()).arg(mail->getDraft()).arg(mail->getReaded()).arg(mail->getTime());
    //console log the sql line
    qDebug()<<createline;
    if(!query.exec(createline))
        return false;
    else {
        return true;
    }
}

//create new draft
bool DataBase::mailDraft(Mail mail)
{
    //change the draft flag to 1
    mail.setDraft(1);
    QSqlQuery query;
    QString sqlline = QString("insert into mail(theme,content,sendername,receivername,deleted,star,draft,readed,time) values('%1','%2','%3','%4','%5','%6','%7','%8','%9')").arg(mail.getTheme()).arg(mail.getContent()).arg(mail.getSenderName()).arg(mail.getReceiverName()).arg(mail.getDeleted()).arg(mail.getStar()).arg(mail.getDraft()).arg(mail.getReaded()).arg(mail.getTime());
    //console log the sql line
    qDebug()<<sqlline;
    if(!query.exec(sqlline))
        return false;
    else {
        return true;
    }
}

//remove the mail to trash
bool DataBase::mailRemove(QList<int> mailidlist)
{
    int mailNum = mailidlist.size();
    QSqlQuery query;
    for(int i = 0; i < mailNum; i++)
    {
        QString sqlline = QString("update mail set deleted = 1 where id = '%1'").arg(mailidlist[i]);
        if(!query.exec(sqlline))
            return false;
    }
    return true;
}

//delete the mail totally
bool DataBase::mailDelete(QList<int> mailidlist)
{
    int mailNum = mailidlist.size();
    QSqlQuery query;
    for(int i = 0; i < mailNum; i++)
    {
        QString sqlline = QString("delete from mail where id = '%1'").arg(mailidlist[i]);
        if(!query.exec(sqlline))
            return false;
    }
    return true;
}

//change the readedflag
bool DataBase::mailReaded(QList<int> mailidlist)
{
    int mailNum = mailidlist.size();
    QSqlQuery query;
    for(int i = 0; i < mailNum; i++)
    {
        QString sqlline = QString("update mail set readed = 1 where id = '%1'").arg(mailidlist[i]);
        qDebug()<<sqlline;
        if(!query.exec(sqlline))
            return false;
    }
    return true;
}

//signal the mail star
bool DataBase::mailStar(QList<int> mailidlist)
{
    int mailNum = mailidlist.size();
    QSqlQuery query;
    for(int i = 0; i < mailNum; i++)
    {
        QString sqlline = QString("update mail set star = 1 where id = '%1'").arg(mailidlist[i]);
        if(!query.exec(sqlline))
            return false;
    }
    return true;
}

//select user's whole sender mails(not include the drafts)
QList<Mail> DataBase::senderMailSelected(QString username)
{
    QList<Mail> mailList;
    QSqlQuery query;
    QString sqlline = QString("select *from mail where sendername = '%1' and draft = 0").arg(username);
    query.exec(sqlline);
    while (query.next()) {
        int mailid =query.value(0).toInt();
        QString theme = query.value(1).toString();
        QString content = query.value(2).toString();
        QString sendername = query.value(3).toString();
        QString receivername = query.value(4).toString();
        int deleted = query.value(5).toInt();
        int star = query.value(6).toInt();
        int draft = query.value(7).toInt();
        int readed = query.value(8).toInt();
        QString time = query.value(9).toString();

        Mail tmpMail(mailid,theme,content,sendername,receivername,deleted,star,draft,readed,time);
        mailList.append(tmpMail);
    }
    return mailList;
}

//select user's deleted mails
QList<Mail> DataBase::deletedMailSelected(QString username)
{
    QList<Mail> mailList;
    QSqlQuery query;
    QString sqlline = QString("select *from mail where receivername = '%1' and deleted = 1").arg(username);
    query.exec(sqlline);
    while (query.next()) {
        int mailid =query.value(0).toInt();
        QString theme = query.value(1).toString();
        QString content = query.value(2).toString();
        QString sendername = query.value(3).toString();
        QString receivername = query.value(4).toString();
        int deleted = query.value(5).toInt();
        int star = query.value(6).toInt();
        int draft = query.value(7).toInt();
        int readed = query.value(8).toInt();
        QString time = query.value(9).toString();

        Mail tmpMail(mailid,theme,content,sendername,receivername,deleted,star,draft,readed,time);
        mailList.append(tmpMail);
    }
    return mailList;
}

//select user's received mails(deleted = 0)
QList<Mail> DataBase::receiverMailSelected(QString username)
{
    QList<Mail> mailList;
    QSqlQuery query;
    QString sqlline = QString("select *from mail where receivername = '%1' and deleted = 0 and draft = 0").arg(username);
    query.exec(sqlline);
    while (query.next()) {
        int mailid =query.value(0).toInt();
        QString theme = query.value(1).toString();
        QString content = query.value(2).toString();
        QString sendername = query.value(3).toString();
        QString receivername = query.value(4).toString();
        int deleted = query.value(5).toInt();
        int star = query.value(6).toInt();
        int draft = query.value(7).toInt();
        int readed = query.value(8).toInt();
        QString time = query.value(9).toString();

        Mail tmpMail(mailid,theme,content,sendername,receivername,deleted,star,draft,readed,time);
        mailList.append(tmpMail);
    }
    return mailList;
}

//select user's draft mails
QList<Mail> DataBase::draftMailSelected(QString username)
{
    QList<Mail> mailList;
    QSqlQuery query;
    QString sqlline = QString("select *from mail where sendername = '%1' and draft = 1").arg(username);
    query.exec(sqlline);
    while (query.next()) {
        int mailid =query.value(0).toInt();
        QString theme = query.value(1).toString();
        QString content = query.value(2).toString();
        QString sendername = query.value(3).toString();
        QString receivername = query.value(4).toString();
        int deleted = query.value(5).toInt();
        int star = query.value(6).toInt();
        int draft = query.value(7).toInt();
        int readed = query.value(8).toInt();
        QString time = query.value(9).toString();

        Mail tmpMail(mailid,theme,content,sendername,receivername,deleted,star,draft,readed,time);
        mailList.append(tmpMail);
    }
    return mailList;
}

//select the mail by itsid
Mail DataBase::mailSelectedByMailid(int mailid)
{
    QSqlQuery query;
    QString sqlline = QString("select *from mail where mailid = '%1'").arg(mailid);
    query.next();
    Mail tmpMail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString());
    return tmpMail;
}

//return the draft mail(for reedit)
//Mail DataBase::mailReedit(int mailid)
//{
//    QSqlQuery query;
//    QString sqlline = QString("select *from mail where mailid = '%1'").arg(mailid);
//    query.next();
//    Mail tmpMail(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toString());
//    return tmpMail;
//}



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

bool DataBase::addContact(QString userName, QString linkmanName, QString remarks, QString groupName)
{
    DataBase db;

    QSqlQuery query;
    QString createline = QString("insert into contact(userName, linkmanName, groupList, remarks) values ('%1','%2','%3','%4')").arg(userName).arg(linkmanName).arg(groupName).arg(remarks);
    qDebug()<<createline;
    query.exec(createline);
    //remain a select function to judge exist
    return true;
}

QList<Contact> DataBase::selectContact(QString userName)
{
    QSqlQuery query;
    QList<Contact> contactList;
    QString createline = QString("select * from contact where userName = '%1'").arg(userName);
    qDebug()<<createline;
    if(!query.exec(createline))
        return contactList;
    else {
        while(query.next()){
            int  id=query.value(0).toInt();
            QString userName = query.value(1).toString();
            QString linkmanName = query.value(2).toString();
            QString groupList = query.value(3).toString();
            QString remarks = query.value(4).toString();
            QString phoneNum = query.value(5).toString();
            Contact contact(id,userName,linkmanName,groupList,remarks,phoneNum);
            contactList.append(contact);
        }
        return contactList;
    }
}
bool DataBase::updateContactNickName(QString userName, QString linkmanName, QString newRemarks)
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

QList<QString> DataBase::groupSelected(QString username)
{
    QList<QString> groupNameList;
    QSqlQuery query;
    QString sqlline = QString("select *from grouplist where username = '%1'").arg(username);
    //test
    qDebug()<<sqlline;
    query.exec(sqlline);
    while (query.next()) {
        QString groupname = query.value(1).toString();
        //test
        qDebug()<<groupname;
        groupNameList.append(groupname);
    }
    return groupNameList;
}

//judge wether the username&&groupname is already existed
bool DataBase::groupConfig(QString username,QString groupname)
{
    QSqlQuery query;
    QString sqlline = QString("select count(*) from grouplist where username ='%1' and groupname = '%2'").arg(username).arg(groupname);
    query.exec(sqlline);
    query.next();
    if(query.value(0).toInt() == 0)
        return true;
    else
        return false;
}

bool DataBase::deleteContact(QString userName, QString linkmanName)
{//select the groupname by username

    QSqlQuery query;
    QString createline = QString("delete from contact where where userName = '%1' and linkmanName = '%2'")
            .arg(userName).arg(linkmanName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}
bool DataBase::addGroup(QString userName, QString groupName)
{
    QSqlQuery query;
    QString createline = QString("insert into grouplist(userName, groupName) values ('%1','%2') ")
            .arg(userName).arg(groupName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}

bool DataBase::deleteGroup(QString userName, QString groupName)
{
    QSqlQuery query;
    QString createline = QString("delete from grouplist where userName = '%1' and groupName = '%2'")
            .arg(userName).arg(groupName);
    qDebug()<<createline;
    if(query.exec(createline))
        return true;
    else
        return false;
}


//username confige
bool DataBase::userConfirm(QString username)
{
    QSqlQuery query;
    QString sqlline = QString("select count(*) from user where username ='%1'").arg(username);
    query.exec(sqlline);
    query.next();
    if(query.value(0).toInt() == 0)
        return true;
    else
        return false;
}


//judge the exist of contact
bool DataBase::contactConfim(QString username,QString contactname)
{
    QSqlQuery query;
    QString sqlline = QString("select count(*) from contact where username = '%1' and linkmanname = '%2'").arg(username).arg(contactname);
    query.exec(sqlline);
    query.next();
    if(query.value(0).toInt() == 0)
        return true;
    else
        return false;
}


QList<Contact> DataBase::selectContactByGroup(QString userName, QString groupName)
{
    QSqlQuery query;
    QList<Contact> contactList;
    QString createline = QString("select * from contact where username = '%1' and groupList = '%2'").arg(userName).arg(groupName);
    qDebug()<<createline;
    if(!query.exec(createline))
        return contactList;
    else {
        while(query.next()){
            int id=query.value(1).toInt();
            QString userName = query.value(1).toString();
            QString linkmanName = query.value(2).toString();
            QString groupList = query.value(3).toString();
            QString remarks = query.value(4).toString();
            QString phoneNum = query.value(5).toString();
            Contact contact(id,userName,linkmanName,groupList,remarks,phoneNum);
            contactList.append(contact);
        }
        return contactList;
    }
}


//delete the group with username and groupname
bool DataBase::groupDelete(QString username,QString groupname)
{
    QSqlQuery query;
    QString sqlline = QString("delete from contact where username ='%1' and groupList = '%2'")
            .arg(username).arg(groupname);
    qDebug()<<sqlline;
    query.exec(sqlline);
    DataBase db;
    if(db.groupConfig(username,groupname))
        return true;
    else
        return false;
}

//delete contact list by name
bool DataBase::contactListDelete(QList<QString> contactList)
{
    int contlistNum = contactList.size();
    QSqlQuery query;
    for(int i = 0; i < contlistNum; i++)
    {
        QString sqlline = QString("delete from contact where linkmanName = '%1'").arg(contactList[i]);
        qDebug()<<sqlline;
        if(!query.exec(sqlline))
            return false;
    }
    return true;
}


//select whole grouplist by username
QList<QString> DataBase::selectGroupName(QString username)
{
    QList<QString> groupNameList;
    QSqlQuery query;
    QString sqlline = QString("select *from grouplist where username = '%1'").arg(username);
    query.exec(sqlline);
    while(query.next()){
        groupNameList.append(query.value(1).toString());
    }
    return groupNameList;
}
