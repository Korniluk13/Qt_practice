#pragma once

template <typename T>
class Stack
{
    public:
        virtual ~Stack() {}
        virtual void push(T value) = 0;
        virtual T pop() = 0;
        virtual void print() = 0;
        virtual int size() = 0;
};

