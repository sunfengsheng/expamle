#include "watcher.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    watcher w;
    w.show();
    return a.exec();
}
