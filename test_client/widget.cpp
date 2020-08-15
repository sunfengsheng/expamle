#include "widget.h"
#include "ui_widget.h"

#include <QDBusInterface>
#include <QDBusReply>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::on_pushButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QDBusInterface iface("com.sun.dbus.frist.test",
                         "/sun/test",
                         "com.sun.dbus.frist.test",
                         QDBusConnection::sessionBus());
    QDBusReply<bool> reply=iface.call("method1",527);
    qDebug()<<reply;
}
