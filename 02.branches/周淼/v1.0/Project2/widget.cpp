#include "widget.h"
#include "ui_widget.h"
#include "tablemodel.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include "qmessagebox.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    model=new TableModel(100,8,false,this);
    ui->tableView->setModel(model);
  //  ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setShowGrid(false);
    ui->tableView->setFrameShape(QFrame::NoFrame);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);


    QPalette palette;
    QBrush brush(QColor(252, 175, 62, 50));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
    QBrush brush1(QColor(252, 175, 62, 100));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
    ui->listWidget->setPalette(palette);



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listWidget_clicked(const QModelIndex &index)
{
    int i=ui->listWidget->currentRow();
    //stack->setCurrentIndex(i);
    ui->stackedWidget->setCurrentIndex(i);
}

void Widget::resizeEvent(QResizeEvent *event)
{
    ui->listWidget->setSpacing(ui->listWidget->width()/10);

    TableModel* model=new TableModel(100,10,this);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

}


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
    ui->tableView->setModel(model);

}

void Widget::on_tableView_doubleClicked(const QModelIndex &index)
{

    ui->stackedWidget->setCurrentIndex(7);

}

void Widget::on_sendMailBtn_clicked()
{
    QString mailtheme = ui->lineEditTheme->text();
    QString content = ui->textEditContent->toPlainText();
    QString sendername = "admin";
    QString receivername = ui->lineEditRecipient->text();
    Mail *newmail = new Mail(mailtheme,content,sendername,receivername);

    newmail->setDraft(0);

    DataBase db;
    bool res = db.mailCreate(*newmail);
    if(!res){
        QMessageBox::warning(0,"notice",
                             "fail sending the mail",
                             QMessageBox::Ok|QMessageBox::Default,
                             QMessageBox::Cancel|QMessageBox::Escape,0);
    }else {
        QMessageBox::information(0,"notice",
                             "success sending the mail",
                             QMessageBox::Ok|QMessageBox::Default,
                             QMessageBox::Cancel|QMessageBox::Escape,0);
    }
}

void Widget::on_saveDraftBtn_clicked()
{
    QString mailtheme = ui->lineEditTheme->text();
    QString content = ui->textEditContent->toPlainText();
    QString sendername = "admin";
    QString receivername = ui->lineEditRecipient->text();
    Mail *newmail = new Mail(mailtheme,content,sendername,receivername);

    DataBase db;
    bool res = db.mailDraft(*newmail);
    if(!res){
        QMessageBox::warning(0,"notice",
                             "fail saving the maildraft",
                             QMessageBox::Ok|QMessageBox::Default,
                             QMessageBox::Cancel|QMessageBox::Escape,0);
    }else {
        QMessageBox::information(0,"notice",
                             "success saving the maildraft",
                             QMessageBox::Ok|QMessageBox::Default,
                             QMessageBox::Cancel|QMessageBox::Escape,0);
    }
}
//test QList<Mail>
void Widget::on_pushButton_clicked()
{
//    QString tmp;
//    DataBase db;
//    QList<Mail> mailList = db.receiverMailSelected("zm");
//    tmp = mailList[0].getContent();
//    ui->textEditContent->setText(tmp);

//    QList<int> tmpmailList = {0,1,2};
//    DataBase db ;
//    bool res = db.mailReaded(tmpmailList);
//    if(!res){
//        qDebug()<<"yidushibai";
//    }
    DataBase db;
    QString res = db.groupSelected("zm");
    ui->textEditContent->setText(res);
}

//show mails
void Widget::on_pushButton_2_clicked()
{

}

void Widget::on_showReceiveBtn_clicked()
{
    QString tmp;
    DataBase db;

    QList<Mail> mailList = db.senderMailSelected("admin");
    int len = sizeof(mailList)/sizeof(mailList[0]);
    for(int i =0;i<len;i++){

    }
//    tmp = mailList[0].getContent();
    ui->textEditContent->setText(tmp);

}
