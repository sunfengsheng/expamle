#include "client.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400,400);
    QHBoxLayout *hblayout=new QHBoxLayout(this);
    QPushButton *bt1=new QPushButton(this);
    bt1->setText("method1");
    QPushButton *bt2=new QPushButton(this);
    bt2->setText("method2");
    hblayout->addWidget(bt1);
    hblayout->addWidget(bt2);

    connect(bt1,&QPushButton::clicked,this,[](){
        QDBusInterface interface("com.learn.DBus.server", "/",
                                 "com.learn.DBus.server",
                                 QDBusConnection::sessionBus());
        QDBusReply<bool> reply = interface.call("methodOne","true");
        qDebug()<<reply;
    });

    connect(bt2,&QPushButton::clicked,this,[](){
        QDBusInterface interface("com.learn.DBus.server", "/",
                                 "com.learn.DBus.server",
                                 QDBusConnection::sessionBus());
        QDBusReply<QString> reply = interface.call("methodTwo",456);
        qDebug()<<reply;
    });

}

Widget::~Widget()
{
}

