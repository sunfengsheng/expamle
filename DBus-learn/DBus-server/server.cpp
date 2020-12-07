#include "server.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    FilectrlAdaptor *f=new FilectrlAdaptor(this);
    QDBusConnection con=QDBusConnection::sessionBus();
    if(!con.registerService("com.learn.DBus.server") ||
       !con.registerObject("/", this))
    {
       qDebug()<<"fail";
    }
}

bool Widget::methodOne(QString arg)
{
    if(arg=="true")
        return true;
    else
        return false;
}

QString Widget::methodTwo(int arg)
{
    QString str;
    QString input=QString::number(arg,10);
    str=QString("Num is ")+input;
        return str;
}
Widget::~Widget()
{
}

FilectrlAdaptor::FilectrlAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    setAutoRelaySignals(true);
}

FilectrlAdaptor::~FilectrlAdaptor()
{

}

bool FilectrlAdaptor::methodOne(const QString &arg)
{
    bool out0;
    QMetaObject::invokeMethod(parent(), "methodOne", Q_RETURN_ARG(bool, out0), Q_ARG(QString, arg));
    return out0;
}

QString FilectrlAdaptor::methodTwo(const int &arg)
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "methodTwo", Q_RETURN_ARG(QString, out0), Q_ARG(int, arg));
    return out0;
}

