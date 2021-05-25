/*

  What
  Assignment

  Why
  Practice what you have learned
  Compression does not always work the way you think it does!

  How
  qCompress and qUncompress

 */

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   // QByteArray data("Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test Test ");

    QByteArray data("Hello World 123");


    QByteArray compressed = qCompress(data,9);
    QByteArray decompressed = qUncompress(compressed);

    qInfo() << "Compressed:" << compressed.size();
    qInfo() << "Decompressed:" << decompressed.size();


    return a.exec();
}
