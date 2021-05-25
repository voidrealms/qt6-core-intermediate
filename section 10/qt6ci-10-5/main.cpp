/*

  What
  Hex

  Why
  Hexadecimal numeral system is a positional numeral system that represents numbers using a radix of 16

  How
  QByteArray again!

 */

#include <QCoreApplication>
#include <QDebug>

QString makeData() {
    QString data;
    for(int i = 0; i < 10; i++) {
        data.append("Hello\r\n");
    }
    return  data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toHex();
    QByteArray decoded = QByteArray::fromHex(encoded);

    qInfo() << "Encoded:" << encoded;
    qInfo(" --------------------------------------- ");
    qInfo() << "Decoded:" << decoded;

    return a.exec();
}
