#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QResizeEvent>
#include <QSize>
#include <QIcon>
#include <QListWidgetItem>
#include "tablemodel.h"
#include "tablemodelbook.h"
#include "mail.h"
#include "user.h"
#include "database.h"
#include "tablemodeldraft.h"
#include "tablemodelsended.h"
#include "tablemodelrubbish.h"
#include "maildlg.h"
#include "buildcontactdlg.h"
#include "contact.h"
#include "addcontact.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,User *user=new User());
    ~Widget();
    User nowUser;


private slots:
    void on_listWidget_clicked(const QModelIndex &index);


    void on_checkBox_stateChanged(int arg1);


//    void on_tableViewMail_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_listWidgetBook_itemClicked(QListWidgetItem *item);

    void on_tableViewAllBook_doubleClicked(const QModelIndex &index);

    void on_addContactBtn_clicked();

    void on_deleteGroupBtn_clicked();

 //   void on_deleteContactBtn_clicked();

   void on_deleteCompleteBtn_clicked();

    void on_deleteCheckedBtn_clicked();

    void on_markAllReadedBtn_clicked();

    void on_deleteDraft_clicked();

    void on_sendMailBtn_clicked();

    void on_saveDraftBtn_clicked();

    void on_tableViewDraft_doubleClicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_replyBtn_clicked();

    void on_deleteMailBtn_clicked();

    void on_deleteSendMailBtn_clicked();

    void on_pushButton_clicked();

    void on_modifyName_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_personImfBtn_clicked();

    void on_quitBtn_clicked();

//    void on_deleteContactBtn_clicked();

    void on_deleteContactBtn_clicked();

    void on_checkBoxAllBook_stateChanged(int arg1);

    void on_checkBoxAllDraft_stateChanged(int arg1);

    void on_checkBoxAllSelect_stateChanged(int arg1);

    void on_checkBoxRubbish_stateChanged(int arg1);

    void on_tableViewRubbish_doubleClicked(const QModelIndex &index);

    void on_addNowContactBtn_clicked();

private:
    Ui::Widget *ui;
    // QWidget interface


    // QWidget interface


    // QWidget interface


    // QWidget interface
   TableModel* model;
   TableModelBook *modelBook;
   TableModelDraft *modelDraft;
   tablemodelSended *modelSended;
    TableModelRubbish *modelRubbish;

   QList<Mail> receiverMails;
   QList<Mail> draftMail;
   QList<Mail> sendedMail;
   QList<Mail> rubbishMail;
   QList<Contact> allContact;
   int nowReadMailId;//记录当前读取邮件的ID
   MailDlg mailDlg;
   buildContactDlg *addContactDialog;
   AddContact *addContactDlg;
   QList<QString>  allGroup;
    int idTimer;

protected:
   void timerEvent(QTimerEvent *);
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // WIDGET_H
