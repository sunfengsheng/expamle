#ifndef DBUSTYPE_H
#define DBUSTYPE_H

#include <QObject>
#include <QtDBus/QtDBus>
#include <QDebug>

#include "ukui_systemtrayicon.h"
#include "dbustypes.h"

class UkuiSystemTrayIcon;
class DBusType : public QObject
{
    Q_OBJECT    
    Q_CLASSINFO("D-Bus Interface","org.kde.StatusNotifierItem")
public:
    explicit DBusType(UkuiSystemTrayIcon *parent = nullptr,int id=0);
    Q_PROPERTY(QString AttentionIconName READ attentionIconName)
    Q_PROPERTY(IconPixmapList AttentionIconPixmap READ attentionIconPixmap)
    Q_PROPERTY(QString AttentionMovieName READ attentionMovieName)
    Q_PROPERTY(QString Category READ category)
    Q_PROPERTY(QString IconName READ iconName)
//    Q_PROPERTY(IconPixmapList IconPixmap READ iconPixmap)
    Q_PROPERTY(QString IconThemePath READ iconThemePath)
    Q_PROPERTY(QString Id READ id)
    Q_PROPERTY(bool ItemIsMenu READ itemIsMenu)
//    Q_PROPERTY(QDBusObjectPath Menu READ menu)
    Q_PROPERTY(QString OverlayIconName READ overlayIconName)
//    Q_PROPERTY(IconPixmapList OverlayIconPixmap READ overlayIconPixmap)
    Q_PROPERTY(QString Status READ status)
    Q_PROPERTY(QString Title READ title)
//    Q_PROPERTY(ToolTip ToolTip READ toolTip)
    Q_PROPERTY(int WindowId READ windowId)

private:
   QString attentionIconName();
   IconPixmapList attentionIconPixmap();
   QString attentionMovieName();
   QString category();
   QString iconName();
//   IconPixmapList iconPixmap();
   QString iconThemePath();
   QString id();
   bool itemIsMenu();
   QDBusObjectPath menu();
   QString overlayIconName();
//   IconPixmapList overlayIconPixmap();
   QString status();
   QString title();
//   ToolTip toolTip();
   int windowId();

public:
   void setIcon(QString icon);

private:
    UkuiSystemTrayIcon *m_SystemIcon;

public slots:
   void Activate(int x, int y);
   void ContextMenu(int x, int y);
   void Scroll(int delta, const QString &orientation);
   void SecondaryActivate(int x, int y);

signals:
   void NewAttentionIcon();
   void NewIcon();
   void NewOverlayIcon();
   void NewStatus(const QString &status);
   void NewTitle();
   void NewToolTip();

};

#endif // DBUSTYPE_H
