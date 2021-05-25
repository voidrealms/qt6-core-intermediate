/*
    What
    Signals and slots

    Why
    Easy communication between QObjects

    How
    Two objects talking

*/

#include <QCoreApplication>
#include "test.h"

void notifications()
{
    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    //You have to connect the two objects
    //Dont make multiple connections to the same signal and slot unless you want multiple calls
    //Notice the icons
    //Can have a connection type
    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::AutoConnection);

    mom.testing();
    //child.wake("NOW");
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    notifications();

    return a.exec();
}
