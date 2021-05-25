/*

  What
  Data compression

  Why
  We want to reduce the data size

  How
  qCompress
  qUncompress

 */

#include <QCoreApplication>

void display(QString title, QByteArray &bytes)
{
    qDebug() << "---" << title << "---";
    qDebug() << "Length:" << bytes.size();
    qDebug() << "Plain:" << bytes;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data("This is my very long and annoy data,This is my very long and annoy data,This is my very long and annoy data,This is my very long and annoy data,This is my very long and annoy data");

    QByteArray compressed = qCompress(data,9);
    QByteArray decompressed = qUncompress(compressed);

    display("Original", data);
    display("Compressed", compressed);
    display("Decompressed", decompressed);

    return a.exec();
}
