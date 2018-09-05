#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QResizeEvent>
#include <QSize>
#include <QIcon>
#include <QListWidgetItem>
#include <QMessageBox>
#include "tablemodel.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    QString userName;
    explicit Widget(QWidget *parent = 0, QString username = NULL);
    ~Widget();

private slots:
    void on_listWidget_clicked(const QModelIndex &index);


    void on_checkBox_stateChanged(int arg1);


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_sendMailBtn_clicked();

    void on_saveDraftBtn_clicked();

private:
    Ui::Widget *ui;
    // QWidget interface


    // QWidget interface


    // QWidget interface


    // QWidget interface
   TableModel* model;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // WIDGET_H
