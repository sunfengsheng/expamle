#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include <QThread>
class MyThread : public QObject
{
    Q_OBJECT

public:
    MyThread(QWidget *parent = nullptr);
    ~MyThread();

public:
    QString test = "ooo";

public slots:
    void doWork(const QString &parameter);

signals:
    void resultReady(const QString &result);
};
#endif // MYTHREAD_H
