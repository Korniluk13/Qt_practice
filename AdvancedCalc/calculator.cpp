#include "calculator.h"

double Calculator::count(double firstNumber, QChar operation, double secondNumber)
{
    if (operation == '+')
        return firstNumber + secondNumber;
    if (operation == '-')
        return firstNumber - secondNumber;
    if (operation == '*')
        return firstNumber * secondNumber;
    if (operation == '/')
        return firstNumber / secondNumber;
}
