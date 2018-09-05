#ifndef REGISTERDLG_H
#define REGISTERDLG_H

#include <QDialog>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class RegisterDlg;
}

class RegisterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDlg(QWidget *parent = 0);
    ~RegisterDlg();

     QList<User> userList;

private slots:
    void on_OKBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::RegisterDlg *ui;
};

#endif // REGISTERDLG_H
