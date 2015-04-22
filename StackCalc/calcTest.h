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
    }

    void cleanup()
    {
        delete arrayStack;
    }

    void testEasyExpression()
    {
        QCOMPARE(StackCalc::calculate("1 1 +", arrayStack), 2.0);
    }

    void testComplexExpression1()
    {
        QCOMPARE(StackCalc::calculate("2 1 4 + *", arrayStack), 10.0);
    }

    void testComplexExpression2()
    {
        QCOMPARE(StackCalc::calculate("26 13 5 4 - * /", arrayStack), 2.0);
    }

private:
    Stack *arrayStack;
};
