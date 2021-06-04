#include "anotherthread.h"
#include <QDebug>
AnotherThread::AnotherThread()
{

}

void AnotherThread::run(){
    qDebug()<<"AnotherThread   :"<<QThread::currentThreadId();
    for(int i=0;i<=100;i++){
        qDebug()<<"AnotherThread   is  :"<<i;
//        printf("AnotherThread id %d\n",i);
//        fflush(stdout);
    }
}
