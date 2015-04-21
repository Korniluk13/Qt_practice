#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "linkedStack.h"
#include "arrayStack.h"

class StackTest: public QObject
{
    Q_OBJECT

public:
    explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        linkedStack = new LinkedStack<int>;
        arrayStack = new ArrayStack<int>(10);
    }

    void cleanup()
    {
        delete linkedStack;
        delete arrayStack;
    }

    void testEmptyLinkedStack()
    {
        QVERIFY(linkedStack->size() == 0);
    }

    void testEmptyArrayStack()
    {
        QVERIFY(arrayStack->size() == 0);
    }

    void testSizeLinkedStack()
    {
        linkedStack->push(1);
        QVERIFY(linkedStack->size() == 1);
    }

    void testSizeArrayStack()
    {
        arrayStack->push(1);
        QVERIFY(arrayStack->size() == 1);
    }

    void testAdditionLinkedStack()
    {
        linkedStack->push(1);
        QVERIFY(linkedStack->pop() == 1);
    }

    void testAdditionArrayStack()
    {
        arrayStack->push(1);
        QVERIFY(arrayStack->pop() == 1);
    }

private:
    LinkedStack<int> *linkedStack;
    ArrayStack<int> *arrayStack;
};
