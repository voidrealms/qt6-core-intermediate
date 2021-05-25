#ifndef TOY_H
#define TOY_H

#include <QObject>
#include <QDebug>

class Toy : public QObject
{
    Q_OBJECT
public:
    explicit Toy(QObject *parent = nullptr, QString name = "");
    ~Toy();
signals:

};

#endif // TOY_H
