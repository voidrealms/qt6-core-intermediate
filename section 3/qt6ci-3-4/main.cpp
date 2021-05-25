/*
    What
    QObjects can not be copied

    Why
    The memory address is the objects identity

    How
    Simple functions

*/

#include <QCoreApplication>

void testPointer(QObject *obj)
{
    qInfo() << obj;
}

void testAddress(QObject &obj)
{
    qInfo() << &obj;
}

void testCopy(QObject obj)
{
    qInfo() << &obj;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("Bryan");

    testPointer(&person);
    testAddress(person);
    testCopy(person); //Deleted copy constructor, move mouse over and see the QObject Q_DISABLE_COPY(QObject) 427:20

    return a.exec();
}
