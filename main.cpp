#include "concurrent.h"
#include "runnable.h"
#include <QApplication>
#include <QThreadPool>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Concurrent w;
    w.show();
    qDebug()<<"master  is  :"<<QThread::currentThread();
//    Runnable *run=new Runnable;
//    QThreadPool::globalInstance()->setMaxThreadCount(10);
//    for(int i=0;i<10;i++){
//    QThreadPool::globalInstance()->start(run);
//    }
    return a.exec();
}
