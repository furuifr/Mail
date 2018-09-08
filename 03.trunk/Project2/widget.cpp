#include "widget.h"
#include "ui_widget.h"
#include "tablemodel.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include <QInputDialog>
#include <QDir>
#include "tablemodelbook.h"
#include <QStandardItemModel>
#include <QLineEdit>
#include <QMessageBox>
#include "database.h"
#include "user.h"

Widget::Widget(QWidget *parent,User *user) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    nowUser=*user;
    //初始化model中的一些值
    //查询数据库获得所有收到的文件
    QString name=nowUser.getUserName();
    DataBase db;
    receiverMails=db.receiverMailSelected(nowUser.getUserName());
    //构造定时器
    idTimer=startTimer(10000);
    //更改构造函数将list赋值进去
    //收件箱
    ui->stackedWidget->setCurrentIndex(0);
     model=new TableModel(100,8,false,this,receiverMails);
    ui->tableView->setModel(model);
  //  ui->tableViewMailMail->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setShowGrid(false);
    ui->tableView->setFrameShape(QFrame::NoFrame);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);


    //更改构造函数将list赋值进去
    allContact=db.selectContact(nowUser.getUserName());
    modelBook=new TableModelBook(100,8,false,this,allContact);
    ui->tableViewAllBook->setModel(modelBook);
    ui->tableViewAllBook->resizeColumnsToContents();
    ui->tableViewAllBook->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewAllBook->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewAllBook->horizontalHeader()->setHighlightSections(false);
    ui->tableViewAllBook->verticalHeader()->setVisible(false);
    ui->tableViewAllBook->setShowGrid(false);
    ui->tableViewAllBook->setFrameShape(QFrame::NoFrame);
    ui->tableViewAllBook->setSelectionMode(QAbstractItemView::SingleSelection);


    //获取草稿箱的列表
    draftMail=db.draftMailSelected(nowUser.getUserName());
       //设置草稿箱的表格
    modelDraft=new TableModelDraft(100,8,false,this,draftMail);
    ui->tableViewDraft->setModel(modelDraft);
    ui->tableViewDraft->resizeColumnsToContents();
    ui->tableViewDraft->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewDraft->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewDraft->horizontalHeader()->setHighlightSections(false);
    ui->tableViewDraft->verticalHeader()->setVisible(false);
    ui->tableViewDraft->setShowGrid(false);
    ui->tableViewDraft->setFrameShape(QFrame::NoFrame);
    ui->tableViewDraft->setSelectionMode(QAbstractItemView::SingleSelection);

    //获取已发送页面列表
    sendedMail=db.senderMailSelected(nowUser.getUserName());
    //设置已发送页面表格
    modelSended=new tablemodelSended(100,8,false,this,sendedMail);
    ui->tableViewSended->setModel(modelSended);
    ui->tableViewSended->resizeColumnsToContents();
    ui->tableViewSended->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewSended->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewSended->horizontalHeader()->setHighlightSections(false);
    ui->tableViewSended->verticalHeader()->setVisible(false);
    ui->tableViewSended->setShowGrid(false);
    ui->tableViewSended->setFrameShape(QFrame::NoFrame);
    ui->tableViewSended->setSelectionMode(QAbstractItemView::SingleSelection);

    //获取垃圾箱页面列表

    rubbishMail=db.deletedMailSelected(nowUser.getUserName());
    modelRubbish=new TableModelRubbish(100,8,false,this,rubbishMail);
    ui->tableViewRubbish->setModel(modelRubbish);
    ui->tableViewRubbish->resizeColumnsToContents();
    ui->tableViewRubbish->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewRubbish->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewRubbish->horizontalHeader()->setHighlightSections(false);
    ui->tableViewRubbish->verticalHeader()->setVisible(false);
    ui->tableViewRubbish->setShowGrid(false);
    ui->tableViewRubbish->setFrameShape(QFrame::NoFrame);
    ui->tableViewRubbish->setSelectionMode(QAbstractItemView::SingleSelection);

    //修改个人信息页面中的一些控件的显示
    ui->personalName->setText(nowUser.getNickName());
    ui->phoneNum->setText(nowUser.getPhoneNum());
    ui->labelAddressShow->setText(nowUser.getUserName());
    ui->password->setText(nowUser.getPassword());

    ui->personalName->setFocusPolicy(Qt::NoFocus);
    ui->phoneNum->setFocusPolicy(Qt::NoFocus);
    ui->password->setFocusPolicy(Qt::NoFocus);
    ui->comfirmPwdLabel->setVisible(false);
    ui->comfirmPwd->setVisible(false);

    ui->personalNameLabel->setText(nowUser.getUserName());

    //获取所有的群组
    allGroup=db.selectGroupName(nowUser.getUserName());
    for(int i=0;i<allGroup.count();i++){
        QListWidgetItem *item=new QListWidgetItem();
        item->setText(allGroup.at(i));
        item->setFont(QFont("Ubuntu", 15));
        item->setTextAlignment(Qt::AlignHCenter);
        ui->listWidgetBook->addItem(item);
    }

