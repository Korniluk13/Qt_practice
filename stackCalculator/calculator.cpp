#include "calculator.h"

Calculator::Calculator() {}

double Calculator::calculate(const QString &expression)
{
    Stack<double> *calcStack = new LinkedStack<double>;
    //Stack<double> *calcStack = new ArrayStack<double>(100);

    int currentPosition = 0;
    int length = expression.length();
    while (currentPosition < length)
    {
        if (isOperation(expression[currentPosition].toLatin1()))
        {
            char operation = expression[currentPosition].toLatin1();
            double current = calcStack->pop();
            double previous = calcStack->pop();
            double result = count(previous, current, operation);
            calcStack->push(result);
        }

        else if (isDigit(expression[currentPosition].toLatin1()))
        {
            QString numberInStr = "";
            while (currentPosition < length && isDigit(expression[currentPosition].toLatin1()))
            {
                numberInStr += expression[currentPosition].toLatin1();
                currentPosition++;
            }

            int number = numberInStr.toInt();
            calcStack->push(number);
        }

        currentPosition++;
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
    else if (operation == '-')
        return previous - current;
    else if (operation == '*')
        return previous * current;
    else
        return previous / current;
}

bool Calculator::isDigit(char symbol)
{
    return (symbol - '0' >= 0 && symbol - '0' <= 9);
}
