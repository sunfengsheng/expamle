#ifndef DBUS_ADAPTOR_H
#define DBUS_ADAPTOR_H


#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "dbus.h"

QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

class dbus_adaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.sun.dbus.frist.test")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.sun.dbus.frist.test\">\n"
"    <method name=\"method2\">\n"
"      <arg direction=\"out\" type=\"b\"/>\n"
"      <arg direction=\"in\" type=\"i\" name=\"input\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")

public:
    explicit dbus_adaptor(QObject *parent = nullptr);
    virtual ~dbus_adaptor();


public Q_SLOTS:
    bool method2(int input);

signals:

public slots:

};

#endif // DBUS_ADAPTOR_H
