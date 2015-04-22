#pragma once

#include "stack.h"

///Class that provides stack on pointers
class LinkedStack : public Stack
{
public:
    LinkedStack();
    ~LinkedStack() override;
    void push(int value);
    int pop();
    int size();

private:
    struct StackElement
    {
        int value;
        StackElement *next;

        StackElement(int newValue)
        {
            value = newValue;
            next = nullptr;
        }
    };

    StackElement *top;
    int currentSize;
};

