#include "addcontact.h"
#include "ui_addcontact.h"

AddContact::AddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContact)
{
    ui->setupUi(this);
}

AddContact::~AddContact()
{
    delete ui;
}

void AddContact::on_pushButton_clicked()
{

    newContactGroup = ui->lineEditAddGroup->text();
    newContactNick = ui->lineEditAddSecond->text();


   ui->lineEditAddGroup->clear();
   ui->lineEditAddSecond->clear();

   this->close();
}

void AddContact::on_pushButton_2_clicked()
{
    ui->lineEditAddGroup->clear();
    ui->lineEditAddSecond->clear();

    this->close();
}
