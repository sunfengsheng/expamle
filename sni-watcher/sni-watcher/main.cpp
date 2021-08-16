#include "sniwatcher.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SniWatcher w;
    return a.exec();
}
