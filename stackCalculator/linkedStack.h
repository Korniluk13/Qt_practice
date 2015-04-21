#pragma once
#include "stack.h"
#include <iostream>
using namespace std;

template <typename T> class LinkedStack: public Stack<T>
{
    public:
        LinkedStack(): top(nullptr), currentSize(0){}

        ~LinkedStack()
        {
            while (top != nullptr)
            {
                StackElement *auxilary = top->next;
                delete top;
                top = auxilary;
            }
            delete top;
        }

        void push(T value)
        {
            StackElement *current = new StackElement(value);
            current->next = top;
            top = current;
            currentSize++;
        }

        T pop()
        {
            if (top != nullptr)
            {
                currentSize--;
                StackElement *current = top;
                top = current->next;
                T taken = current->value;
                delete current;
                return taken;
            }
        }

        void print()
        {
            StackElement *current = top;
            while(current != nullptr)
            {
                cout << current->value << endl;
                current = current->next;
            }
        }

        int size()
        {
            return currentSize;
        }

    private:
        struct StackElement
        {
            T value;
            StackElement *next;

            StackElement(double value)
            {
                this->value = value;
                next = nullptr;
            }
        };

        StackElement *top;
        int currentSize;
};

