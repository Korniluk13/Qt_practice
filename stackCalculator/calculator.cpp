#include "calculator.h"

Calculator::Calculator(){}

double Calculator::calculate(ifstream &input)
{
    Stack<double> *calcStack = new LinkedStack<double>;
    //Stack<double> *calcStack = new ArrayStack<double>(100);

    char operation = ' ';
    double number = 0;
    char oracleChar = input.peek();
    char symbol = ' ';
    while (symbol != '\n')
    {
        if (isDigit(oracleChar))
        {
            input >> number;
            calcStack->push(number);
        }
        else if (isOperation(oracleChar))
        {
            input >> operation;
            double current = calcStack->pop();
            double previous = calcStack->pop();
            double result = count(previous, current, operation);
            calcStack->push(result);
        }
        else
            input.get(symbol);

        oracleChar = input.peek();
    }

    double result = calcStack->pop();
    delete calcStack;
    return result;
}

bool Calculator::isOperation(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

double Calculator::count(double previous, double current, char operation)
{
    if (operation == '+')
        return previous + current;
    if (operation == '-')
        return previous - current;
    if (operation == '*')
        return previous * current;
    if (operation == '/')
        return previous / current;
}

bool Calculator::isDigit(char symbol)
{
    return (symbol - '0' >= 0 && symbol - '0' <= 9);
}




