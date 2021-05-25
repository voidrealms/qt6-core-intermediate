/*

  What
  Signals and slots across threads

  Why
  It's not super obvious

  How
  Connection Type

 */

#include <QCoreApplication>
#include <QThread>
#include "producer.h"
#include "consumer.h"

void cleanup()
{
    qInfo() << "Cleanup";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    QThread pthread;
    pthread.setObjectName("Producer Thread");
    Producer *producer = new Producer();
    producer->moveToThread(&pthread);
    QObject::connect(&pthread,&QThread::started,producer,&Producer::start);

    QThread cthread;
    cthread.setObjectName("Consumer Thread");
    Consumer *consumer = new Consumer();
    consumer->moveToThread(&cthread);

    QObject::connect(producer,&Producer::produce,consumer,&Consumer::consume);
    QObject::connect(producer,&Producer::finished,&pthread,&QThread::quit);
    QObject::connect(&pthread,&QThread::finished,&cthread,&QThread::quit);
    QObject::connect(&cthread,&QThread::finished,consumer,&Consumer::deleteLater);
    QObject::connect(&pthread,&QThread::finished,producer,&Producer::deleteLater);
    QObject::connect(&cthread,&QThread::finished,&a,&QCoreApplication::quit);
    QObject::connect(&a,&QCoreApplication::aboutToQuit,&cleanup);

    cthread.start();
    pthread.start();

    return a.exec();
}
