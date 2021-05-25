/*

  What
  Navigating groups

  Why
  Sometimes we don't know what groups are there

  How
  childGroups
*/

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void saveAge(QSettings *setting,QString group, QString name, int age) {
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *setting,QString group, QString name) {
    setting->beginGroup(group);

    if(!setting->contains(name)) {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok) {
        qWarning() << "Failed to convert ot int!!!";
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

    QStringList people;
    people << "Bryan" << "Tammy" << "Heather" << "Chris";

    foreach(QString person, people)
    {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings,"test",person,value);
    }

    //SAVE
    settings.sync();
    qInfo() << "File:" << settings.fileName();

    foreach(QString group, settings.childGroups())
    {
        settings.beginGroup(group);
        qInfo() << "Group:" << group;
        foreach(QString key, settings.childKeys())
        {
            qInfo() << "... key:" << key << " = " << settings.value(key).toString();
        }


        settings.endGroup();
    }

    return a.exec();
}
