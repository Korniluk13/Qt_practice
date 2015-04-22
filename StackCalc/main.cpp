#include "stackTest.h"
#include "calcTest.h"

int main()
{
    StackTest stackTest;
    QTest::qExec(&stackTest);

    CalcTest calcTest;
    QTest::qExec(&calcTest);

    return 0;
}

