/********************************************************************************
** Form generated from reading UI file 'maildlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILDLG_H
#define UI_MAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MailDlg
{
public:
    QPushButton *LoginBtn;
    QLabel *usernamelabel;
    QLineEdit *UserLineEdit;
    QLabel *passwordlabel;
    QLineEdit *PasswordLineEdit;
    QPushButton *RegisterBtn;
    QLabel *backgroundlabel;

    void setupUi(QDialog *MailDlg)
    {
        if (MailDlg->objectName().isEmpty())
            MailDlg->setObjectName(QStringLiteral("MailDlg"));
        MailDlg->resize(430, 330);
        LoginBtn = new QPushButton(MailDlg);
        LoginBtn->setObjectName(QStringLiteral("LoginBtn"));
        LoginBtn->setGeometry(QRect(121, 271, 80, 34));
        LoginBtn->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        usernamelabel = new QLabel(MailDlg);
        usernamelabel->setObjectName(QStringLiteral("usernamelabel"));
        usernamelabel->setGeometry(QRect(97, 165, 68, 29));
        usernamelabel->setMinimumSize(QSize(60, 29));
        usernamelabel->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        UserLineEdit = new QLineEdit(MailDlg);
        UserLineEdit->setObjectName(QStringLiteral("UserLineEdit"));
        UserLineEdit->setGeometry(QRect(171, 167, 161, 30));
        passwordlabel = new QLabel(MailDlg);
        passwordlabel->setObjectName(QStringLiteral("passwordlabel"));
        passwordlabel->setGeometry(QRect(97, 217, 67, 26));
        passwordlabel->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        PasswordLineEdit = new QLineEdit(MailDlg);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(171, 217, 161, 30));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);
        RegisterBtn = new QPushButton(MailDlg);
        RegisterBtn->setObjectName(QStringLiteral("RegisterBtn"));
        RegisterBtn->setGeometry(QRect(250, 271, 80, 34));
        RegisterBtn->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        RegisterBtn->setIconSize(QSize(30, 16));
        backgroundlabel = new QLabel(MailDlg);
        backgroundlabel->setObjectName(QStringLiteral("backgroundlabel"));
        backgroundlabel->setGeometry(QRect(190, 70, 67, 17));

        retranslateUi(MailDlg);

        QMetaObject::connectSlotsByName(MailDlg);
    } // setupUi

    void retranslateUi(QDialog *MailDlg)
    {
        MailDlg->setWindowTitle(QApplication::translate("MailDlg", "MailDlg", nullptr));
        LoginBtn->setText(QApplication::translate("MailDlg", "\347\231\273\345\275\225", nullptr));
        usernamelabel->setText(QApplication::translate("MailDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        passwordlabel->setText(QApplication::translate("MailDlg", "\345\257\206    \347\240\201\357\274\232", nullptr));
        RegisterBtn->setText(QApplication::translate("MailDlg", "\346\263\250\345\206\214", nullptr));
        backgroundlabel->setText(QApplication::translate("MailDlg", "\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MailDlg: public Ui_MailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILDLG_H
