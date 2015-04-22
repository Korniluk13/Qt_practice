#pragma once

#include <vector>

#include "stack.h"

class ArrayStack : public Stack
{
public:
    ~ArrayStack() override;
    void push(int value);
    int pop();
    int size() const;

private:
    std::vector<int> stackArray;
};
