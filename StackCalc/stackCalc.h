#pragma once

#include <QString>
#include "stack.h"

///Class that provides stack calculator for postfix expression
class StackCalc
{
public:
    ///Calculating postfix expression from string using define stack
    static double calculate(const QString &expression, Stack *calcStack);
};
