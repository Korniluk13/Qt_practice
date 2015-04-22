#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "stackCalc.h"
#include "arrayStack.h"

class CalcTest : public QObject
{
    Q_OBJECT
public:
    explicit CalcTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        arrayStack = new ArrayStack;
        calc = new StackCalc(arrayStack);
    }

    void cleanup()
    {
        delete calc;
        //delete arrayStack;
    }

    void testEasyExpression()
    {
        QCOMPARE(calc->calculate("1 1 +"), 2.0);
    }

    void testComplexExpression1()
    {
        QCOMPARE(calc->calculate("2 1 4 + *"), 10.0);
    }

    void testComplexExpression2()
    {
        QCOMPARE(calc->calculate("26 13 5 4 - * /"), 2.0);
    }

private:
    Stack *arrayStack;
    StackCalc *calc;
};
