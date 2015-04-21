#pragma once
#include <QString>
#include "linkedStack.h"
#include "arrayStack.h"
#include "stack.h"

class Calculator
{
    public:
        Calculator();
        double calculate(const QString &expression);

    private:
        bool isOperation(char symbol);
        double count(double previous, double current, char operation);
        bool isDigit(char symbol);
};

