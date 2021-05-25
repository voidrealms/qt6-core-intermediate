/*

  What
  QScopedPointer

  Why
  Manual memory management is error prone

  How
  See below
*/

#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void test()
{
    QScopedPointer<Test> sp(new Test());
    sp->setObjectName("My Test");

    qInfo() << "Scoped Pointer" << &sp;
    qInfo() << "Pointer Data" << sp.data();
    qInfo() << sp->objectName();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
