#include "udpserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpServer *udp=new UdpServer;
    udp->show();
    return a.exec();
}
