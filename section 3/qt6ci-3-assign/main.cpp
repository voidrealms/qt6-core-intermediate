/*
    What
    Assignment

    Why
    Practice what you have learned

    How
    Play around with a QObject

*/

#include <QCoreApplication>

void testcopy(QObject obj)
{
    qDebug() << &obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("Bryan");

    qDebug() << &person;
    testcopy(person);


    return a.exec();
}
