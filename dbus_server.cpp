#include "dbus_server.h"
#include <QApplication>

DBusServer::DBusServer(UkuiSystemTrayIcon *parent,int id)
{
    m_SystemIcon=parent;
    QDBusConnection dbus = QDBusConnection::sessionBus();
    QString service="org.kde.StatusNotifierItem-"+QString::number(id);
    m_Service=service;
    QString path="/StatusNotifierItem";
    if (!dbus.registerService(service))
        qDebug() << QDBusConnection::sessionBus().lastError().message();
    if (!dbus.registerObject("/StatusNotifierItem", "org.kde.StatusNotifierItem",this, QDBusConnection::ExportAllContents))
        qDebug() << QDBusConnection::sessionBus().lastError().message();

    QDBusInterface *m_interFace=new QDBusInterface ("org.kde.StatusNotifierWatcher", "/StatusNotifierWatcher",
                                                    "org.kde.StatusNotifierWatcher",
                                                    QDBusConnection::sessionBus());
    if (!m_interFace->isValid())
    {
        qWarning() << qPrintable(QDBusConnection::sessionBus().lastError().message());
    }
    m_interFace->call("RegisterStatusNotifierItem",service);
}



//property
QString DBusServer::attentionIconName(){
    return "attentionIconName";
}
IconPixmapList DBusServer::attentionIconPixmap(){
    IconPixmapList tep;
    return tep;
}
QString DBusServer::attentionMovieName(){
    return "attentionMovieName";
}
QString DBusServer::category(){
    return "category";
}
QString DBusServer::iconName(){
//     return "network-wired-connected-symbolic";
    return this->property("icon").toString();
}
//IconPixmapList DBusServer::iconPixmap(){
//    IconPixmapList tep;
//    return tep;
//}
QString DBusServer::iconThemePath(){
    return "iconThemePath";
}
QString DBusServer::id(){
    return "id";
}
bool DBusServer::itemIsMenu(){
    return true;
}
QDBusObjectPath DBusServer::menuItem(){
    QDBusObjectPath path;
    path.setPath("/MenuBar");
    return path;
}
QString DBusServer::overlayIconName(){
    return "overlayIconName";
}
//IconPixmapList DBusServer::overlayIconPixmap(){
//    IconPixmapList tep;
//    return tep;
//}
QString DBusServer::status(){
    return "Active";
}
QString DBusServer::title(){
    return "title";
}
//ToolTip DBusServer::toolTip(){
//    ToolTip tp;
//    return tp;
//}
int DBusServer::windowId(){
    return 1;
}


//public
void DBusServer::setIcon(QString icon){
    this->setProperty("icon",icon);
    iconName();
}


//method
void DBusServer::Activate(int x, int y)
{
    m_SystemIcon->Activate(x,y);
}
void DBusServer::ContextMenu(int x, int y){
//    m_SystemIcon->ContextMenu(x,y);
}
void DBusServer::Scroll(int delta, const QString &orientation)
{
    m_SystemIcon->Scroll(delta,orientation);
}
void DBusServer::SecondaryActivate(int x, int y){
    m_SystemIcon->SecondaryActivate(x,y);
}

//menu
void DBusServer::setMenu(QMenu *menu){
    m_DMenu = new DBusMenu(this,menu);
    QThread* thread1 = new QThread();

//    Test* w = new Test();
    m_DMenu->moveToThread(thread1);
    thread1->start();
}
