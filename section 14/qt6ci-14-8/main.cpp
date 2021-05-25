/*

  What
  Exploring our process lifecycle

  Why
  To see how we interact with the world

  How
  main function
  QCoreApplication

 */

#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Args:";
    for(int i = 0; i < argc; i++)
    {
        qInfo() << argv[i];
    }

    QTimer::singleShot(6000,&a, SLOT(quit()));

    int code = a.exec();
    qInfo() << "Code" << code;

    return code;
}
