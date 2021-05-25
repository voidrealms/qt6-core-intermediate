/*

  What
  Base 64

  Why
  We want to transmit special characters
  Some protocols use special characters that can cause issues

  How
  Base64 is a group of similar binary-to-text encoding schemes that represent binary data in an ASCII string format by translating it into a radix-64 representation.
  The term Base64 originates from a specific MIME content transfer encoding.
  Each Base64 digit represents exactly 6 bits of data. Three 8-bit bytes (i.e., a total of 24 bits) can therefore be represented by four 6-bit Base64 digits.

*/

#include <QCoreApplication>

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
    QByteArray encoded = bytes.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded:" << encoded;
    qInfo(" --------------------------------------- ");
    qInfo() << "Decoded:" << decoded;


    return a.exec();
}
