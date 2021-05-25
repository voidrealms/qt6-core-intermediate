#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>
#include <QThread>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);
    ~Producer();

signals:
    void produce(int value);
    void finished();

public slots:
    void start();

private slots:
    void timeout();

private:
    QTimer *m_timer;
    int m_count;
    int m_max;


};

#endif // PRODUCER_H
