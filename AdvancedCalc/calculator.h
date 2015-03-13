#pragma once

#include <QChar>

/**
 * @brief The Calculator class counts expressions
 */
class Calculator
{
    public:
    /**
         * @brief count - counting expression with two numbers and operation
         * @return - result of counting
         */
        double count(double firstNumber, QChar operation, double secondNumber);
};
