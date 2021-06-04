#include "concurrent.h"
#include <QtConcurrent/QtConcurrent>
#include <functional>
#include <QtWidgets>
#include <QThreadPool>
using namespace QtConcurrent;
Concurrent::Concurrent(QWidget *parent)
    : QWidget(parent)
{
//    QThreadPool::globalInstance()->setMaxThreadCount(10);
    qDebug()<<"master   is  :"<<QThread::currentThreadId()<<QThread::currentThread();
    for(int i=0;i<10;i++){
        QtConcurrent::run(Func);
    }

    qDebug()<<"thread   count   :"<<this->thread()->idealThreadCount();
}

Concurrent::~Concurrent()
{
}

void Func(){
        qDebug()<<"this thread id is   :"<<QThread::currentThreadId()<<QThread::currentThread();
        while(true){

        }
}
