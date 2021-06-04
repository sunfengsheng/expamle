#ifndef ANOTHERTHREAD_H
#define ANOTHERTHREAD_H

#include <QThread>
class AnotherThread : public QThread
{
    Q_OBJECT
public:
    AnotherThread();

protected:
    void run();

};

#endif // ANOTHERTHREAD_H
