/*

  What
  Reading files

  Why
  How to read files

  How
  QFile

 */

#include <QCoreApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString filename = "test.txt";
    QFile file(filename);

    qInfo() << "Exists:" << file.exists();

    if(file.open(QIODevice::ReadOnly))
    {
        //Small files only!!!
        qInfo() << file.readAll();

        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    return a.exec();
}
