/*

    What
    Locking a file to once instance

    Why
    There can be only one

    How
    QLockFile
 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLockFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Attempting to lock a file...";

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    QFile file(path);
    QLockFile lock(file.fileName() +"l");
    lock.setStaleLockTime(15000);

    if(lock.tryLock())
    {
        qInfo() << "Putting into file...";
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray data;
            data.append("Hello World");
            file.write(data);
            file.close();
            qInfo() << "Finished with file...";
            //Took over X seconds here, auto unlock
        }
        qInfo() << "Unlocking file";
       lock.unlock(); //Comment out to see it lock
    }
    else
    {
        qInfo() << "Could not lock the file!";
        qint64 pid;
        QString host;
        QString application;

        if(lock.getLockInfo(&pid,&host,&application)) {
            qInfo() << "The file is locked by:";
            qInfo() << "Pid: " << pid;
            qInfo() << "Host: " << host;
            qInfo() << "Application: " << application;

        } else {
            qInfo() << "File is locked, but we can't get the info!";
        }
    }

    return a.exec();
}
