#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    number = 0;
    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,&Test::timeout);
}

void Test::timeout()
{
    number++;
    //Qt5
    //qInfo() << QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);
    qInfo() << QTime::currentTime().toString(Qt::DateFormat::TextDate);

    if(number >= 5)
    {
        timer.stop();
        qInfo() << "Complete!";
    }
}

void Test::dostuff()
{
    number = 0;
    timer.start();
}
