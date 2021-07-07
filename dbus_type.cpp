#include "dbus_type.h"

DBusType::DBusType(UkuiSystemTrayIcon *parent,int id)
{
    m_SystemIcon=parent;
    QDBusConnection dbus = QDBusConnection::sessionBus();
    QString service="org.ukui.StatusNotifierItem-"+QString::number(id);
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
