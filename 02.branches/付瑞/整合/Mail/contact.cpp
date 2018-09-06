#include "contact.h"

Contact::Contact()
{

}

Contact::Contact(QString userName, QString linkmanName, QString groupList, QString remarks, QString phoneNum)
    :userName(userName),linkmanName(linkmanName),groupList(groupList),remarks(remarks),phoneNum(phoneNum)
{

}
QString Contact::getUserName()
{
    return userName;
}
QString Contact::getLinkmanName()
{
    return linkmanName;
}
QString Contact::getGroupList()
{
    return groupList;
}
QString Contact::getRemarks()
{
    return remarks;
}
QString Contact::getPhoneNum()
{
    return phoneNum;
}
void Contact::setUserName(QString userName)
{
    this->userName=userName;
}
void Contact::setLinkmanName(QString linkmanName)
{
    this->linkmanName=linkmanName;
}
void Contact::setGroupList(QString groupList)
{
    this->groupList=groupList;
}
void Contact::setRemarks(QString remarks)
{
    this->remarks=remarks;
}
void Contact::setPhoneNum(QString phoneNum)
{
    this->phoneNum=phoneNum;
}
