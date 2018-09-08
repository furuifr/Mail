/********************************************************************************
** Form generated from reading UI file 'registerdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDLG_H
#define UI_REGISTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDlg
{
public:
    QLabel *label;
    QLineEdit *userLineEdit;
    QLabel *label_2;
    QLineEdit *passwdLineEdit;
    QLabel *label_3;
    QLineEdit *confirmpasswd;
    QPushButton *OKBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *RegisterDlg)
    {
        if (RegisterDlg->objectName().isEmpty())
            RegisterDlg->setObjectName(QStringLiteral("RegisterDlg"));
        RegisterDlg->resize(400, 300);
        label = new QLabel(RegisterDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(63, 61, 81, 23));
        label->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        userLineEdit = new QLineEdit(RegisterDlg);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(161, 61, 161, 30));
        label_2 = new QLabel(RegisterDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(64, 110, 81, 23));
        label_2->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        passwdLineEdit = new QLineEdit(RegisterDlg);
        passwdLineEdit->setObjectName(QStringLiteral("passwdLineEdit"));
        passwdLineEdit->setGeometry(QRect(161, 110, 161, 30));
        passwdLineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(RegisterDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 160, 75, 23));
        label_3->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        confirmpasswd = new QLineEdit(RegisterDlg);
        confirmpasswd->setObjectName(QStringLiteral("confirmpasswd"));
        confirmpasswd->setGeometry(QRect(161, 158, 161, 30));
        confirmpasswd->setEchoMode(QLineEdit::Password);
        OKBtn = new QPushButton(RegisterDlg);
        OKBtn->setObjectName(QStringLiteral("OKBtn"));
        OKBtn->setGeometry(QRect(115, 210, 80, 34));
        OKBtn->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        cancelBtn = new QPushButton(RegisterDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(240, 210, 80, 34));
        cancelBtn->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));

        retranslateUi(RegisterDlg);

        QMetaObject::connectSlotsByName(RegisterDlg);
    } // setupUi

    void retranslateUi(QDialog *RegisterDlg)
    {
        RegisterDlg->setWindowTitle(QApplication::translate("RegisterDlg", "Dialog", nullptr));
        label->setText(QApplication::translate("RegisterDlg", "  \347\224\250  \346\210\267  \345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("RegisterDlg", "    \345\257\206    \347\240\201  \357\274\232", nullptr));
        label_3->setText(QApplication::translate("RegisterDlg", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        OKBtn->setText(QApplication::translate("RegisterDlg", "\346\263\250\345\206\214", nullptr));
        cancelBtn->setText(QApplication::translate("RegisterDlg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDlg: public Ui_RegisterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDLG_H
