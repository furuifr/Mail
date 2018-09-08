#ifndef BUILDCONTACTDLG_H
#define BUILDCONTACTDLG_H

#include <QDialog>

namespace Ui {
class buildContactDlg;
}

class buildContactDlg : public QDialog
{
    Q_OBJECT

public:
    explicit buildContactDlg(QWidget *parent = 0);
    ~buildContactDlg();

    QString newContactName;
    QString newContactGroup;
    QString newContactNick;

private slots:
    void on_OKBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::buildContactDlg *ui;
};

#endif // BUILDCONTACTDLG_H
