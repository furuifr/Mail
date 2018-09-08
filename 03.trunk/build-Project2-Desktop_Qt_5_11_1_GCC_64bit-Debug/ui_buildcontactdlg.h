/********************************************************************************
** Form generated from reading UI file 'buildcontactdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDCONTACTDLG_H
#define UI_BUILDCONTACTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_buildContactDlg
{
public:
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *newContactName;
    QLabel *label;
    QPushButton *OKBtn;
    QLineEdit *newContactNick;
    QPushButton *cancelBtn;
    QLineEdit *newContactGroup;
    QLabel *label_4;

    void setupUi(QDialog *buildContactDlg)
    {
        if (buildContactDlg->objectName().isEmpty())
            buildContactDlg->setObjectName(QStringLiteral("buildContactDlg"));
        buildContactDlg->resize(400, 300);
        label_3 = new QLabel(buildContactDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 158, 61, 26));
        label_3->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        label_2 = new QLabel(buildContactDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 111, 61, 26));
        label_2->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        newContactName = new QLineEdit(buildContactDlg);
        newContactName->setObjectName(QStringLiteral("newContactName"));
        newContactName->setGeometry(QRect(160, 61, 161, 30));
        label = new QLabel(buildContactDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 62, 61, 26));
        label->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        OKBtn = new QPushButton(buildContactDlg);
        OKBtn->setObjectName(QStringLiteral("OKBtn"));
        OKBtn->setGeometry(QRect(114, 210, 80, 34));
        OKBtn->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        newContactNick = new QLineEdit(buildContactDlg);
        newContactNick->setObjectName(QStringLiteral("newContactNick"));
        newContactNick->setGeometry(QRect(160, 158, 161, 30));
        cancelBtn = new QPushButton(buildContactDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(239, 210, 80, 34));
        cancelBtn->setStyleSheet(QStringLiteral("font: 13pt \"Ubuntu\";"));
        newContactGroup = new QLineEdit(buildContactDlg);
        newContactGroup->setObjectName(QStringLiteral("newContactGroup"));
        newContactGroup->setGeometry(QRect(160, 110, 161, 30));
        label_4 = new QLabel(buildContactDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 20, 91, 17));

        retranslateUi(buildContactDlg);

        QMetaObject::connectSlotsByName(buildContactDlg);
    } // setupUi

    void retranslateUi(QDialog *buildContactDlg)
    {
        buildContactDlg->setWindowTitle(QApplication::translate("buildContactDlg", "Dialog", nullptr));
        label_3->setText(QApplication::translate("buildContactDlg", "\345\244\207   \346\263\250  \357\274\232", nullptr));
        label_2->setText(QApplication::translate("buildContactDlg", "\347\276\244   \347\273\204  \357\274\232", nullptr));
        label->setText(QApplication::translate("buildContactDlg", "\351\202\256   \347\256\261  \357\274\232", nullptr));
        OKBtn->setText(QApplication::translate("buildContactDlg", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QApplication::translate("buildContactDlg", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QApplication::translate("buildContactDlg", "\346\267\273\345\212\240\346\226\260\350\201\224\347\263\273\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buildContactDlg: public Ui_buildContactDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDCONTACTDLG_H
