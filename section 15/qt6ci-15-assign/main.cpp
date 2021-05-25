/*

  What
  Assignment

  Why
  Pratice what you have learned

  How
  Play with a timer

 */

#include <QCoreApplication>
#include <QTime>
#include <QTimer>

void test()
{
    qInfo() << "Time:" << QTime::currentTime().toString();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer::singleShot(3000,&test);

    return a.exec();
}
