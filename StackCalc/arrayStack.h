#pragma once

#include <vector>
using namespace std;

#include "stack.h"

class ArrayStack : public Stack
{
public:
    ~ArrayStack() override;
    void push(int value);
    int pop();
    int size() const;

private:
    vector<int> stackArray;
};
