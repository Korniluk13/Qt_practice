#include "arrayStack.h"

ArrayStack::~ArrayStack()
{
    stackArray.clear();
}

void ArrayStack::push(int value)
{
    stackArray.push_back(value);
}

int ArrayStack::pop()
{
    if (stackArray.size() > 0)
    {
        int back = stackArray.back();
        stackArray.pop_back();
        return back;
    }
    else
        throw StackException("Empty stack");
}

int ArrayStack::size() const
{
    return stackArray.size();
}
