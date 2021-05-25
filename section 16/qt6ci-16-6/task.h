#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QRunnable>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();

signals:

public slots:
    void run();
};

#endif // TASK_H
