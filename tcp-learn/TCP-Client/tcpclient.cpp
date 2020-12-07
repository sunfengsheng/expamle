#include "tcpclient.h"
#include <QMessageBox>
#include <QHostInfo>
tcpclient::tcpclient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("TCP Client");
    contentListWidget =new QListWidget;
    sendLineEdit =new QLineEdit;
    sendBtn = new QPushButton("发送");
    userNamelabel =new QLabel("用户名：");
    userNameLineEdit= new QLineEdit;
    serverIPLabel=new QLabel("服务器地址： ");
    serverIPLineEdit=new QLineEdit;
    portLabel=new QLabel("端口：");
    portLineEdit=new QLineEdit;
    enterBtn=new QPushButton("进入聊天室");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(contentListWidget,0,0,1,2);
    mainLayout->addWidget(sendLineEdit,1,0);
    mainLayout->addWidget(sendBtn,1,1);
    mainLayout->addWidget(userNamelabel,2,0);
    mainLayout->addWidget(userNameLineEdit,2,1);
    mainLayout->addWidget(serverIPLabel,3,0);
    mainLayout->addWidget(serverIPLineEdit,3,1);
    mainLayout->addWidget(portLabel,4,0);
    mainLayout->addWidget(portLineEdit,4,1);
    mainLayout->addWidget(enterBtn,5,0,1,2);

    status=false;
    port=8010;
    portLineEdit->setText(QString::number(port));
    serverIP =new QHostAddress();
    connect(enterBtn,&QPushButton::clicked,this,[=](){
        slotEnter();
    });
    connect(sendBtn,&QPushButton::clicked,this,[=](){
        slotSend();
    });
    sendBtn->setEnabled(false);

}

void tcpclient::slotEnter(){
    qDebug()<<status;
    if(!status){
        QString ip=serverIPLineEdit->text();
        if(!serverIP->setAddress(ip)){
            QMessageBox::information(this,"error","server ip address error!");
            return;
        }
        if(userNameLineEdit->text()==""){
            QMessageBox::information(this,"error","User name error!");
            return;
        }
        userName=userNameLineEdit->text();
        tcpSocket=new QTcpSocket(this);
        connect(tcpSocket,&QTcpSocket::connected,this,[=](){
            slotConnected();
        });
        connect(tcpSocket,&QTcpSocket::disconnected,this,[=](){
            slotDisconnected();
        });
        connect(tcpSocket,&QTcpSocket::readyRead,this,[=](){
            dataReceived();
        });
        tcpSocket->connectToHost(*serverIP,port);
        status=true;
    }else{
        int length=0;
        QString msg=userName+":Leave Chat Room";
        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
            return;
        }
        tcpSocket->disconnectFromHost();
        status=false;
    }
}

void tcpclient::slotConnected(){
    sendBtn->setEnabled(true);
    enterBtn->setText("离开");
    int length=0;
    QString msg=userName+":Enter Chat Room";
    if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
        return;
    }
}

void tcpclient::slotSend(){
    if(sendLineEdit->text()==""){
        return;
    }
    QString msg=userName+":"+sendLineEdit->text();
    tcpSocket->write(msg.toLatin1(),msg.length());
    sendLineEdit->clear();
}

void tcpclient::slotDisconnected(){
    sendBtn->setEnabled(false);
    enterBtn->setText("进入聊天室");
}

void tcpclient::dataReceived(){
    while(tcpSocket->bytesAvailable()>0){
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(),datagram.size());
        QString msg=datagram.data();
        contentListWidget->addItem(msg.left(datagram.size()));
    }
}


tcpclient::~tcpclient()
{
}

