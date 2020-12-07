#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "tcpclientsocket.h"
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,int port=0);
    QList<tcpclientsocket*> tcpclientsocketList;

signals:
    void updateServer(QString,int);

public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);

protected:
    void incomingConnection(qintptr  socketDescriptor);

};

#endif // SERVER_H
