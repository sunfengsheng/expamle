#include "dbus_adaptor.h"
#include <QMetaObject>
#include <QByteArray>
#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QVariant>
dbus_adaptor::dbus_adaptor(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    setAutoRelaySignals(true);
}

dbus_adaptor::~dbus_adaptor()
{
    // destructor
}


bool dbus_adaptor::method2(int input)
{
    // handle method call com.kylin.security.controller.filectrl.AddToTaskbar
    bool out0;
    QMetaObject::invokeMethod(parent(), "method1", Q_RETURN_ARG(bool, out0), Q_ARG(int, input));
    qDebug()<<out0;
    return out0;
}
