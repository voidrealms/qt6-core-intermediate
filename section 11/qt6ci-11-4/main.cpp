/*

  What
  File compression

  Why
  Why not!

  How
  Lots of custom code
  make file
  compress file
  decompress file
  NOT COMPATIBLE !!!!

 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QTextStream>

bool makeFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QByteArray data;
        for(int i = 0; i < 1000; i++)
        {
            data.append(QString::number(i).toUtf8() + "\r\n");
        }

        file.write(data);
        file.close();

        return true;
    }

    return false;
}

QByteArray getHeader() {
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile);
    QByteArray header = getHeader();

    if(!ofile.open(QIODevice::ReadOnly)) return false;
    if(!nfile.open(QIODevice::WriteOnly)) return  false;
    int size = 1024;

    while (!ofile.atEnd())
    {
        QByteArray buffer = ofile.read(size);
        QByteArray compressed = qCompress(buffer,9);
        nfile.write(header);
        nfile.write(compressed);
    }

    ofile.close();
    nfile.close();

    qInfo() << "Finished compressing";

    return true;
}

bool decompressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile);
    QByteArray header = getHeader();
    int size = 1024;

    if(!ofile.open(QIODevice::ReadOnly)) return false;
    if(!nfile.open(QIODevice::WriteOnly)) return false;


    //Make sure WE created this file!!!
    QByteArray buffer = ofile.peek(size);
    if(!buffer.startsWith(header))
    {
        qCritical() << "We did not create this file!";
        ofile.close();
        nfile.close();
        return false;
    }


    //Find the header positions
    ofile.seek(header.length());

    while (!ofile.atEnd())
    {
        buffer = ofile.peek(size);
        qint64 index = buffer.indexOf(header);
        qDebug() << "Head found at:" << index;

        if(index > -1)
        {
            //We found a header
            qint64 maxbytes = index;
            qInfo() << "Reading:" << maxbytes;
            buffer = ofile.read(maxbytes);
            ofile.read(header.length());
        }
        else
        {
            //Do not have a header!
            qInfo() << "Read all no header";
            buffer = ofile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        nfile.write(decompressed);
        nfile.flush();
    }

    ofile.close();
    nfile.close();

    return true;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = "orginal.txt";
    QString compressedFile = "compressed.txt";
    QString decompressedFile = "decompressed.txt";

    if(makeFile(originalFile)) {
        qInfo() << "Original created";

        if(compressFile(originalFile, compressedFile)) {
            qInfo() << "File compressed";
            if(decompressFile(compressedFile,decompressedFile)) {
                qInfo() << "File decompressed!";
            } else {
                qInfo() << "Could not decompress file!";
            }
        } else {
            qInfo() << "File not compressed";
        }
    }

    return a.exec();
}
