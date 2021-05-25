/*

  What
  Assignment

  Why
  Practice what you have learned

  How
  See below

*/

#include <QCoreApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString app = "xed"; //notepad
    QProcess proc1;
    proc1.start(app);
    proc1.waitForFinished();
    qInfo() << "Exit code:" << proc1.exitCode();

    QProcess proc2;
    proc2.start(app);
    proc2.waitForFinished();
    qInfo() << "Exit code:" << proc2.exitCode();
    return a.exec();
}
