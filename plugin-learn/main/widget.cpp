#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFile file("/home/li/testwork/build-plugin-learn-unknown-Debug/plugin/libPlugin1.so");
    qDebug()<<file.exists();
    QPluginLoader pluginLoader("/home/li/testwork/build-plugin-learn-unknown-Debug/plugin/libPlugin1.so");
    QObject *pClipPlugin = pluginLoader.instance();
    qDebug()<<pluginLoader.isLoaded();
    pulgin1interface *yuyu = dynamic_cast<pulgin1interface *>(pClipPlugin);
    qDebug()<<yuyu->name();
    yuyu->createPluginWidget(this);
}

Widget::~Widget()
{
}

