/*
    What
    QOBJECT Macro

    Why
    Tells MOC to convert the class into a true QObject
    Basically adds signals and slots along with meta data type info

    How
    Comment out QOBJECT Macro
*/

#include <QCoreApplication>
#include "test.h"

void lifecycle()
{
    Test t;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    lifecycle();

    return a.exec();
}
