/*
    What
    QObject

    Why
    Its the base class for (almost) everything
    Also reviews the basics

    How
    QDebug
    Class lifecycle
    Application life cycle
    Event loops


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
