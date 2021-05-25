#include "consumer.h"

Consumer::Consumer(QObject *parent) : QObject(parent)
{
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Consumer::~Consumer()
{
    qInfo() << "Deconstructed" << this << "on" << QThread::currentThread();
}

void Consumer::consume(int value)
{
    qInfo() << "Consumed" << value << "on" << QThread::currentThread();
}
