#include "linkedStack.h"

using namespace std;

LinkedStack::LinkedStack(): top(nullptr)
{}

LinkedStack::~LinkedStack()
{
    while (top != nullptr)
    {
        StackElement *auxilary = top->next;
        delete top;
        top = auxilary;
    }
    delete top;
}

void LinkedStack::push(int value)
{
    StackElement *current = new StackElement(value);
    current->next = top;
    top = current;
    currentSize++;
}

int LinkedStack::pop()
{
    if (top != nullptr)
    {
        currentSize--;
        StackElement *current = top;
        top = current->next;
        int taken = current->value;
        delete current;
        return taken;
    }
    else
        throw StackException("Empty stack");
}

int LinkedStack::size() const
{
    return currentSize;
}

