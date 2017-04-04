#-------------------------------------------------
#
# Project created by QtCreator 2017-03-20T18:38:41
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets multimedia multimediawidgets
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += webkit webkitwidgets
QT += webkitwidgets
TARGET = webwiev3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    searchbox.cpp

HEADERS  += mainwindow.h \
    searchbox.h

FORMS    += mainwindow.ui