//    QPixmap *pixmap = new QPixmap(":/new/Images/MailLogo.png");
//    pixmap->scaled(ui->backgroundlabelwidget->size(), Qt::KeepAspectRatio);
//    ui->backgroundlabelwidget->setScaledContents(true);
//    ui->backgroundlabelwidget->setPixmap(*pixmap);
//    ui->backgroundlabelwidget->resize(ui->widget_9->size());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event){
    if(event->timerId()==idTimer){
        DataBase db;
        receiverMails=db.receiverMailSelected(nowUser.getUserName());
        model=new TableModel(100,8,false,this,receiverMails);
       ui->tableView->setModel(model);
    }
}
//点击listWidget时改变stackWidget的页面内容
void Widget::on_listWidget_clicked(const QModelIndex &index)
{
    int i=ui->listWidget->currentRow();
    //stack->setCurrentIndex(i);
    ui->stackedWidget->setCurrentIndex(i);
}

//窗口大小变化响应函数
void Widget::resizeEvent(QResizeEvent *event)
{
    //改变窗口大小时使listWIdget中的字的大小自适应
    ui->listWidget->setSpacing(ui->listWidget->width()/10);

    //窗口大小变化使改变重新初始化Model
//    TableModel* model=new TableModel(100,10,this);
//    ui->tableView->setModel(model);
//    ui->tableView->horizontalHeader()->setStretchLastSection(true);

}

//选择全选时改变状态
void Widget::on_checkBox_stateChanged(int arg1)
{
    for(int i=0;i<model->m_dataList.count();i++){
        QModelIndex indexNow =model->index(i, 0);
        if(ui->checkBox->isChecked()){
            model->setData(indexNow,Qt::Checked,Qt::CheckStateRole);
        }else{
            model->setData(indexNow,Qt::Unchecked,Qt::CheckStateRole);
        }

    }
//    ui->tableViewMail->setModel(model);

}

//选中邮件后的事件处理
//void Widget::on_tableViewMail_doubleClicked(const QModelIndex &index)
//{
//    //选中邮件后，跳转到读邮件页面
//    ui->stackedWidget->setCurrentIndex(6);
//    //将邮件的具体信息传递过去


//}

//新建群组
void Widget::on_pushButton_2_clicked()
{
    //弹出输入群组名的对话框
    bool ok;
    QString newGroupName=QInputDialog::getText(this,tr("新建组"),
                                               tr("组名:"),QLineEdit::Normal,
                                               QDir::home().dirName(),&ok);

    //将新建的群组名添加到listWidget中去
    if(ok&&!newGroupName.isEmpty()){
        DataBase db;
        if(!db.groupConfig(nowUser.getUserName(),newGroupName)){
            QMessageBox::about(this,"提示","该群组已存在");
        }else{
            QListWidgetItem *item=new QListWidgetItem();
            item->setText(newGroupName);
            item->setFont(QFont("Ubuntu", 15));
            item->setTextAlignment(Qt::AlignHCenter);
            ui->listWidgetBook->addItem(item);
            //将新建的群组名添加到数据库中
            DataBase db;
            db.addGroup(nowUser.getUserName(),newGroupName);
        }
    }

}

//更新联系人tableModel的数据
void Widget::on_listWidgetBook_itemClicked(QListWidgetItem *item)
{
    int row;
    row=ui->listWidgetBook->currentRow();
    if(row==0){
        DataBase db;
        QList<Contact> contactAll;
        contactAll=db.selectContact(nowUser.getUserName());

        modelBook=new TableModelBook(100,8,false,this,contactAll);
        ui->tableViewAllBook->setModel(modelBook);
    }else{
        QString selectGroupName=item->text();
        QList<Contact> contactList;
        DataBase db;
        contactList=db.selectContactByGroup(nowUser.getUserName(),selectGroupName);
        modelBook=new TableModelBook(100,8,false,this,contactList);
        ui->tableViewAllBook->setModel(modelBook);
        //根据群组名查询数据库中该群组下的联系人
    }

}

