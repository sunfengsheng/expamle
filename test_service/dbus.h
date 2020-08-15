#ifndef DBUS_H
#define DBUS_H

#include <QObject>

class Dbus : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.sun.dbus.frist.test")
public:
    explicit Dbus(QObject *parent = 0);

signals:

public slots:
    bool method1(int input);

};

#endif // DBUS_H
