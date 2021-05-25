/*

  What
  QLoggingCategory

  Why
  Make Logging categories easier

  How
  QLoggingCategory

 */

#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLoggingCategory logtest("testing");
    logtest.setEnabled(QtMsgType::QtDebugMsg,false);

    qDebug() << "Debug = " << logtest.isDebugEnabled();
    qInfo() << "Info = " << logtest.isInfoEnabled();
    qWarning() << "Warning = " << logtest.isWarningEnabled();
    qCritical() << "Critical = " << logtest.isCriticalEnabled();

    qDebug(logtest) << "This is a debug";
    qInfo(logtest) << "This is a info";
    qWarning(logtest) << "This is a warning";
    qCritical(logtest) << "This is a critical";

    return a.exec();
}
