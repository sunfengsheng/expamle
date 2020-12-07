#include "udpserver.h"
#include <QHostAddress>
UdpServer::UdpServer(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("UDP Server");
    TimerLabel=new QLabel("计时器",this);
    TextLineEdit=new QLineEdit(this);
    StartBtn=new QPushButton("开始",this);
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    connect(StartBtn,&QPushButton::clicked,this,[=](){
        StartBtnClicked();
    });
    port=5555;
    isStarted=false;
    udpSocket  =new QUdpSocket(this);
    timer =new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=](){
        timeout();
    });

}

void UdpServer::StartBtnClicked(){
    if(!isStarted){
        StartBtn->setText("停止");
        timer->start(1000);
        isStarted=true;
    }else{
        StartBtn->setText("开始");
        isStarted=false;
        timer->stop();
    }
}

void UdpServer::timeout(){
    QString msg = TextLineEdit->text();
    int length=0;
    if(msg==""){
        return;
    }
    if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),
                                        QHostAddress::Broadcast,port))!=msg.length()){
        return;
    }
}


UdpServer::~UdpServer()
{
}

