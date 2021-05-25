/*

  What
  TypeDef

  Why
  Make your own data types

  How
  Really its more of an alias

 */

#include <QCoreApplication>
#include <QDebug>
#include <QMap>

typedef QMap<QString,int> People;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    People p;
    p.insert("Bryan", 45);
    p.insert("Tammy", 50);
    p.insert("Rango", 15);

    foreach(auto k, p.keys())
    {
        qInfo() << k << p[k];
    }

    return a.exec();
}
