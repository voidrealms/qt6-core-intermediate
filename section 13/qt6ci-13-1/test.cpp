#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    qInfo() << "Constructed" << this;
}

Test::~Test()
{
    qInfo() << "Deconstructed" << this;
}