void Widget::on_tableViewAllBook_doubleClicked(const QModelIndex &index)
{
    //将该页面的收件人赋值为该联系人
      QMap<int,QVariant> i=modelBook->itemData(index);
      QString receiverName=i.find(0)->toString();

     ui->lineEditRecipient->setText(receiverName);

     //双击联系人列表转到给该联系人发邮件的页面
     ui->stackedWidget->setCurrentIndex(0);


}
//在通讯录中添加联系人
void Widget::on_addContactBtn_clicked()
{
    addContactDialog=new buildContactDlg();
    addContactDialog->exec();
    QString contactAddress=addContactDialog->newContactName;
    QString groupName=addContactDialog->newContactGroup;
    QString secondName=addContactDialog->newContactNick;
    DataBase db;
    if(contactAddress!=NULL&&groupName!=NULL&&secondName!=NULL){
        if(db.userConfirm(contactAddress)&&contactAddress!=NULL){
            QMessageBox::about(this,"提示","该邮箱地址不存在");
        }
        else if(!db.contactConfim(nowUser.getUserName(),contactAddress)){
            QMessageBox::about(this,"提示","该联系人已添加");
        }
        else{
            Contact *newContact=new  Contact(nowUser.getUserName(), contactAddress, groupName, secondName, NULL);
            //将联系人存入数据库中
            DataBase db;
            db.addContact(nowUser.getUserName(),contactAddress,secondName,groupName);

            modelBook->m_dataList.append(*newContact);
            QList<Contact> contactList=modelBook->m_dataList;
            modelBook=new TableModelBook(100,8,false,this,contactList);
            ui->tableViewAllBook->setModel(modelBook);
            //该群组不存在则新建该群组
            if(db.groupConfig(nowUser.getUserName(),groupName)){
                QListWidgetItem *item=new QListWidgetItem();
                item->setText(groupName);
                item->setFont(QFont("Ubuntu", 15));
                item->setTextAlignment(Qt::AlignHCenter);
                ui->listWidgetBook->addItem(item);
                //将新建的群组名添加到数据库中
                DataBase db;
                db.addGroup(nowUser.getUserName(),groupName);
            }
        }
    }


}
//删除当前群组
void Widget::on_deleteGroupBtn_clicked()
{
    if(ui->listWidgetBook->currentRow()==0){
        //全部群组
        QMessageBox msgBox;
         msgBox.setText("该群组不能删除请选择其他群组");
         msgBox.exec();
    }else{
        if(ui->listWidgetBook->currentItem()!=0x0){
            //获得当前群组名称
             QListWidgetItem *item=ui->listWidgetBook->currentItem();
             QString nowGroupName=ui->listWidgetBook->currentItem()->text();
             int row;
             row=ui->listWidgetBook->currentRow();

             QMessageBox message(QMessageBox::Warning,"Information","确定要删除该群组吗​？",QMessageBox::Yes|QMessageBox::No,NULL);
              if (message.exec()==QMessageBox::Yes){

                  //删除该群组及其内的所有联系人
                   //删除对应数据库中的数据
                  DataBase db;
                  db.deleteGroup(nowUser.getUserName(),nowGroupName);
                  db.groupDelete(nowUser.getUserName(),nowGroupName);
                  //页面显示全部联系人列表
                  QList<Contact> allContactList;
                  allContactList=db.selectContact(nowUser.getUserName());

                  modelBook=new TableModelBook(100,8,false,this,allContactList);
                  ui->tableViewAllBook->setModel(modelBook);

                  ui->listWidgetBook->setCurrentRow(0);
                  qDebug()<<item->text();

                  ui->listWidgetBook->takeItem(row);

              }
        }else{
            //当前群组名为空弹出提示框
            QMessageBox msgBox;
             msgBox.setText("请选择要删除的群组");
             msgBox.exec();
        }
    }


}



