/*

  What
  Reading large files

  Why
  ReadAll is not a great idea
  Break it into smaller parts

  How
  QFile::readline
  Qfile::read

 */

#include <QCoreApplication>
#include <QFile>

void readLines(QFile &file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.readLine(); // \n
    }
}

void readChunks(QFile &file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.read(25);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; //create this manually

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) //reads the file can not modify it
    {
        //Read line by line
        readLines(file);


        qInfo() << "-------------------";

        //Read chunks
        readChunks(file);

        file.close();

    }
    else
    {
        qInfo() << file.errorString();
    }


    return a.exec();
}
