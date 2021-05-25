/*

  What
  Navigate Directories Recursively

  Why
  We need to know whats in all the directories

  How
  QDir

 */

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QDir &root)
{
    qInfo() << "---Listing---";
    foreach(QFileInfo fi, root.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot,QDir::Name))
    {
        if(fi.isDir()) qInfo() << "Dir" << fi.filePath();
        if(fi.isFile()) qInfo() << "File" << fi.filePath();

        if(fi.isDir())
        {
            QDir child(fi.filePath());
            qInfo() << "Inspecting:" << child.absolutePath();
            list(child);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();
    list(dir);

    return a.exec();
}
