#include "cat.h"

Cat::Cat(QObject *parent, QString name) : QObject(parent)
{
    setObjectName(name);
    qInfo() << "Constructed" << this;
}

Cat::~Cat()
{
    qInfo() << "Deconstructed" << this;
}

void Cat::play(QSharedPointer<Toy> toy)
{
    m_toy.swap(toy);
    qInfo() << this << "Playing with" << m_toy.data();
}
