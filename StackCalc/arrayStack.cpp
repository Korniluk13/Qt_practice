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
}

int ArrayStack::size()
{
    return stackArray.size();
}
