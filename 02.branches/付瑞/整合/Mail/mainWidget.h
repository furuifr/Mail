#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>

namespace Ui {
class MainDlg;
}

class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString username=NULL);
    ~Widget();

private:
    Ui::MainDlg *ui;

};

#endif // MAINDLG_H
