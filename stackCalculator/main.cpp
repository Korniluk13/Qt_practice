#include <iostream>
using namespace std;
#include <fstream>
#include "calculator.h"
#include "stackTest.h"
#include "calculatorTest.h"

int main()
{
    StackTest stackTest;
    QTest::qExec(&stackTest);

    CalculatorTest calcTest;
    QTest::qExec(&calcTest);

    return 0;
}

