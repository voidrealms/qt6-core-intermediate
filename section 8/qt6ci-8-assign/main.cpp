/*

  What
  Practice what you have learned

  Why
  Working with files is fundamental

  How
  Open a file, write and read it

*/

#include <QCoreApplication>
#include <QTemporaryFile>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTemporaryFile file;
    if(file.open())
    {
        qInfo() << "File:" << file.fileName();

        QByteArray dataout("Hello World");
        file.write(dataout);
        file.flush();
        file.seek(0);
        qInfo() << file.readAll();
        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    return a.exec();
}
