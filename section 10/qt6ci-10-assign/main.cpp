/*

  What
  Encode and decode base64

  Why
  Practice what you have learned

  How
  QByteArray

 */

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello my name is Bryan";
    QByteArray encoded = data.toUtf8().toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << encoded;
    qInfo() << "------------------------------";
    qInfo() << decoded;

    return a.exec();
}
