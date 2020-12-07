#include "tcpserver.h"

tcpserver::tcpserver(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("TCP Server");
    ContentListWidget =new QListWidget;
    PortLabel=new QLabel("端口： ");
    PortLineEdit=new QLineEdit;
    CreateBtn =new QPushButton("创建聊天室");
    mainLayout =new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);

    port=8010;
    PortLineEdit->setText(QString::number(port));
    connect(CreateBtn,&QPushButton::clicked,this,[=](){
        slotCreateServer();
    });
}

void tcpserver::slotCreateServer(){
    server=new Server(this,port);
    connect(server,&Server::updateServer,this,[=](const QString &key1,const int &key2){
        updateServer(key1,key2);
    });
    CreateBtn->setEnabled(false);
}

void tcpserver::updateServer(QString msg, int length){
    ContentListWidget->addItem(msg.left(length));
}


tcpserver::~tcpserver()
{
}

