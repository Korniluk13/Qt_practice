#-------------------------------------------------
#
# Project created by QtCreator 2015-03-12T21:30:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clock
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++0x
