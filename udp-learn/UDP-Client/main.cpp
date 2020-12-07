#include "udpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpClient *udp=new UdpClient;
    udp->show();
    return a.exec();
}
