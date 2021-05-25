/*

  What
  Run another thread

  Why
  We have a powerful computer, lets use it

  How
  QObject::moveToThread

 */

#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QScopedPointer>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThread worker;
    worker.setObjectName("Worker Thread");

    qInfo() << "Starting work" << QThread::currentThread();
    //Task *task = new Task(&a);
    QScopedPointer<Task> t(new Task()); //Auto delete
    Task *task = t.data();
    task->moveToThread(&worker);

    worker.connect(&worker,&QThread::started, task,&Task::work);
    //Connect to QThread::finished if you need to know when the thread is done

    worker.start();
    qInfo() << "Free to do other things..." << QThread::currentThread();

    return a.exec();
}
