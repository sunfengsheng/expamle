#include "threadcontrol.h"
#include <QDebug>
ThreadControl::ThreadControl(QObject *parent) : QObject(parent)
{
    worker = new MyThread;
    AnotherWork = new AnotherThread;
    worker->moveToThread(&workerThread);
//    connect(this, &ThreadControl::operate, worker, &MyThread::doWork);
//    connect(this, &ThreadControl::operate, worker, &MyThread::doWork,Qt::QueuedConnection);
//    connect(this, &ThreadControl::operate, worker, &MyThread::doWork,Qt::DirectConnection);
//    connect(this, &ThreadControl::operate, worker, &MyThread::doWork,Qt::BlockingQueuedConnection);
    workerThread.start();
//    AnotherWork->start();
    emit operate("dssds");
    qDebug()<<"master   :"<<QThread::currentThreadId();

}

ThreadControl::~ThreadControl(){
    workerThread.quit();
    workerThread.wait();
}

void ThreadControl::handleResults(const QString &print){
    qDebug()<<"print    "<<print;
}