//彻底删除邮件
void Widget::on_deleteCompleteBtn_clicked()
{

    QMap<int,Qt::CheckState> modelMap=model->rowCheckStateMap;
    if(modelMap.count()>0){
        QList<int> deleteComMailId;//彻底删除邮件列表
        QList<Mail> dataList;//新生成的数据列表
        QMap<int,Qt::CheckState>::const_iterator i;
        for( i=modelMap.constBegin(); i!=modelMap.constEnd(); ++i)  {
            auto v=model->m_dataList.at(i.key());
            int j=v.getMailId();
             deleteComMailId.append(j);
        }

        for(int i=0;i<model->m_dataList.count();i++){
            auto v = model->m_dataList.at(i);
            int j=v.getMailId();
            if(!deleteComMailId.contains(j)){
               dataList.append(model->m_dataList.at(i));
            }
        }

        //在数据库中删除这一项
        DataBase db;
        db.mailDelete(deleteComMailId);
        //在显示列表中删除这一项
        model=new TableModel(100,8,false,this,dataList);
       ui->tableView->setModel(model);
    }else{
        QMessageBox::about(this,"提示","请选择要彻底删除的邮件");
    }



}

//不彻底删除邮件
void Widget::on_deleteCheckedBtn_clicked()
{
     QMap<int,Qt::CheckState> modelMap=model->rowCheckStateMap;
    if(modelMap.count()==0){
        QMessageBox::about(this,"提示","请选择要删除的邮件");
    }else{

        QList<int> deleteComMails;//彻底删除邮件列表
        QList<Mail> deleteList;
        QMap<int,Qt::CheckState>::const_iterator i;
        for( i=modelMap.constBegin(); i!=modelMap.constEnd(); ++i)  {
            auto v=model->m_dataList.at(i.key());
            int j=v.getMailId();
            deleteComMails.append(j);
        }
        for(int i=0;i<model->m_dataList.count();i++){
            auto v = model->m_dataList.at(i);
            int j=v.getMailId();
            if(!deleteComMails.contains(j)){
                deleteList.append(model->m_dataList.at(i));
            }
            else{
                modelRubbish->m_dataList.append(v);
            }
        }
        //在数据库中删除这一项
        DataBase db;
        db.mailRemove(deleteComMails);

        model=new TableModel(100,8,false,this,deleteList);
        ui->tableView->setModel(model);
        //在垃圾箱中显示该项

        QList<Mail> rubbishList;
        rubbishList=modelRubbish->m_dataList;

        modelRubbish=new TableModelRubbish(100,8,false,this,rubbishList);
        ui->tableViewRubbish->setModel(modelRubbish);
    }


}


//标记为全读
void Widget::on_markAllReadedBtn_clicked()
{

    QList<int> list;
    QList<Mail> dataList;
    for(int i=0;i<model->m_dataList.count();i++){

        Mail v=model->m_dataList.at(i);
        list.append(v.getMailId());
        v.setReaded(1);
        dataList.append(v);
    }

    //在数据库中改变每一项的读取状态
    DataBase db;
    db.mailReaded(list);
    //改变每一行显示的读取状态
    model=new TableModel(100,8,false,this,dataList);
    ui->tableView->setModel(model);
}

