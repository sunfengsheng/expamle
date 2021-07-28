#include "dbus_menu.h"
#include <QApplication>
#include <QMenu>
DBusMenu::DBusMenu(DBusServer *parent,QMenu *menu)
{
    m_Parent=parent;
    m_Menu=menu;
    DBusMenuExporter eMenu(m_Parent->menuItem().path(),m_Menu);
}
