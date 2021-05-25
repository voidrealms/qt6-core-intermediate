/*

  What
  QSet

  Why
  Fast lookup

  How
  Almost identical API
  https://doc.qt.io/qt-6/qset.html

 */

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Bryan" << "Tammy" << "Chris" << "Heather";
    people.insert("Rango");

    //Notice this is out of order - and no duplicates
    foreach(QString person, people) {
        qInfo() << person;
    }

    //Very very fast
    qInfo() << "Bryan in collection?" << people.contains("Bryan");

    return a.exec();
}
