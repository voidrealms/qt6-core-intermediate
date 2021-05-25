/*

  What
  Threads intro

  Why
  We need to understand threads

  How
  View our current thread

 */

#include <QCoreApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *thread = QThread::currentThread();
    thread->setObjectName("Main Thread");

    qInfo() << "Starting" << thread;

    for(int i = 0; i < 10; i++)
    {
        qInfo() << i << "on" << thread;
    }
    qInfo() << "Finished" << thread;



    return a.exec();
}
