#ifndef UKUISYSTEMTRAYICON_H
#define UKUISYSTEMTRAYICON_H

#include <QObject>
#include "dbus_type.h"

class DBusType;
class UkuiSystemTrayIcon : public QObject
{
    Q_OBJECT
public:
    explicit UkuiSystemTrayIcon(QObject *parent = nullptr,int pid = 0);


private:
    DBusType *m_Dbus;

public:
    void Activate(int x, int y);
    void ContextMenu(int x, int y);
    void Scroll(int delta, const QString &orientation);
    void SecondaryActivate(int x, int y);

    void setIcon(const QIcon &icon);

signals:
    void activated(int x, int y);
    void Context(int x, int y);
    void Scrolled(int delta, const QString &orientation);
    void SecondaryActivated(int x, int y);


};

#endif // UKUISYSTEMTRAYICON_H
