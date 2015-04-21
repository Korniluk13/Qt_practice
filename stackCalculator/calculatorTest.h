#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT

public:
    explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void emptyCalcTest()
    {
        Calculator calc;
        calc.calculate("");
    }

    void easyCalcTest()
    {
        Calculator calc;
        QVERIFY(calc.calculate("1 1 +") == 2);
    }

    void complexCalcTest()
    {
        Calculator calc;
        QVERIFY(calc.calculate("1 1 + 2 / 13 5 *") == 65);
    }
};
