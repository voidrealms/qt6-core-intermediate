/*

  What
  Sorting a container

  Why
  We want things in order

  How
  qSort is deprecated
  use std sort

 */

#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QRandomGenerator>

void randoms(QList<int> *list, int max)
{
    list->reserve(max);
    for(int i = 0; i < max; i++)
    {
        int value = QRandomGenerator::global()->bounded(1000);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    randoms(&list,10);

    qInfo() << "Unsorted:" << list;

    //qSort - do not use

    std::sort(list.begin(),list.end());
    qInfo() << "Sorted:" << list;

    std::reverse(list.begin(),list.end());
    qInfo() << "Reversed:" << list;




    return a.exec();
}
