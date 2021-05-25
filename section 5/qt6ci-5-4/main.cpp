/*

  What
  QMap

  Why
  Key value pairs

  How
  See below

 */

#include <QCoreApplication>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 37);
    ages.insert("Rango", 15);

    qInfo() << "Keys:" << ages.keys();
    qInfo() << "Values:" << ages.values();
    qInfo() << "Bryan is:" << ages["Bryan"] << "years old";

    ages.remove("Rango");
    qInfo() << "Contains" << ages.contains("Rango");

    foreach(QString key, ages.keys())
    {
        qInfo() << key << " = " << ages[key];
    }

    qInfo() << "Test" << ages.value("Test",-1);

    ages["Bryan"] = 99;
    qInfo() << "Bryan" << ages.value("Bryan",-1);

    ages["Test"] = 222;
    qInfo() << "Test" << ages.value("Test",-1);

    return a.exec();
}
