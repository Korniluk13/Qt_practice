#pragma once

///Abstract class that provides stack
class Stack
{
public:
    ///Pushing element in the stack
    virtual void push(int value) = 0;

    ///Popping element from the stack
    virtual int pop() = 0;

    ///Counting size of the stack
    virtual int size() const = 0;

    ///Destructor for the stack
    virtual ~Stack() {}
};

