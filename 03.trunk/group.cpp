#include "group.h"

Group::Group()
{

}

QString Group::getuserName()
{
    return userName;
}

QString Group::getGroupName()
{
    return groupName;
}

void Group::setUserName(QString username)
{
    this->userName = username;
}

void Group::serGroupName(QString groupname)
{
    this->groupName = groupname;
}


