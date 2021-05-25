/*

  What
  Assignment

  Why
  Practice what you have learned

  How
  QStringView

 */

#include <QCoreApplication>
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p(nullptr,"Bryan","Cairns");
    qInfo() << p.display();


    return a.exec();
}