//删除草稿
void Widget::on_deleteDraft_clicked()
{
    QMap<int,Qt::CheckState> modelMap=modelDraft->rowCheckStateMap;
    if(modelMap.count()>0){

           QMessageBox message(QMessageBox::Warning,"Information","Really to clear data?",QMessageBox::Yes|QMessageBox::No,NULL);
            if (message.exec()==QMessageBox::Yes)
            {
             QList<int> deleteComDraftMailId;//彻底删除草稿箱邮件列表
             QList<Mail> dataList;//新生成的数据列表
             QMap<int,Qt::CheckState>::const_iterator i;
             for( i=modelMap.constBegin(); i!=modelMap.constEnd(); ++i)  {
                 auto v=modelDraft->m_dataList.at(i.key());
                 int j=v.getMailId();
                 deleteComDraftMailId.append(j);
             }

             for(int i=0;i<modelDraft->m_dataList.count();i++){
                 auto v = modelDraft->m_dataList.at(i);
                 int j=v.getMailId();
                 if(!deleteComDraftMailId.contains(j)){
                    dataList.append(modelDraft->m_dataList.at(i));
                 }
             }

             //在数据库中删除这一项
             DataBase db;
             db.mailDelete(deleteComDraftMailId);
             //在显示列表中删除这一项
             modelDraft=new TableModelDraft(100,8,false,this,dataList);
             ui->tableViewDraft->setModel(modelDraft);
         }


    }else{
        QMessageBox::about(this,"提示","请选择要删除的草稿");//提示用户选择要删除的草稿
    }

}
//写邮箱发送按钮
void Widget::on_sendMailBtn_clicked()
{
    //获取发送的邮件信息
    QString senderName;
    QString receiverName;
    QString content;
    QString theme;
    senderName=nowUser.getUserName();//将发件人改为当前用户的名字
    receiverName=ui->lineEditRecipient->text();
    theme=ui->lineEditTheme->text();
    content=ui->textEditContent->toPlainText();
    DataBase db;
    if(!db.userConfirm(receiverName)){

        Mail *mail=new Mail(theme,content,senderName,receiverName);

        //将新建邮件存到数据库中

        if(db.mailCreate(mail)){
    //        QMessageBox msgBox;
    //         msgBox.setText("邮件发送成功");
    //         msgBox.exec();
             QMessageBox::about(this,"提示","邮件发送成功");//提示用户邮件发送状态
        }else{
    //        QMessageBox msgBox;
    //         msgBox.setText("邮件发送失败");
    //         msgBox.exec();
             QMessageBox::about(this,"提示","邮件发送失败");
        }


        ui->lineEditRecipient->setText("");
        ui->lineEditTheme->setText("");
        ui->textEditContent->setText("");
        //可以考虑跳转到已发送界面
        //更新已发送页面的内容

        modelSended->m_dataList.append(*mail);

        QList<Mail> sendedList;
        sendedList=modelSended->m_dataList;

        modelSended=new tablemodelSended(100,8,false,this,sendedList);
        ui->tableViewSended->setModel(modelSended);
        ui->stackedWidget->setCurrentIndex(4);
    }
    else{
         QMessageBox::about(this,"提示","该联系人不存在");
    }

}

//在写邮件时将邮件存为草稿
void Widget::on_saveDraftBtn_clicked()
{

    //获取草稿邮件信息
    QString senderName;
    QString receiverName;
    QString content;
    QString theme;
    senderName=nowUser.getUserName();//将发件人改为当前用户的名字
    receiverName=ui->lineEditRecipient->text();
    theme=ui->lineEditTheme->text();
    content=ui->textEditContent->toPlainText();

    Mail *mail=new Mail(theme,content,senderName,receiverName);
    mail->setDraft(1);

    //将新建邮件存到数据库中
    DataBase db;
    if(db.mailCreate(mail)){

         QMessageBox::about(this,"提示","存为草稿成功");//提示用户邮件发送状态
    }else{

         QMessageBox::about(this,"提示","存为草稿失败");
    }

    //重新设置modelDraft
    QList<Mail> draftList;
    draftList=modelDraft->m_dataList;
    draftList.append(*mail);
    modelDraft=new TableModelDraft(100,10,false,this,draftList);
    ui->tableViewDraft->setModel(modelDraft);

    ui->stackedWidget->setCurrentIndex(3);
}

//双击草稿箱的主题会跳转回写信页面

void Widget::on_tableViewDraft_doubleClicked(const QModelIndex &index)
{
    int row=index.row();//获取行号

     Mail nowDraftMail=modelDraft->m_dataList.at(row);
     ui->stackedWidget->setCurrentIndex(0);//跳转到写信页面
     //并且补全内容
     ui->lineEditRecipient->setText(nowDraftMail.getReceiverName());
     ui->lineEditTheme->setText(nowDraftMail.getTheme());
     ui->textEditContent->setText(nowDraftMail.getContent());
     //删除该草稿
     QList<Mail> draftDelete;
     for(int i=0;i<modelDraft->m_dataList.count();i++){
         if(i!=row){
             draftDelete.append(modelDraft->m_dataList.at(i));
         }
     }
     Mail mail=modelDraft->m_dataList.at(row);
     int id=mail.getMailId();
     QList<int> mailId;
     mailId.append(id);
     DataBase db;
     db.mailDelete(mailId);

     modelDraft=new TableModelDraft(100,10,false,this,draftDelete);
     ui->tableViewDraft->setModel(modelDraft);
}

