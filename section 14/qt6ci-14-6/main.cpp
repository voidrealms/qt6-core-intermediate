/*

  What
  Working with a process

  Why
  We want to see the exit code

  How
  Its super easy

 */

#include <QCoreApplication>
#include <QDebug>
#include<QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Starting...";
    QProcess proc;
    proc.execute("xed",QStringList() << "http://www.voidrealms.com");
    qInfo() << "Exit code: " << proc.exitCode(); //0 is good, means no errors!

    return a.exec();
}
