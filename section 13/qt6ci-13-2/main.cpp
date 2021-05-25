/*

  What
  Filling a container

  Why
  We want to populate a container

  How
  qFill is deprecated
  use a QList or STD fill

 */

#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 1 << 2 << 3 << 4;

   // qFill() = do not use

    list.fill(9);
    qInfo() << list;

    list.resize(12);
    std::fill(list.begin(),list.end(),-1);
    qInfo() << list;

    return a.exec();
}
