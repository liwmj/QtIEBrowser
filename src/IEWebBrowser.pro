#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T10:17:56
#
#-------------------------------------------------

QT       += core gui
CONFIG += qaxcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtIEBrowser
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    iewebview.cpp \
    ieaxwidget.cpp

HEADERS  += widget.h \
    iewebview.h \
    ieaxwidget.h
