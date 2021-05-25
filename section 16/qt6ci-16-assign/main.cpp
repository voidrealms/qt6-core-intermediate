/*

  What
  Assignment

  Why
  Practice what you have learned

  How
  Run a function using Qt concurrent

 */

#include <QCoreApplication>
#include <QtConcurrent>
#include <QThread>
#include <QDebug>
#include <QFuture>

void test()
{
    qInfo() << "Hello World" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<void> f = QtConcurrent::run(&test);

    return a.exec();
}
