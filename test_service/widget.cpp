#include "widget.h"
#include "dbus.h"
#include "adaptor.h"

#include <QDebug>
#include <QDBusConnection>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    register_dbus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::register_dbus()
{
    Dbus* dbus=new Dbus;
    new TestAdaptor(dbus);
    QDBusConnection con=QDBusConnection::sessionBus();
    if(!con.registerService("com.sun.dbus.frist.test") ||
            !con.registerObject("/sun/test",dbus))
    {
        qDebug()<<"fail";
    }
}
