/*

  What
  Deleting all pointers in a container

  Why
  C++ requires us to manage pointers

  How
  qDeleteAll

 */

#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Test*> list;
    for(int i = 0; i < 10; i++)
    {
        Test *t = new Test(); //no parent, no smart pointer
        t->setObjectName(QString::number(i));
        list.append(t);

    }

    qInfo() << list.at(0);

    qDeleteAll(list);
    qInfo() << "Count: " << list.count();

   // qInfo() << list.at(0); //Will crash
    qInfo() << "Clearing...";
    list.clear();

    qInfo() << "Count: " << list.count();

    return a.exec();
}