//双击收信箱页面会跳转到读取页面内容页面
void Widget::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    Mail mail=model->m_dataList.at(row);
    ui->stackedWidget->setCurrentIndex(6);//跳转到读取页面内容页面
    nowReadMailId=mail.getMailId();//记录读取邮件的ID
    //获取页面内容
    ui->labelSender->setText(mail.getSenderName());
    ui->labelTheme->setText(mail.getTheme());
    ui->textEditReadContent->setText(mail.getContent());
    ui->labelTIem->setText(mail.getTime());
    //将该消息在数据库中标为已读
    QList<int> readedList;
    readedList.append(mail.getMailId());
    DataBase db;
    db.mailReaded(readedList);
    mail.setReaded(1);
    model->m_dataList.insert(row,mail);
    model->m_dataList.removeAt(row+1);
    QList<Mail> mailList=model->m_dataList;
    model=new TableModel(100,8,false,this,mailList);
    ui->tableView->setModel(model);

}
//回复发件人发来的邮件
void Widget::on_replyBtn_clicked()
{
    //获取收件人姓名
    QString receiverName=ui->labelSender->text();
     ui->stackedWidget->setCurrentIndex(0);//跳转到写信页面
    ui->lineEditRecipient->setText(receiverName);
}
//删除该邮件
void Widget::on_deleteMailBtn_clicked()
{
    QMessageBox message(QMessageBox::Warning,"Information","确定要删除该邮件吗？删除后可在垃圾箱中找到该邮件",QMessageBox::Yes|QMessageBox::No,NULL);
     if (message.exec()==QMessageBox::Yes){

         QList<int> mailId;
        mailId.append(nowReadMailId);

         //移除该邮件到垃圾箱
         DataBase db;
         db.mailRemove(mailId);
           Mail rubbish;
         //在收件箱中是删除该邮件
         QList<Mail> mailList;
         for(int i=0;i<model->m_dataList.count();i++){
             Mail v=model->m_dataList.at(i);
             if(v.getMailId()!=mailId.at(0)){
                 mailList.append(model->m_dataList.at(i));
             }
             else{
                 rubbish=v;
             }
         }

         model=new TableModel(100,8,false,this,mailList);
         ui->tableView->setModel(model);

         //将该邮件添加到垃圾箱中

           modelRubbish->m_dataList.append(rubbish);
         QList<Mail> rubbishList;
         rubbishList=modelRubbish->m_dataList;

         modelRubbish=new TableModelRubbish(100,8,false,this,rubbishList);
         ui->tableViewRubbish->setModel(modelRubbish);

         ui->stackedWidget->setCurrentIndex(5);//跳转到写信页面
         ui->labelSender->setText("");
         ui->labelTheme->setText("");
         ui->textEditReadContent->setText("");
     }

}

//删除所选的已发送页面中的邮件
void Widget::on_deleteSendMailBtn_clicked()
{
    QMap<int,Qt::CheckState> modelMap=modelSended->rowCheckStateMap;
    if(modelMap.count()>0){

           QMessageBox message(QMessageBox::Warning,"Information","确定要删除所选择的邮件吗？",QMessageBox::Yes|QMessageBox::No,NULL);
            if (message.exec()==QMessageBox::Yes)
            {
             QList<int> deleteComDraftMailId;//彻底删除已发送邮件列表
             QList<Mail> dataList;//新生成的数据列表
             QMap<int,Qt::CheckState>::const_iterator i;
             for( i=modelMap.constBegin(); i!=modelMap.constEnd(); ++i)  {
                 auto v=modelSended->m_dataList.at(i.key());
                 int j=v.getMailId();
                 deleteComDraftMailId.append(j);
             }


             for(int i=0;i<modelSended->m_dataList.count();i++){
                 auto v = modelSended->m_dataList.at(i);
                 int j=v.getMailId();
                 if(!deleteComDraftMailId.contains(j)){
                    dataList.append(modelSended->m_dataList.at(i));
                 }
             }

             //在数据库中删除这一项
             DataBase db;
             db.mailDelete(deleteComDraftMailId);
             //在显示列表中删除这一项
             modelSended=new tablemodelSended(100,8,false,this,dataList);
             ui->tableViewSended->setModel(modelSended);
         }


    }else{
        QMessageBox::about(this,"提示","请选择要删除的邮件");//提示用户选择要删除的草稿
    }
}
//垃圾箱彻底删除
void Widget::on_pushButton_clicked()
{
    QMap<int,Qt::CheckState> modelMap=modelRubbish->rowCheckStateMap;
    if(modelMap.count()>0){

           QMessageBox message(QMessageBox::Warning,"Information","确定要彻底删除所选的邮件吗？彻底删除后将不能恢复邮件",QMessageBox::Yes|QMessageBox::No,NULL);
            if (message.exec()==QMessageBox::Yes)
            {
             QList<int> deleteComDraftMailId;//彻底删除已发送邮件列表
             QList<Mail> dataList;//新生成的数据列表
             QMap<int,Qt::CheckState>::const_iterator i;
             for( i=modelMap.constBegin(); i!=modelMap.constEnd(); ++i)  {
                 auto v=modelRubbish->m_dataList.at(i.key());
                 int j=v.getMailId();
                 deleteComDraftMailId.append(j);
             }

             for(int i=0;i<modelRubbish->m_dataList.count();i++){
                 auto v = modelRubbish->m_dataList.at(i);
                 int j=v.getMailId();
                 if(!deleteComDraftMailId.contains(j)){
                    dataList.append(modelRubbish->m_dataList.at(i));
                 }
             }

             //在数据库中删除这一项
             DataBase db;
             db.mailDelete(deleteComDraftMailId);
             //在显示列表中删除这一项
             modelRubbish=new TableModelRubbish(100,8,false,this,dataList);
             ui->tableViewRubbish->setModel(modelRubbish);
         }
    }else{
        QMessageBox::about(this,"提示","请选择要删除的邮件");//提示用户选择要删除的草稿
    }
}

