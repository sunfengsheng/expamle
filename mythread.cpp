#include "mythread.h"
#include <QDebug>
#include <QElapsedTimer>
MyThread::MyThread(QWidget *parent)
    : QObject(parent)
{
}

MyThread::~MyThread()
{
}

void MyThread::doWork(const QString &parameter) {
//    qDebug() << "before MyThread this   test  :" << this->test;
//    test += "sgnb";
//    qDebug() << "after MyThread this   test  :" << this->test;


    qDebug()<<"mythread   :"<<QThread::currentThreadId();
    for(int i=0;i<=100;i++){
        qDebug()<<"mythread   is  :"<<i;
    }
}
