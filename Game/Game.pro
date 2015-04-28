#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T17:45:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        widget.cpp \
    gameField.cpp \
    controlPanel.cpp

HEADERS  += widget.h \
    gameField.h \
    controlPanel.h
