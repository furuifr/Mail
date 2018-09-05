#include "widget.h"
#include <QApplication>
#include <QtSql>
#include "database.h"

int main(int argc, char *argv[])
{
    DataBase db;
    db.connectDB();

    QApplication a(argc, argv);
    Widget w;
    w.show();

    QFile qss(":/cssStyle.qss");
    qss.open(QFile::ReadOnly);
    w.setStyleSheet(qss.readAll());
    qss.close();

    return a.exec();
}