//修改昵称
void Widget::on_modifyName_clicked()
{
    ui->personalName->setFocusPolicy(Qt::StrongFocus);
}



void Widget::on_pushButton_8_clicked()
{
    QString newName=ui->personalName->text();
    QString newPhoneNum=ui->phoneNum->text();
    QString newPassword=ui->password->text();
    QString newComfirmPwd=ui->comfirmPwd->text();
    if(newName==NULL||newPhoneNum==NULL||newPassword==NULL){
         QMessageBox::about(this,"提示","信息不能为空");
    }else{
        if(newPassword!=nowUser.getPassword()){
            if(newPassword!=newComfirmPwd){
                //两个密码不相同
                QMessageBox::about(this,"提示","两次密码输入不相同，请输入相同的密码");
                ui->password->setText("");
                ui->comfirmPwd->setText("");
            }
        }else{
            nowUser.setNickName(newName);
            nowUser.setPassword(newPassword);
            nowUser.setPhoneNum(newPhoneNum);
            ui->personalNameLabel->setText(newName);
            DataBase db;
            if(db.updateInformation(nowUser,nowUser.getUserName())){
                QMessageBox::about(this,"提示","修改成功");
            }
        }

    }

}
//修改电话号码
void Widget::on_pushButton_5_clicked()
{
    ui->phoneNum->setFocusPolicy(Qt::StrongFocus);
}

//修改密码
void Widget::on_pushButton_6_clicked()
{
    ui->password->setFocusPolicy(Qt::StrongFocus);
    ui->comfirmPwdLabel->setVisible(true);
    ui->comfirmPwd->setVisible(true);
}

void Widget::on_listWidget_itemClicked(QListWidgetItem *item)
{

}


//个人信息按钮点击转换到个人信息页面
void Widget::on_personImfBtn_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}
//点击注销按钮回到登陆页面
void Widget::on_quitBtn_clicked()
{
    this->close();
    mailDlg.exec();
}

//删除联系人
void Widget::on_deleteContactBtn_clicked()
{
    QMap<int,Qt::CheckState> modelMap=modelBook->rowCheckStateMap;
    if(modelMap.count()>0){

           QMessageBox message(QMessageBox::Warning,"Information","确定要删除该联系人吗​？",QMessageBox::Yes|QMessageBox::No,NULL);
            if (message.exec()==QMessageBox::Yes)
            {
             QList<QString> deleteComDraftMailId;//彻底删除已发送邮件列表
             QList<Contact> dataList;//新生成的数据列表
             for(int i=0;i<modelBook->rowCheckStateMap.count();i++){
                 if(modelMap.value(i)==Qt::Checked){
                     auto v = modelBook->m_dataList.at(i);
                     QString j=v.getLinkmanName();
                     deleteComDraftMailId.append(j);
                 }
             }

             for(int i=0;i<modelBook->m_dataList.count();i++){
                 auto v = modelBook->m_dataList.at(i);
                 QString j=v.getLinkmanName();
                 if(!deleteComDraftMailId.contains(j)){
                    dataList.append(modelBook->m_dataList.at(i));
                 }
             }

             //在数据库中删除这一项
             DataBase db;
             db.contactListDelete(deleteComDraftMailId);
             //在显示列表中删除这一项
             modelBook=new TableModelBook(100,8,false,this,dataList);
             ui->tableViewAllBook->setModel(modelBook);
         }
    }else{
        QMessageBox::about(this,"提示","请选择要删除的联系人");
    }
}






