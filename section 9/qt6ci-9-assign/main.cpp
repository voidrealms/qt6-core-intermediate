/*

  What
  Make logging categories

  Why
  We want them to make logging easier to understand

  How
  QLoggingCategory

 */

#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

void test(QLoggingCategory & lcat)
{
    qDebug(lcat) << "Debug";
    qInfo(lcat) << "Info";
    qWarning(lcat) << "Warning";
    qCritical(lcat) << "Critical";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLoggingCategory cats("cats");

    cats.setEnabled(QtMsgType::QtDebugMsg,false);
    cats.setEnabled(QtMsgType::QtInfoMsg,false);
    cats.setEnabled(QtMsgType::QtWarningMsg,false);

    QLoggingCategory dogs("dogs");
    dogs.setEnabled(QtMsgType::QtDebugMsg,false);

    test(cats);
    test(dogs);

    return a.exec();
}
