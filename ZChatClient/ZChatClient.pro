#-------------------------------------------------
#
# Project created by QtCreator 2025-04-27T21:28:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZChatClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# 添加输出目录和图标文件
RC_ICON = icon.ico
DESTDIR = ./bin
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    global.cpp \
    httpmanager.cpp \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    registerdialog.cpp

HEADERS += \
    global.h \
    httpmanager.h \
        mainwindow.h \
    logindialog.h \
    registerdialog.h \
    singleton.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    registerdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rc.qrc
