#include "dbus_type.h"

DBusType::DBusType(UkuiSystemTrayIcon *parent,int id)
{
    m_SystemIcon=parent;
    QDBusConnection dbus = QDBusConnection::sessionBus();
    QString service="org.kde.StatusNotifierItem-"+QString::number(id);
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
QString DBusType::attentionIconName(){
    return "attentionIconName";
}
IconPixmapList DBusType::attentionIconPixmap(){
    IconPixmapList tep;
    return tep;
}
QString DBusType::attentionMovieName(){
    return "attentionMovieName";
}
QString DBusType::category(){
    return "category";
}
QString DBusType::iconName(){
//     return "network-wired-connected-symbolic";
    return this->property("icon").toString();
}
//IconPixmapList DBusType::iconPixmap(){
//    IconPixmapList tep;
//    return tep;
//}
QString DBusType::iconThemePath(){
    return "iconThemePath";
}
QString DBusType::id(){
    return "id";
}
bool DBusType::itemIsMenu(){
    return true;
}
QDBusObjectPath DBusType::menu(){
    QDBusObjectPath path;
    return path;
}
QString DBusType::overlayIconName(){
    return "overlayIconName";
}
//IconPixmapList DBusType::overlayIconPixmap(){
//    IconPixmapList tep;
//    return tep;
//}
QString DBusType::status(){
    return "Active";
}
QString DBusType::title(){
    return "title";
}
//ToolTip DBusType::toolTip(){
//    ToolTip tp;
//    return tp;
//}
int DBusType::windowId(){
    return 1;
}


//public
void DBusType::setIcon(QString icon){
    this->setProperty("icon",icon);
    iconName();
}


//method
void DBusType::Activate(int x, int y)
{
    m_SystemIcon->Activate(x,y);
}
void DBusType::ContextMenu(int x, int y){
    m_SystemIcon->ContextMenu(x,y);
}
void DBusType::Scroll(int delta, const QString &orientation)
{
    m_SystemIcon->Scroll(delta,orientation);
}
void DBusType::SecondaryActivate(int x, int y){
    m_SystemIcon->SecondaryActivate(x,y);
}
