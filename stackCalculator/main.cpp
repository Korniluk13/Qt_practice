#include <iostream>
using namespace std;
#include <fstream>
#include "calculator.h"
#include "stackTest.h"

int main()
{
    StackTest stackTest;
    QTest::qExec(&stackTest);

    ifstream input("input.txt");
    if (!input.is_open())
    {
        cout << "File doesn't exist";
        return 0;
    }

    Calculator *calc = new Calculator;
    cout << calc->calculate(input) << endl;
    return 0;
}

