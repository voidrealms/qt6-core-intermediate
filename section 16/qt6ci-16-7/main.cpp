/*

  What
  Concurrent

  Why
  Threading is hard and we just want to run code

  How
  QtConcurrent
  This uses QThreadpool for us
  Not returning values and all that stuff is in the advanced course

 */

#include <QCoreApplication>
#include <QtConcurrent>
#include <QThread>
#include <QDebug>
#include <QFuture>

int test()
{
    QThread *thread = QThread::currentThread();

    qInfo() << "Starting" << thread;

    int value = 0;
    for(int i = 0; i < 10; i++)
    {
        qInfo() << i << "on" << thread;
        value = value + i;
    }
    qInfo() << "Finished" << thread;

    return value;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<int> future1 = QtConcurrent::run(&test);
    QFuture<int> future2 = QtConcurrent::run(&test);
    QFuture<int> future3 = QtConcurrent::run(&test);

    qInfo() << "Value1" << future1.result();
    qInfo() << "Value2" << future2.result();
    qInfo() << "Value3" << future3.result();

    return a.exec();
}
