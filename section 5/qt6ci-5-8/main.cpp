/*

  What
  qDeleteAll with QMap

  Why
  QObjects can not be copied

  Example
  See below

 */

#include <QCoreApplication>
#include <QMap>
#include "test.h"

void testMapDelete()
{
    QMap<QString,Test*> map;

    for(int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i);
        QString name = "Item-" + QString::number(i);
        map.insert(id,new Test(nullptr,name));
    }

    foreach(QString key, map.keys())
    {
        qInfo() << key << map[key];
    }

    qDeleteAll(map);
    //qInfo() << list.at(0); //Dangling pointer!
    map.clear();


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testMapDelete();
    return a.exec();
}
