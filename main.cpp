#include "mythread.h"
#include "threadcontrol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThread w;
    ThreadControl q;
    return a.exec();
}
