/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i example_adaptor.h -a :example_adaptor.cpp ../dbus.demo.example.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "example_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <stdio.h>
#include "dbus_demo_example.h"

/*
 * Implementation of adaptor class Dbus_demo_exampleAdaptor
 */

Dbus_demo_exampleAdaptor::Dbus_demo_exampleAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

Dbus_demo_exampleAdaptor::~Dbus_demo_exampleAdaptor()
{
    // destructor
}

bool Dbus_demo_exampleAdaptor::return_bool()
{
    // handle method call local.dbus_demo_example.return_bool
    bool out0;
    QMetaObject::invokeMethod(parent(), "return_bool", Q_RETURN_ARG(bool, out0));
    return out0;
}

int Dbus_demo_exampleAdaptor::return_integer()
{
    // handle method call local.dbus_demo_example.return_integer
    int out0;
    QMetaObject::invokeMethod(parent(), "return_integer", Q_RETURN_ARG(int, out0));
    return out0;
}

int Dbus_demo_exampleAdaptor::return_integet_and_set_integer(int argc_1, const QString &argc_22, QString &argc_2, QString &out1)
{
    // handle method call local.dbus_demo_example.return_integet_and_set_integer
    printf("%s\n", "12312312312312312312");
    return static_cast<dbus_demo_example *>(parent())->return_integet_and_set_integer(argc_1, argc_22, argc_2, out1);
}

int Dbus_demo_exampleAdaptor::return_integet_and_set_integet_2(int argc_1)
{
    // handle method call local.dbus_demo_example.return_integet_and_set_integet_2
    int out0;
    QMetaObject::invokeMethod(parent(), "return_integet_and_set_integet_2", Q_RETURN_ARG(int, out0), Q_ARG(int, argc_1));
    return out0;
}

QString Dbus_demo_exampleAdaptor::return_string()
{
    // handle method call local.dbus_demo_example.return_string
    QString out0;
    QMetaObject::invokeMethod(parent(), "return_string", Q_RETURN_ARG(QString, out0));
    return out0;
}

QString Dbus_demo_exampleAdaptor::return_string_and_set_string(const QString &argc_1)
{
    // handle method call local.dbus_demo_example.return_string_and_set_string
    QString out0;
    QMetaObject::invokeMethod(parent(), "return_string_and_set_string", Q_RETURN_ARG(QString, out0), Q_ARG(QString, argc_1));
    return out0;
}

QVariantList Dbus_demo_exampleAdaptor::return_variantlist()
{
    // handle method call local.dbus_demo_example.return_variantlist
    QVariantList out0;
    QMetaObject::invokeMethod(parent(), "return_variantlist", Q_RETURN_ARG(QVariantList, out0));
    return out0;
}

void Dbus_demo_exampleAdaptor::set_integer(int argc)
{
    // handle method call local.dbus_demo_example.set_integer
    QMetaObject::invokeMethod(parent(), "set_integer", Q_ARG(int, argc));
}

void Dbus_demo_exampleAdaptor::set_string(const QString &argc)
{
    // handle method call local.dbus_demo_example.set_string
    QMetaObject::invokeMethod(parent(), "set_string", Q_ARG(QString, argc));
}

void Dbus_demo_exampleAdaptor::set_variantlist(int cnt, const QVariantList &argc)
{
    // handle method call local.dbus_demo_example.set_variantlist
    QMetaObject::invokeMethod(parent(), "set_variantlist", Q_ARG(int, cnt), Q_ARG(QVariantList, argc));
}

int Dbus_demo_exampleAdaptor::set_variantlist_2(const QVariantList &argc)
{
    // handle method call local.dbus_demo_example.set_variantlist_2
    int out0;
    QMetaObject::invokeMethod(parent(), "set_variantlist_2", Q_RETURN_ARG(int, out0), Q_ARG(QVariantList, argc));
    return out0;
}

