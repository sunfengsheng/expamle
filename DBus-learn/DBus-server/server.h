#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDBusAbstractAdaptor>
#include <QDBusConnection>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    bool methodOne(QString arg);
    QString methodTwo(int arg);

Q_SIGNALS:
    int signals1(int arg);
};


class FilectrlAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.learn.DBus.server")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.learn.DBus.server\">\n"
"    <method name=\"methodOne\">\n"
"      <arg direction=\"out\" type=\"b\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"arg\"/>\n"
"    </method>\n"
"    <method name=\"methodTwo\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"      <arg direction=\"in\" type=\"i\" name=\"arg\"/>\n"
"    </method>\n"
"    <signal name=\"signals1\">\n"
"    <arg name=\"nickname\" type=\"i\" direction=\"out\"/>"
"    </signal>\n"
"  </interface>\n"
        "")
public:
    FilectrlAdaptor(QObject *parent);
    virtual ~FilectrlAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    bool methodOne(const QString &arg);
    QString methodTwo(const int &arg);

Q_SIGNALS:
    int signals1(int arg);
};

#endif // WIDGET_H
