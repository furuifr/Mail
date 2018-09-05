#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QResizeEvent>
#include <QSize>
#include <QIcon>
#include <QListWidgetItem>
#include "tablemodel.h"
#include "database.h"
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_listWidget_clicked(const QModelIndex &index);


    void on_checkBox_stateChanged(int arg1);


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_sendMailBtn_clicked();

    void on_saveDraftBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_showReceiveBtn_clicked();

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
