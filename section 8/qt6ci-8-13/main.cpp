/*

  What
  Reading streams of data

  Why
  Data Encoding!

  How
  QDataStream

 */

#include <QCoreApplication>
#include <QFile>
#include <QDataStream>

bool write(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
        return false;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_0);

    int age = 45;
    QString name = "Bryan";
    double weight = 185.06;

    stream << age << name << weight;


    qInfo() << "Writing file";

    stream << age << name << weight;
    if(!file.flush())
    {
        qInfo() << file.errorString();
        file.close();
        return false;
    }

    qInfo() << "Closing file";

    file.close();

    return true;
}

bool read(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        return false;
    }


    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_0)
    {
        qInfo() << "Wrong file version";
        file.close();
        return false;
    }

    int age;
    QString name;
    double weight;

    stream >> age;
    stream >> name;
    stream >> weight;

    file.close();

    qInfo() << "Name" << name;
    qInfo() << "Age" << age;
    qInfo() << "Weight" << weight;


    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString filename = "test.txt";

    if(write(filename)) read(filename);

    return a.exec();
}
