QT += testlib

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    linkedStack.cpp \
    arrayStack.cpp \
    stackCalc.cpp

HEADERS += \
    stack.h \
    linkedStack.h \
    arrayStack.h \
    stackTest.h \
    stackCalc.h \
    calcTest.h

