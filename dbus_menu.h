#ifndef DBUSMENU_H
#define DBUSMENU_H

#include <QObject>
#include <dbusmenuexporter.h>
#include <QMenu>

#include "dbus_server.h"

class DBusServer;

class DBusMenu : public QObject
{
    Q_OBJECT
public:
    explicit DBusMenu(DBusServer *parent = nullptr,QMenu *menu = nullptr);

private:

public:
    QEventLoop loop;

private:
    DBusServer *m_Parent;
    QMenu *m_Menu;

signals:

};

#endif // DBUSMENU_H
