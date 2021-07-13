#include "person.h"

Person::Person(QObject *parent, QString firstname, QString lastname) : QObject(parent)
{
    m_firstname = firstname;
    m_lastname = lastname;
}

QStringView Person::display()
{
    //QStringView view(QString(m_firstname + " " + m_lastname));
    
    String name = QString(m_firstname + " " + m_lastname);
    QStringView view(name);
    return view;
}
