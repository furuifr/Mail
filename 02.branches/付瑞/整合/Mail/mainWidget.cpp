#include "mainWidget.h"
#include "ui_maindlg.h"

MainDlg::MainDlg(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::MainDlg)
{
    ui->setupUi(this);
    ui->UserNameLabel->setText(username);
}

MainDlg::~MainDlg()
{
    delete ui;
}
