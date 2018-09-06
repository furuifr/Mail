#include "widget.h"
#include "ui_widget.h"
#include "tablemodel.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include "user.h"

Widget::Widget(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->UserNameLabel->setText(username);

    //初始化model中的一些值
     model=new TableModel(100,8,false,this);
    ui->tableViewMail->setModel(model);
  //  ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewMail->resizeColumnsToContents();
    ui->tableViewMail->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewMail->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewMail->horizontalHeader()->setHighlightSections(false);
    ui->tableViewMail->verticalHeader()->setVisible(false);
    ui->tableViewMail->setShowGrid(false);
    ui->tableViewMail->setFrameShape(QFrame::NoFrame);
    ui->tableViewMail->setSelectionMode(QAbstractItemView::SingleSelection);




    //改变listWidget选中时的颜色该为橙色
    QPalette palette;
    QBrush brush(QColor(252, 175, 62, 50));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
    QBrush brush1(QColor(252, 175, 62, 100));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
    ui->listWidget->setPalette(palette);


}

Widget::~Widget()
{
    delete ui;
}


//点击listWidget时改变stackWidget的页面内容
void Widget::on_listWidget_clicked(const QModelIndex &index)
{
    int i=ui->listWidget->currentRow();
    //stack->setCurrentIndex(i);
    ui->stackedWidget->setCurrentIndex(i);
}

//窗口大小变化响应函数
void Widget::resizeEvent(QResizeEvent *event)
{
    //改变窗口大小时使listWIdget中的字的大小自适应
    ui->listWidget->setSpacing(ui->listWidget->width()/10);

    //窗口大小变化使改变重新初始化Model
    TableModel* model=new TableModel(100,10,this);
    ui->tableViewMail->setModel(model);
    ui->tableViewMail->horizontalHeader()->setStretchLastSection(true);

}

//选择全选时改变状态
void Widget::on_checkBox_stateChanged(int arg1)
{
    for(int i=0;i<model->m_dataList.count();i++){
        QModelIndex indexNow =model->index(i, 0);
        if(ui->checkBox->isChecked()){
            model->setData(indexNow,Qt::Checked,Qt::CheckStateRole);
        }else{
            model->setData(indexNow,Qt::Unchecked,Qt::CheckStateRole);
        }

    }
    ui->tableViewMail->setModel(model);

}


void Widget::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(index.row());
}

// 发送邮件
void Widget::on_sendMailBtn_clicked()
{
    QMessageBox messBox;

    // 发件人,收件人,主题,正文需存入数据库,标记为已发送
    QString recipient = ui->lineEditRecipient->text();
    QString theme = ui->lineEditTheme->text();
    QString content = ui->textEditContent->toPlainText();

    if (recipient == NULL){
        messBox.setText("请填写收件人后再发送!");
        messBox.exec();
    }
    else{
        // 发送成功保存到已发送中

        messBox.setText("发送成功!");
        messBox.exec();
    }
}

void Widget::on_saveDraftBtn_clicked()
{
    QMessageBox messBox;

    // 发件人,收件人,主题,正文需存入数据库,标记为存草稿
    QString recipient = ui->lineEditRecipient->text();
    QString theme = ui->lineEditTheme->text();
    QString content = ui->textEditContent->toPlainText();

    messBox.setText("已保存到草稿箱!");
    messBox.exec();

    // 保存到草稿箱
    
}
