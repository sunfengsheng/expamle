#ifndef THREADCONTROL_H
#define THREADCONTROL_H

#include <QObject>
#include "mythread.h"
#include "anotherthread.h"
class ThreadControl : public QObject
{
    Q_OBJECT
public:
    explicit ThreadControl(QObject *parent = nullptr);
    QThread workerThread;
    MyThread *worker;
    AnotherThread *AnotherWork;
    ~ThreadControl();
public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);


signals:

};

#endif // THREADCONTROL_H
