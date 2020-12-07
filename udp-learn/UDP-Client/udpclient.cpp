#include "udpclient.h"
#include <QHostAddress>
#include <QMessageBox>
UdpClient::UdpClient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("UDP Client");
    ReceiveTextEdit=new QTextEdit(this);
    CloseBtn=new QPushButton("Close",this);
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    connect(CloseBtn,&QPushButton::clicked,this,[=](){
        CloseBtnClicked();
    });
    port=5555;
    udpSocket  =new QUdpSocket(this);
    connect(udpSocket,&QUdpSocket::readyRead,this,[=](){
        dataReceived();
    });
    bool result=udpSocket->bind(port);
    if(!result){
        QMessageBox::information(this,"error","udp socket create error!");
        return;
    }

}

void UdpClient::CloseBtnClicked(){
    close();
}

void UdpClient::dataReceived(){
    while(udpSocket->hasPendingDatagrams()){
        QByteArray datagrem;
        datagrem.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagrem.data(),datagrem.size());
        QString msg =datagrem.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}


UdpClient::~UdpClient()
{
}

