/*

  What
  Assignment

  Why
  Practice what you have learned

  How
  Make a macro
  It should fill a list with random values

 */

#include <QCoreApplication>
#include <QRandomGenerator>
#include <QList>

#define randlist(list, max)\
    {\
        for(int i = 0; i < list.size(); i++)\
        {\
            list[i] = QRandomGenerator::global()->bounded(max);\
        }\
    }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QList<int> list;
    QList<int> list;
    list.resize(10);
    randlist(list,100);
    qInfo() << list;

    return a.exec();
}
