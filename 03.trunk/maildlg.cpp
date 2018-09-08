#include "maildlg.h"
#include "ui_maildlg.h"
#include "widget.h"
#include <QList>
#include <QDebug>
#include "user.h"
#include "database.h"
#include "widget.h"


MailDlg::MailDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MailDlg)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    // 去掉标题栏,去掉任务栏显示，窗口置顶
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);


    /*先打开一个图像；
      将图像文件加载进QImage对象中；
      再用QPixmap对象获得图像；
      最后用QLabel选择一个QPixmap图像对象显示。*/
    QString filename(":/new/Images/背景图.png");
    QImage* img = new QImage;
    int width = img->width(),
        height = img->height();
    if(!(img->load(filename))) // 加载图像
    {
        QMessageBox::information(this,
                     tr("打开图像失败"),
                     tr("打开图像失败!"));
        delete img;
        return;
    }
    // 修改label的大小
    ui->backgroundlabel->resize(width,height);
    ui->backgroundlabel->setGeometry(0,0,430,150);
    // 根据图片的大小缩放到合适的大小显示
    img->scaled(width,height,Qt::KeepAspectRatio);

    ui->backgroundlabel->setPixmap(QPixmap::fromImage(*img));
}

MailDlg::~MailDlg()
{
    delete ui;
}

void MailDlg::on_LoginBtn_clicked()
{
    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
    const QString userName = ui->UserLineEdit->text();
    const QString password = ui->PasswordLineEdit->text();
    QMessageBox messBox;
    DataBase db;

   /* QList<User> list = db.doSelectUser();
    qDebug()<<list.size();*/

    if(userName==""){
        messBox.setText("请输入用户名!");
        messBox.exec();
    }
    else if(password == ""){
        messBox.setText("请输入密码!");
        messBox.exec();
    }
    else{
        int flag=0;

        User user = db.selectUserByUserName(userName);
        if(user.getUserName()==""&&user.getPassword()==""){
            messBox.setText("该用户不存在!");
            messBox.exec();
        }
        else if(user.getPassword()==password)
        {
            Widget *mainDlg = new Widget(NULL, &user);
            mainDlg->setWindowModality(Qt::ApplicationModal);
            //mainDlg->setAttribute(Qt::WA_ShowModal, true);
            mainDlg->show();

            // 加载QSS样式
           // CommonHelper::setStyle("cssStyle.qss");
            QFile qss(":/new/qss/cssStyle.qss");
            qss.open(QFile::ReadOnly);
            mainDlg->setStyleSheet(qss.readAll());
            qss.close();

            ui->PasswordLineEdit->clear();
            this->close();// 关闭登录窗口
        }
        else if(user.getPassword()!=password)
        {
            messBox.setText("密码错误!");
            messBox.exec();
        }

    }
}

void MailDlg::on_RegisterBtn_clicked()
{
    regDlg.exec();
}
