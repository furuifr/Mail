/********************************************************************************
** Form generated from reading UI file 'mainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QFrame *line;
    QTableView *tableView;
    QWidget *page_4;
    QLabel *label_3;
    QWidget *page_8;
    QLabel *label_2;
    QWidget *page_5;
    QLabel *label_4;
    QWidget *page_6;
    QLabel *label_5;
    QWidget *page_7;
    QLabel *label_6;
    QWidget *page_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(989, 617);
        Widget->setMinimumSize(QSize(699, 545));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(30, 30, 10, 30);
        listWidget = new QListWidget(Widget);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("\345\206\231\344\277\241\345\233\276\346\240\207");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("../write_email (1).png"), QSize(), QIcon::Normal, QIcon::Off);
            icon.addFile(QStringLiteral("../write_email (1).png"), QSize(), QIcon::Normal, QIcon::On);
            icon.addFile(QStringLiteral("write_email.png"), QSize(), QIcon::Disabled, QIcon::Off);
            icon.addFile(QStringLiteral("write_email.png"), QSize(), QIcon::Disabled, QIcon::On);
            icon.addFile(QStringLiteral("write_email.png"), QSize(), QIcon::Active, QIcon::Off);
            icon.addFile(QStringLiteral("write_email (1).png"), QSize(), QIcon::Active, QIcon::On);
            icon.addFile(QStringLiteral("write_email.png"), QSize(), QIcon::Selected, QIcon::Off);
            icon.addFile(QStringLiteral("../write_email.png"), QSize(), QIcon::Selected, QIcon::On);
        }
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setPointSize(17);
        font.setUnderline(false);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../\344\270\213\350\275\275 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("../\344\270\213\350\275\275.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8("../\344\270\213\350\275\275.png"), QSize(), QIcon::Selected, QIcon::On);
        QFont font1;
        font1.setPointSize(17);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font1);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../\351\200\232\350\256\257\345\275\225 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8("../\351\200\232\350\256\257\345\275\225.png"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font1);
        __qlistwidgetitem2->setIcon(icon2);
        QFont font2;
        font2.setPointSize(12);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem3->setFont(font2);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem4->setFont(font2);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem5->setFont(font2);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget);
        __qlistwidgetitem6->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem6->setFont(font2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(50, 70));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setIconSize(QSize(30, 30));
        listWidget->setSpacing(22);

        horizontalLayout->addWidget(listWidget);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setFocusPolicy(Qt::StrongFocus);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 210, 81, 17));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(page_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        line = new QFrame(page_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        tableView = new QTableView(page_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 15);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 240, 161, 17));
        stackedWidget->addWidget(page_4);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        label_2 = new QLabel(page_8);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 220, 111, 17));
        stackedWidget->addWidget(page_8);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 250, 181, 17));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_5 = new QLabel(page_6);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 250, 141, 17));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        label_6 = new QLabel(page_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 240, 101, 21));
        stackedWidget->addWidget(page_7);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "\345\206\231\344\277\241", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "\346\224\266\344\277\241", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "\351\200\232\350\256\257\345\275\225", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Widget", "\346\224\266\344\273\266\347\256\261", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Widget", "\350\215\211\347\250\277\347\256\261", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Widget", "\345\267\262\345\217\221\351\200\201", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Widget", "\345\236\203\345\234\276\347\256\261", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("Widget", "\345\206\231\344\277\241\351\241\265\351\235\242", nullptr));
        checkBox->setText(QApplication::translate("Widget", "\345\205\250\351\200\211", nullptr));
        label_3->setText(QApplication::translate("Widget", "\351\200\232\350\256\257\345\275\225\351\241\265\351\235\242", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\224\266\344\273\266\347\256\261", nullptr));
        label_4->setText(QApplication::translate("Widget", "\350\215\211\347\250\277\347\256\261\351\241\265\351\235\242", nullptr));
        label_5->setText(QApplication::translate("Widget", "\345\267\262\345\217\221\351\200\201\351\241\265\351\235\242", nullptr));
        label_6->setText(QApplication::translate("Widget", "\345\236\203\345\234\276\347\256\261\351\241\265\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
