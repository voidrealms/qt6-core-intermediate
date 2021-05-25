/*

  What
  QVector

  Why
  Historical code

  How
  QVector is now an alias for QList
  https://www.qt.io/blog/qlist-changes-in-qt-6
  https://doc.qt.io/qt-6/qvector.html

 */
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> v;
    v << 1 << 2 << 3;
    qInfo() << v;

    foreach(int i, v)
    {
        qInfo() << i;
    }

    return a.exec();
}
