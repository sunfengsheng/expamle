#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QObject>
#include <QRunnable>
class Runnable : public QRunnable
{
public:
    Runnable();
    void run();
};

#endif // RUNNABLE_H
