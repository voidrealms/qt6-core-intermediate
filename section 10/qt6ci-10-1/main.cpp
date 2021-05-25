/*

  What
  ASCII

  Why
  No encoding

  How
  You already use it
  http://www.asciitable.com/

 ASCII is a 7-bit character set containing 128 characters.
 It contains the numbers from 0-9, the upper and lower case English letters from A to Z, and some special characters.
 The character sets used in modern computers, in HTML, and on the Internet, are all based on ASCII.

 */


#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

QByteArray makedata()
{
    QByteArray data;
    for(int i = 0; i < 10; i++) {
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(108);
        data.append(111);
        data.append(33);
        data.append(13); // \r
        data.append(10); // \n

        // \r\n
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makedata();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.close();
    }

    qInfo() << "Done";

    return a.exec();
}
