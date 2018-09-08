#ifndef GROUP_H
#define GROUP_H
#include"qstring.h"

class Group
{
public:
    Group();
    //get and set function
    QString getuserName();
    QString getGroupName();
    void setUserName(QString username);
    void serGroupName(QString groupName);
    //select function
private:
    QString userName;
    QString groupName;
};

#endif // GROUP_H
