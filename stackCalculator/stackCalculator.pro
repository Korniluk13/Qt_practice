QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    calculator.cpp

HEADERS += \
    stack.h \
    arrayStack.h \
    linkedStack.h \
    calculator.h \
    stackTest.h \
    calculatorTest.h

QMAKE_CXXFLAGS += -std=c++0x
