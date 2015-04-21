#pragma once
#include "stack.h"
#include <iostream>
using namespace std;

template <typename T> class ArrayStack : public Stack<T>
{
    public:
        ArrayStack(int maxSize)
        {
            currentSize = 0;
            arrayStack = new T[maxSize];
        }

        ~ArrayStack()
        {
            currentSize = 0;
            delete []arrayStack;
        }

        void push(T value)
        {
            currentSize++;
            arrayStack[currentSize - 1] = value;
        }

        T pop()
        {
            T result = arrayStack[currentSize - 1];
            currentSize--;
            return result;
        }

        void print()
        {
            for (int i = 0; i < currentSize; i++)
                cout << arrayStack[i] << " ";
            cout << endl;
        }

        int size()
        {
            return currentSize;
        }

    private:
        int currentSize;
        T *arrayStack;
};
