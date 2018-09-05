/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
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
    QWidget *pageWrite;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sendMailBtn;
    QPushButton *saveDraftBtn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelRecipient;
    QLineEdit *lineEditRecipient;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelTheme_2;
    QLineEdit *lineEditTheme;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QTextEdit *textEditContent;
    QWidget *pageReceive;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteCompleteBtn;
    QPushButton *deleteCheckedBtn;
    QPushButton *markAllReadedBtn;
    QCheckBox *checkBox;
    QFrame *line;
    QTableView *tableView;
    QWidget *pageBook;
    QLabel *label_2;
    QWidget *pageReceiveBox;
    QLabel *label_4;
    QWidget *pageDraftBox;
    QLabel *label_3;
    QWidget *pageSended;
    QLabel *label_5;
    QWidget *pageRubbish;
    QLabel *label_6;
    QWidget *pageReadMail;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *replyBtn;
    QPushButton *deleteMailBtn;
    QPushButton *addNowContactBtn;
    QComboBox *comboBoxMark;
    QLabel *labelSender;
    QFrame *line_2;
    QLabel *labelTheme;
    QTextEdit *textEdit;
    QWidget *page_9;

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
        pageWrite = new QWidget();
        pageWrite->setObjectName(QStringLiteral("pageWrite"));
        gridLayout_4 = new QGridLayout(pageWrite);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_3 = new QWidget(pageWrite);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("background-color: rgb(252, 175, 62,30);\n"
"\n"
""));
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 168, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        sendMailBtn = new QPushButton(layoutWidget);
        sendMailBtn->setObjectName(QStringLiteral("sendMailBtn"));
        sendMailBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_4->addWidget(sendMailBtn);

        saveDraftBtn = new QPushButton(layoutWidget);
        saveDraftBtn->setObjectName(QStringLiteral("saveDraftBtn"));
        saveDraftBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_4->addWidget(saveDraftBtn);


        verticalLayout_3->addWidget(widget_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelRecipient = new QLabel(pageWrite);
        labelRecipient->setObjectName(QStringLiteral("labelRecipient"));

        horizontalLayout_5->addWidget(labelRecipient);

        lineEditRecipient = new QLineEdit(pageWrite);
        lineEditRecipient->setObjectName(QStringLiteral("lineEditRecipient"));

        horizontalLayout_5->addWidget(lineEditRecipient);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelTheme_2 = new QLabel(pageWrite);
        labelTheme_2->setObjectName(QStringLiteral("labelTheme_2"));

        horizontalLayout_6->addWidget(labelTheme_2);

        lineEditTheme = new QLineEdit(pageWrite);
        lineEditTheme->setObjectName(QStringLiteral("lineEditTheme"));

        horizontalLayout_6->addWidget(lineEditTheme);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(pageWrite);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        textEditContent = new QTextEdit(pageWrite);
        textEditContent->setObjectName(QStringLiteral("textEditContent"));

        horizontalLayout_7->addWidget(textEditContent);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 2);
        verticalLayout_3->setStretch(3, 12);

        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(pageWrite);
        pageReceive = new QWidget();
        pageReceive->setObjectName(QStringLiteral("pageReceive"));
        gridLayout_2 = new QGridLayout(pageReceive);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(pageReceive);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QLatin1String("background-color: rgb(252, 175, 62,30);\n"
"\n"
""));
        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 11, 272, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        deleteCompleteBtn = new QPushButton(layoutWidget1);
        deleteCompleteBtn->setObjectName(QStringLiteral("deleteCompleteBtn"));
        deleteCompleteBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(deleteCompleteBtn);

        deleteCheckedBtn = new QPushButton(layoutWidget1);
        deleteCheckedBtn->setObjectName(QStringLiteral("deleteCheckedBtn"));
        deleteCheckedBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(deleteCheckedBtn);

        markAllReadedBtn = new QPushButton(layoutWidget1);
        markAllReadedBtn->setObjectName(QStringLiteral("markAllReadedBtn"));
        markAllReadedBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(markAllReadedBtn);


        verticalLayout->addWidget(widget);

        checkBox = new QCheckBox(pageReceive);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        line = new QFrame(pageReceive);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        tableView = new QTableView(pageReceive);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 15);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(pageReceive);
        pageBook = new QWidget();
        pageBook->setObjectName(QStringLiteral("pageBook"));
        label_2 = new QLabel(pageBook);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 230, 131, 17));
        stackedWidget->addWidget(pageBook);
        pageReceiveBox = new QWidget();
        pageReceiveBox->setObjectName(QStringLiteral("pageReceiveBox"));
        label_4 = new QLabel(pageReceiveBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 250, 181, 17));
        stackedWidget->addWidget(pageReceiveBox);
        pageDraftBox = new QWidget();
        pageDraftBox->setObjectName(QStringLiteral("pageDraftBox"));
        label_3 = new QLabel(pageDraftBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 250, 67, 17));
        stackedWidget->addWidget(pageDraftBox);
        pageSended = new QWidget();
        pageSended->setObjectName(QStringLiteral("pageSended"));
        label_5 = new QLabel(pageSended);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 250, 141, 17));
        stackedWidget->addWidget(pageSended);
        pageRubbish = new QWidget();
        pageRubbish->setObjectName(QStringLiteral("pageRubbish"));
        label_6 = new QLabel(pageRubbish);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 240, 101, 21));
        stackedWidget->addWidget(pageRubbish);
        pageReadMail = new QWidget();
        pageReadMail->setObjectName(QStringLiteral("pageReadMail"));
        gridLayout_3 = new QGridLayout(pageReadMail);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_2 = new QWidget(pageReadMail);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(252, 175, 62,30);\\n\\n"));
        layoutWidget2 = new QWidget(widget_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 10, 368, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        replyBtn = new QPushButton(layoutWidget2);
        replyBtn->setObjectName(QStringLiteral("replyBtn"));
        replyBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(replyBtn);

        deleteMailBtn = new QPushButton(layoutWidget2);
        deleteMailBtn->setObjectName(QStringLiteral("deleteMailBtn"));
        deleteMailBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(deleteMailBtn);

        addNowContactBtn = new QPushButton(layoutWidget2);
        addNowContactBtn->setObjectName(QStringLiteral("addNowContactBtn"));
        addNowContactBtn->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(addNowContactBtn);

        comboBoxMark = new QComboBox(layoutWidget2);
        comboBoxMark->addItem(QString());
        comboBoxMark->addItem(QString());
        comboBoxMark->addItem(QString());
        comboBoxMark->setObjectName(QStringLiteral("comboBoxMark"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxMark->sizePolicy().hasHeightForWidth());
        comboBoxMark->setSizePolicy(sizePolicy);
        comboBoxMark->setStyleSheet(QStringLiteral("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(comboBoxMark);


        verticalLayout_2->addWidget(widget_2);

        labelSender = new QLabel(pageReadMail);
        labelSender->setObjectName(QStringLiteral("labelSender"));

        verticalLayout_2->addWidget(labelSender);

        line_2 = new QFrame(pageReadMail);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        labelTheme = new QLabel(pageReadMail);
        labelTheme->setObjectName(QStringLiteral("labelTheme"));
        QFont font3;
        font3.setPointSize(20);
        labelTheme->setFont(font3);

        verticalLayout_2->addWidget(labelTheme);

        textEdit = new QTextEdit(pageReadMail);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font3);

        verticalLayout_2->addWidget(textEdit);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 2);
        verticalLayout_2->setStretch(4, 13);

        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(pageReadMail);
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        stackedWidget->addWidget(page_9);

        horizontalLayout->addWidget(stackedWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


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

        sendMailBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        saveDraftBtn->setText(QApplication::translate("Widget", "\345\255\230\350\215\211\347\250\277", nullptr));
        labelRecipient->setText(QApplication::translate("Widget", "\346\224\266\344\273\266\344\272\272", nullptr));
        labelTheme_2->setText(QApplication::translate("Widget", "\344\270\273\351\242\230", nullptr));
        label->setText(QApplication::translate("Widget", "\346\255\243\346\226\207", nullptr));
        deleteCompleteBtn->setText(QApplication::translate("Widget", "\345\275\273\345\272\225\345\210\240\351\231\244", nullptr));
        deleteCheckedBtn->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        markAllReadedBtn->setText(QApplication::translate("Widget", "\345\205\250\351\203\250\346\240\207\344\270\272\345\267\262\350\257\273", nullptr));
        checkBox->setText(QApplication::translate("Widget", "\345\205\250\351\200\211", nullptr));
        label_2->setText(QApplication::translate("Widget", "\351\200\232\350\256\257\345\275\225\351\241\265\351\235\242", nullptr));
        label_4->setText(QApplication::translate("Widget", "\346\224\266\344\273\266\347\256\261", nullptr));
        label_3->setText(QApplication::translate("Widget", "\350\215\211\347\250\277\347\256\261", nullptr));
        label_5->setText(QApplication::translate("Widget", "\345\267\262\345\217\221\351\200\201\351\241\265\351\235\242", nullptr));
        label_6->setText(QApplication::translate("Widget", "\345\236\203\345\234\276\347\256\261\351\241\265\351\235\242", nullptr));
        replyBtn->setText(QApplication::translate("Widget", "\345\233\236\345\244\215", nullptr));
        deleteMailBtn->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        addNowContactBtn->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\350\257\245\350\201\224\347\263\273\344\272\272", nullptr));
        comboBoxMark->setItemText(0, QApplication::translate("Widget", "\346\227\240\346\240\207\350\256\260", nullptr));
        comboBoxMark->setItemText(1, QApplication::translate("Widget", "\346\230\237\346\240\207\351\202\256\344\273\266", nullptr));
        comboBoxMark->setItemText(2, QApplication::translate("Widget", "\345\267\262\350\257\273\351\202\256\344\273\266", nullptr));

        labelSender->setText(QApplication::translate("Widget", "\345\217\221\344\273\266\344\272\272", nullptr));
        labelTheme->setText(QApplication::translate("Widget", "\344\270\273\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
