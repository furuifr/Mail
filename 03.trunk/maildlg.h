#ifndef MAILDLG_H
#define MAILDLG_H

#include <QDialog>
#include <QMessageBox>

#include "registerdlg.h"

namespace Ui {
class MailDlg;
}

class MailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MailDlg(QWidget *parent = 0);
    ~MailDlg();

private slots:
    void on_LoginBtn_clicked();

    void on_RegisterBtn_clicked();

private:
    Ui::MailDlg *ui;
    RegisterDlg regDlg;
};

#endif // MAILDLG_H