void Widget::on_checkBoxAllBook_stateChanged(int arg1)
{
    for(int i=0;i<modelBook->m_dataList.count();i++){
        QModelIndex indexNow =modelBook->index(i, 0);
        if(ui->checkBoxAllBook->isChecked()){
            modelBook->setData(indexNow,Qt::Checked,Qt::CheckStateRole);
        }else{
            modelBook->setData(indexNow,Qt::Unchecked,Qt::CheckStateRole);
        }

    }
}

void Widget::on_checkBoxAllDraft_stateChanged(int arg1)
{
    for(int i=0;i<modelDraft->m_dataList.count();i++){
        QModelIndex indexNow =modelDraft->index(i, 0);
        if(ui->checkBoxAllDraft->isChecked()){
            modelDraft->setData(indexNow,Qt::Checked,Qt::CheckStateRole);
        }else{
            modelDraft->setData(indexNow,Qt::Unchecked,Qt::CheckStateRole);
        }

    }
}

void Widget::on_checkBoxAllSelect_stateChanged(int arg1)
{
    for(int i=0;i<modelSended->m_dataList.count();i++){
        QModelIndex indexNow =modelSended->index(i, 0);
        if(ui->checkBoxAllSelect->isChecked()){
            modelSended->setData(indexNow,Qt::Checked,Qt::CheckStateRole);
        }else{
           modelSended->setData(indexNow,Qt::Unchecked,Qt::CheckStateRole);
        }

    }
}



void Widget::on_checkBoxRubbish_stateChanged(int arg1)
{
    for(int i=0;i<modelRubbish->m_dataList.count();i++){
        QModelIndex indexNow =modelRubbish->index(i, 0);
        if(ui->checkBoxRubbish->isChecked()){
            modelRubbish->setData(indexNow,Qt::Checked,Qt::CheckStateRole);
        }else{
           modelRubbish->setData(indexNow,Qt::Unchecked,Qt::CheckStateRole);
        }

    }
}



void Widget::on_tableViewRubbish_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    Mail mail=modelRubbish->m_dataList.at(row);
    ui->stackedWidget->setCurrentIndex(6);//跳转到读取页面内容页面
    nowReadMailId=mail.getMailId();//记录读取邮件的ID
    //获取页面内容
    ui->labelSender->setText(mail.getSenderName());
    ui->labelTheme->setText(mail.getTheme());
    ui->textEditReadContent->setText(mail.getContent());
    ui->labelTIem->setText(mail.getTime());
    //将该消息在数据库中标为已读
    QList<int> readedList;
    readedList.append(mail.getMailId());
    DataBase db;
    db.mailReaded(readedList);
    mail.setReaded(1);
    modelRubbish->m_dataList.insert(row,mail);
    modelRubbish->m_dataList.removeAt(row+1);
    QList<Mail> mailList=modelRubbish->m_dataList;
    modelRubbish=new TableModelRubbish(100,8,false,this,mailList);
    ui->tableViewRubbish->setModel(modelRubbish);
}


//在读取页面中添加该发件人为联系人
void Widget::on_addNowContactBtn_clicked()
{
    DataBase db;
    QString linkManName=ui->labelSender->text();
    if(db.contactConfim(nowUser.getUserName(),linkManName)){
        Contact *newContact=new Contact(nowUser.getUserName(),linkManName);

        db.addContact(nowUser.getUserName(),linkManName,"","");
        QList<Contact> contactList;
        contactList=db.selectContact(nowUser.getUserName());
        modelBook=new TableModelBook(100,8,false,this,contactList);
        ui->tableViewAllBook->setModel(modelBook);
    }else{
         QMessageBox::about(this,"提示","该联系人已添加");
    }

}
