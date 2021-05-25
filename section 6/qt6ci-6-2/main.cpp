/*

  What
  QByteArrayView

  Why
  Read only (fast access) to a QByteArray

  How
  Example Code
  https://doc.qt.io/qt-6/qbytearrayview.html

 */

#include <QCoreApplication>
#include <QByteArray>
#include <QByteArrayView>

void display(QByteArrayView &view)
{
    qInfo() << view;
    qInfo() << "Size" << view.size();
    qInfo() << "Data" << view.constData();
    qInfo() << "Slice" << view.sliced(3,6);
    qInfo() << "Contains" << view.contains("ello");
    qInfo() << "At" << view.at(1);
    qInfo() << "Index" << view[0];
    qInfo() << "Indexof" << view.indexOf('e');

    for(auto c : view)
    {
        qInfo() << c;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray bytes("Hello world how are you?");
    QByteArrayView view(bytes);

    display(view);

    return a.exec();
}
