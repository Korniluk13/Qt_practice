#pragma once

#include <QString>
#include "stack.h"

class StackCalc
{
public:
    Calculator(Stack *stack);
    double calculate(const QString &str);

private:
    Stack *calcStack;
};
