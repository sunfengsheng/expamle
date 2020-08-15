#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mqsettings = new QSettings("/home/sunfengsheng/.config/qsettingtest.conf",QSettings::IniFormat);
    mqsettings ->beginGroup("frist");
    mqsettings->setValue("point1",true);
    qDebug()<<"point1"<<mqsettings->value("point1","").toString();
    mqsettings->endGroup();
}

Widget::~Widget()
{

}
