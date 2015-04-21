#pragma once
#include <fstream>
using namespace std;
#include "linkedStack.h"
#include "arrayStack.h"
#include "stack.h"

class Calculator
{
    public:
        Calculator();
        double calculate(ifstream& input);

    private:
        bool isOperation(char symbol);
        double count(double previous, double current, char operation);
        bool isDigit(char symbol);
};

