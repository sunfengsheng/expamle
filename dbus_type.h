#ifndef DBUSTYPE_H
#define DBUSTYPE_H

#include <QObject>
#include <QtDBus/QtDBus>
#include <QDebug>

#include "ukui_systemtrayicon.h"

class UkuiSystemTrayIcon;
class DBusType : public QObject
{
    Q_OBJECT
public:
    explicit DBusType(UkuiSystemTrayIcon *parent = nullptr,int id=0);
    Q_PROPERTY(QString IconName READ iconName)


private:
    QString iconName(){
        this->setProperty("IconName",QString("network-wired-connected-symbolic"));
       return QString("network-wired-connected-symbolic");
    }

private:
    UkuiSystemTrayIcon *m_SystemIcon;

public slots:
   void Activate(int x, int y);
   void ContextMenu(int x, int y);
   void Scroll(int delta, const QString &orientation);
   void SecondaryActivate(int x, int y);

signals:

};

#endif // DBUSTYPE_H
