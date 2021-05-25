/*

  What
  Get file info

  Why
  We want to know details about a file or folder

  How
  QFileInfo

 */

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDateTime>
#include <QDebug>

void list(QString path)
{
    qInfo() << "List:" << path;

    QDir dir(path);
    QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList files = dir.entryInfoList(QDir::Files);

    foreach(QFileInfo fi, dirs)
    {
        qInfo() << fi.fileName();
    }

    foreach(QFileInfo fi, files)
    {
        qInfo() << "..Name: " << fi.fileName();
        qInfo() << "...Size: " << fi.size();
        qInfo() << "...Created: " << fi.birthTime();
        qInfo() << "...Modified: " << fi.lastModified();
    }

    foreach(QFileInfo fi, dirs) {
        list(fi.absoluteFilePath());
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    list(QDir::tempPath());

    qInfo() << "Done";

    return a.exec();
}
