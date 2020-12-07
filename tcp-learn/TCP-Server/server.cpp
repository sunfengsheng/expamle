#include "server.h"

Server::Server(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

void Server::incomingConnection(qintptr  socketDescriptor){
    tcpclientsocket *tcpClientSocket=new tcpclientsocket(this);
    connect(tcpClientSocket,&tcpclientsocket::updateClients,this,[=](const QString& key1,const int& key2){
        qDebug()<<key1;
        qDebug()<<key2;
        updateClients(key1,key2);
    });
    connect(tcpClientSocket,&tcpclientsocket::disconnected,this,[=](const int& key3){
        qDebug()<<key3;
       slotDisconnected(key3);
    });
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpclientsocketList.append(tcpClientSocket);
}

void Server::updateClients(QString msg,int length){
    emit updateServer(msg,length);
    for(int i=0;i<tcpclientsocketList.count();i++){
        QTcpSocket *item = tcpclientsocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length){
            continue;
        }
    }
}

void Server::slotDisconnected(int descriptor){
    for(int i=0;i<tcpclientsocketList.count();i++){
        QTcpSocket *item=tcpclientsocketList.at(i);
        if(item->socketDescriptor()==descriptor){
            tcpclientsocketList.removeAt(i);
            return;
        }
    }
}





