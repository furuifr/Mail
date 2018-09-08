#-------------------------------------------------
#
# Project created by QtCreator 2018-09-02T12:28:48
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
QT       +=core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    tablemodel.cpp \
    widget.cpp \
    tablemodelbook.cpp \
    mail.cpp \
    database.cpp \
    user.cpp \
    tablemodeldraft.cpp \
    tablemodelsended.cpp \
    tablemodelrubbish.cpp \
    contact.cpp \
    maildlg.cpp \
    registerdlg.cpp \
    group.cpp \
    buildcontactdlg.cpp \
    addcontact.cpp

HEADERS += \
    mail.h \
    tablemodel.h \
    widget.h \
    tablemodelbook.h \
    database.h \
    user.h \
    tablemodeldraft.h \
    tablemodelsended.h \
    tablemodelrubbish.h \
    contact.h \
    maildlg.h \
    registerdlg.h \
    group.h \
    buildcontactdlg.h \
    addcontact.h

FORMS += \
    widget.ui \
    maildlg.ui \
    registerdlg.ui \
    buildcontactdlg.ui \
    addcontact.ui

DISTFILES +=

RESOURCES += \
    styleprc.qrc
