#include "stackCalc.h"

StackCalc::Calculator(Stack *stack) : calcStack(stack)
{}

double StackCalc::calculate(const QString &str)
{
    int currentPosition = 0;
    const int length = expression.length();
    while (currentPosition < length)
    {
        if (isOperation(expression[currentPosition].toLatin1()))
        {
            const char operation = expression[currentPosition].toLatin1();
            const double current = calcStack->pop();
            const double previous = calcStack->pop();
            const double result = count(previous, current, operation);
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

    const double result = calcStack->pop();
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
    return (symbol >= '0' && symbol <= '9');
}
