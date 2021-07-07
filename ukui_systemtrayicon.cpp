#include "ukui_systemtrayicon.h"
UkuiSystemTrayIcon::UkuiSystemTrayIcon(QObject *parent,int pid)
{
    m_Dbus=new DBusType(this,pid);
}

void UkuiSystemTrayIcon::Activate(int x, int y){
    emit activated(x,y);
}

void UkuiSystemTrayIcon::ContextMenu(int x, int y){
    emit Context(x,y);
}

void UkuiSystemTrayIcon::Scroll(int delta, const QString &orientation){
    emit Scrolled(delta,orientation);
}

void UkuiSystemTrayIcon::SecondaryActivate(int x, int y){
    emit SecondaryActivated(x,y);
}

void UkuiSystemTrayIcon::SetIcon(){

}
