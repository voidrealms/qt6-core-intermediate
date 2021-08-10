/*

  What
  UTF16

  Why
  We want one or two 16-bit code units

  How
  UTF-16 is a character encoding capable of encoding all 1,112,064 non-surrogate code points of Unicode.
  The encoding is variable-length, as code points are encoded with one or two 16-bit code units

 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>


QString makeData() {
    QString data;

    data.append("Unicode test\r\n");
    for(int i = 0; i < 10; i++) {
        int number = QRandomGenerator::global()->bounded(1024);

        data.append(QChar(number));
    }
    data.append("\r\n");

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly)) {

        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf16);
        stream << data;
        stream.flush();

        file.close();
    }

    qInfo() << "Done";
    qInfo() << "UTF16: " << data;
    qInfo() << "UTF8: " << data.toUtf8();
    qInfo() << "ASCII: " << data.toLatin1();


    return a.exec();
}
