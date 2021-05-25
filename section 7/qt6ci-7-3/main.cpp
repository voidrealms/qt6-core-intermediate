/*

  What
  Creating groups

  Why
  We want the settings in logical groups

  How
  beginGroup / endGroup

 */

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void saveAge(QSettings *setting,QString group,QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *setting, QString group, QString name)
{
    setting->beginGroup(group);

    if(!setting->contains(name))
    {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok)
    {
        qWarning() << "Could not convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("VoidRealms");
    QCoreApplication::setOrganizationDomain("VoidRealms.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings,"people","Bryan",44);
    saveAge(&settings,"beer","twoheart",1);
    saveAge(&settings,"beer","Bryan",11);

    qInfo() << "TwoHeart" << getAge(&settings,"beer","twoheart");
    qInfo() << "Bryan (people)" << getAge(&settings,"people","Bryan");
    qInfo() << "Bryan (beer)" << getAge(&settings,"beer","Bryan");

    return a.exec();
}
