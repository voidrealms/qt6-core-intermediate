/*

  What
  Serialize to JSON

  Why
  Sharing with other apps or a human readble format

  How
  QJsonDocument

 */

#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "converter.h"


void writeJson(QString path)
{
    Test t;
    t.fill();
    Converter::writeJson(&t, path);
}

void readJson(QString path)
{
    Test *t;
  
    t = Converter::readJson(path);

    if(!t)
    {
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name:" << t->name();
    foreach(QString key, t->map().keys())
    {
        qInfo() << key << " : " << t->map().value(key);
    }
  
   t.deleteLater();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    writeJson(path);
    readJson(path);

    return a.exec();
}
