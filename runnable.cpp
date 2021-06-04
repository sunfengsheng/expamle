#include "runnable.h"
#include <QDebug>
#include <QThread>
Runnable::Runnable()
{

}

void Runnable::run(){
    qDebug()<<"thread  is  :"<<QThread::currentThread();
}
