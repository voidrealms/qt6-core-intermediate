/*

  What
  Serialize to XML

  Why
  Retro early 2000s
  Actually XML is widely used

  How
  QXmlStreamWriter
  QXmlStreamReader
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
}

void writeXML(QString path)
{
    Test t;
    t.fill();
    Converter::writeXml(&t, path);
}

void readXML(QString path)
{
    Test *t;
    t = Converter::readXml(path);

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
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    //writeJson(path);
    //readJson(path);

    writeXML(path);
    readXML(path);

    return a.exec();
}
