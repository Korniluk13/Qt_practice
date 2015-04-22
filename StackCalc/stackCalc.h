#pragma once

#include <QString>
#include "stack.h"

///Class that provides stack calculator for postfix expression
class StackCalc
{
public:
    ///Constructor with define stack for stack calculator
    StackCalc(Stack *stack);

    ///Calculating postfix expression from string
    double calculate(const QString &expression);

private:
    Stack *calcStack;
};
