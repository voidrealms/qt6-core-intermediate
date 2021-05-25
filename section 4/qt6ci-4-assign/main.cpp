/*

  What
  Section 4 Assignment

  Why
  Practice what you have learned

  How
  Use a Qt smart pointer


 */


#include <QCoreApplication>
#include <QSharedPointer>
#include <QScopedPointer>
#include "test.h"

Test* getObject()
{
    return new Test(nullptr,"Test");
}

void test()
{
    QScopedPointer<Test> ptr(getObject());
    qInfo() << ptr.data();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
