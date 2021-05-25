#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";
}

Test::~Test()
{
    qInfo() << this << "Deconstructed";
}
