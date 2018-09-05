#include "maildlg.h"
#include "widget.h"
#include <QApplication>
#include <QFile>
#include "database.h"

int main(int argc, char *argv[])
{
    DataBase db;
    db.connectDB();
    QApplication a(argc, argv);
    MailDlg w;
    w.show();

    return a.exec();
}
