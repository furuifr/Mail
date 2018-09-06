#include "registerdlg.h"
#include "ui_registerdlg.h"
#include "user.h"
#include "maildlg.h"
#include "database.h"

RegisterDlg::RegisterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDlg)
{
    ui->setupUi(this);
}

RegisterDlg::~RegisterDlg()
{
    delete ui;
}

void RegisterDlg::on_OKBtn_clicked()
{
    // 输入密码时显示为星号
    ui->passwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmpasswd->setEchoMode(QLineEdit::Password);

    QString userName = ui->userLineEdit->text();
    QString password = ui->passwdLineEdit->text();
    QString conpassword = ui->confirmpasswd->text();

    QMessageBox messBox;


    if(userName == NULL){
        messBox.setText("请输入用户名!");
        messBox.exec();
    }
    else if(userName.length() < 6 || userName.length() > 18){
        messBox.setText("用户名长度为6～18位!");
        messBox.exec();
        ui->userLineEdit->clear();
    }
    else if(password == NULL){
        messBox.setText("请输入密码!");
        messBox.exec();
    }
    else if(password.length() < 6 || password.length() > 16){
        messBox.setText("密码长度为6～16位!");
        messBox.exec();
        ui->passwdLineEdit->clear();
    }
    else if(conpassword == NULL){
        messBox.setText("请再次输入密码!");
        messBox.exec();
    }
    else if(password == conpassword && password != NULL){
        // 检查是否存在该用户
//        QList<User> list = regDlg.userList;
//        for(int i = 0;i < list.size(); i++){
//            User userlist = list.at(i);
//            if(!userlist.getUserName().compare(userName)
//               && !userlist.getPassword().compare(password)){
//                messBox.setText("该用户已存在!");
//                messBox.exec();
//            }
//        }



        const User user(userName,password);
        //userList.append(user);
        DataBase db;
        bool res = db.userRegister(user);

        if(!res){
            QMessageBox::warning(0,"notice",
                                 "Register failed",
                                 QMessageBox::Ok|QMessageBox::Default,
                                 QMessageBox::Cancel|QMessageBox::Escape,0);
        }else {
            QMessageBox::information(0,"notice",
                                 "register succeed",
                                 QMessageBox::Ok|QMessageBox::Default,
                                 QMessageBox::Cancel|QMessageBox::Escape,0);

            ui->userLineEdit->clear();
            ui->passwdLineEdit->clear();
            ui->confirmpasswd->clear();
            this->close();// 关闭注册窗口
        }
    }
    else
    {
        messBox.setText("两次密码不一致!");
        messBox.exec();
        ui->confirmpasswd->clear();
    }
}

void RegisterDlg::on_cancelBtn_clicked()
{
    ui->userLineEdit->clear();
    ui->passwdLineEdit->clear();
    ui->confirmpasswd->clear();
    this->close();// 关闭注册窗口
}
