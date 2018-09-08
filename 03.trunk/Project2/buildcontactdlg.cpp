#include "buildcontactdlg.h"
#include "ui_buildcontactdlg.h"

buildContactDlg::buildContactDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buildContactDlg)
{
    ui->setupUi(this);
}

buildContactDlg::~buildContactDlg()
{
    delete ui;
}

void buildContactDlg::on_OKBtn_clicked()
{
     newContactName = ui->newContactName->text();
     newContactGroup = ui->newContactGroup->text();
     newContactNick = ui->newContactNick->text();



    ui->newContactName->clear();
    ui->newContactGroup->clear();
    ui->newContactNick->clear();

    this->close();
}

void buildContactDlg::on_cancelBtn_clicked()
{
    ui->newContactName->clear();
    ui->newContactGroup->clear();
    ui->newContactNick->clear();

    this->close();
}

