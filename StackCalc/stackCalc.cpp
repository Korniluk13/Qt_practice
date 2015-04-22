#include "stackCalc.h"

bool isOperation(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

double count(double previous, double current, char operation)
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

bool isDigit(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

double StackCalc::calculate(const QString &expression, Stack *calcStack)
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

            const int number = numberInStr.toInt();
            calcStack->push(number);
        }

        currentPosition++;
    }

    return calcStack->pop();
}
