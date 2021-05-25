/*

  What
  File system watcher

  Why
  We want to know when something changes

  How
  See example
  QFileSystemWatcher
 */

#include <QCoreApplication>
#include "watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Watcher w;

    return a.exec();
}
