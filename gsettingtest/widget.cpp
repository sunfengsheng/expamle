#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    const QByteArray id("org.ukui.sun.fristtest");
    gsetting = new QGSettings(id);
    connect(gsetting,&QGSettings::changed,this,[](const QString &key){
        if(key=="point1"){
            qDebug()<<"******8";
        }
    });

    gsetting->get("point1");
    gsetting->set("point1",89);

}

Widget::~Widget()
{

}
