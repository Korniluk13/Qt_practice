#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedStack.h"
#include "arrayStack.h"

class StackTest : public QObject
{
    Q_OBJECT
public:
    explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        linkedStack = new LinkedStack;
        arrayStack = new ArrayStack;
    }

    void cleanup()
    {
        delete linkedStack;
        delete arrayStack;
    }

    void testEmptyStack()
    {
        QCOMPARE(linkedStack->size(), 0);
        QCOMPARE(arrayStack->size(), 0);
    }

    void testPushOneSize()
    {
        linkedStack->push(1);
        QCOMPARE(linkedStack->size(), 1);

        arrayStack->push(13);
        QCOMPARE(arrayStack->size(), 1);
    }

    void testPushSeveralSize()
    {
        for (int i = 0; i < 10; i++)
            linkedStack->push(i);
        QCOMPARE(linkedStack->size(), 10);

        for (int j = 0; j < 15; j++)
            arrayStack->push(j);
        QCOMPARE(arrayStack->size(), 15);
    }

    void testPushPop()
    {
        linkedStack->push(1);
        QCOMPARE(linkedStack->pop(), 1);

        arrayStack->push(12);
        QCOMPARE(arrayStack->pop(), 12);
    }

    void testPushSeveralPop()
    {
        for (int i = 0; i < 10; i++)
            linkedStack->push(i);
        QCOMPARE(linkedStack->pop(), 9);

        for (int j = 0; j < 15; j++)
            arrayStack->push(j);
        QCOMPARE(arrayStack->pop(), 14);
    }

private:
    Stack *linkedStack;
    Stack *arrayStack;
};

