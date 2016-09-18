#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T01:09:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FridgeAssistKitV4
TEMPLATE = app


SOURCES += main.cpp\
        welcomescreen.cpp \
    actionmenu.cpp \
    changeinventory.cpp \
    custominput.cpp \
    userlist.cpp \
    mycaledar.cpp

HEADERS  += welcomescreen.h \
    actionmenu.h \
    changeinventory.h \
    custominput.h \
    userlist.h \
    mycaledar.h

FORMS    += welcomescreen.ui \
    actionmenu.ui \
    changeinventory.ui \
    custominput.ui \
    userlist.ui \
    mycaledar.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += \
    pictureslogosandicons.qrc
