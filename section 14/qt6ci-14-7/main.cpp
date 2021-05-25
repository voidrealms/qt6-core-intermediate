/*

  What
  Process custom commands

  Why
  Show we have the full system available

  How
  CMD - Windows
  BASH - Linux
  Mac - zsh

 */

#include <QCoreApplication>
#include "commander.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Commander cmd;
    cmd.action(QByteArray("pwd"));
    cmd.action(QByteArray("ls -l"));

    return a.exec();
}
