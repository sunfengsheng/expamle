#include "maintest.h"
#include <QDBusInterface>
#include <QDBusReply>
#include <QVariant>
#include <QDebug>
#include <QtDBus>
MainTest::MainTest(QWidget *parent)
    : QWidget(parent)
{
    qDBusRegisterMetaType<QPair<QString,QString>>();
    QDBusInterface *m_interFace=new QDBusInterface ("org.ukui.panel", "/panel/position",
                                                    "org.ukui.panel",
                                                    QDBusConnection::sessionBus());
    if (!m_interFace->isValid())
    {
        qWarning() << qPrintable(QDBusConnection::sessionBus().lastError().message());
    }



    QDBusReply<QVariantMap> PrimaryScreenGeometry_reply = m_interFace->call("GetPrimaryScreenGeometry");
    if (PrimaryScreenGeometry_reply.isValid())
    {
        QVariantMap PrimaryScreenGeometry=PrimaryScreenGeometry_reply.value();
        qDebug()<<"panelposition:"<<PrimaryScreenGeometry.value("panelposition").toString();
        qDebug()<<"primary_screen_x:"<<PrimaryScreenGeometry.value("primary_screen_x").toString();
        qDebug()<<"primary_screen_y:"<<PrimaryScreenGeometry.value("primary_screen_y").toString();
        qDebug()<<"primary_screen_width:"<<PrimaryScreenGeometry.value("primary_screen_width").toString();
        qDebug()<<"primary_screen_height:"<<PrimaryScreenGeometry.value("primary_screen_height").toString();
    }

    QDBusReply<QVariantMap> PrimaryScreenAvailableGeometry_reply = m_interFace->call("GetPrimaryScreenAvailableGeometry");
    if (PrimaryScreenAvailableGeometry_reply.isValid())
    {
        QVariantMap PrimaryScreenGeometry=PrimaryScreenAvailableGeometry_reply.value();
        qDebug()<<"panelposition:"<<PrimaryScreenGeometry.value("panelposition").toString();
        qDebug()<<"available_primary_screen_x:"<<PrimaryScreenGeometry.value("available_primary_screen_x").toString();
        qDebug()<<"available_primary_screen_y:"<<PrimaryScreenGeometry.value("available_primary_screen_y").toString();
        qDebug()<<"available_primary_screen_width:"<<PrimaryScreenGeometry.value("available_primary_screen_width").toString();
        qDebug()<<"available_primary_screen_height:"<<PrimaryScreenGeometry.value("available_primary_screen_height").toString();
    }


    QDBusReply<QVariantMap> PrimaryScreenPhysicalGeometry_reply = m_interFace->call("GetPrimaryScreenPhysicalGeometry");
    if (PrimaryScreenPhysicalGeometry_reply.isValid())
    {
        QVariantMap PrimaryScreenGeometry=PrimaryScreenPhysicalGeometry_reply.value();
        qDebug()<<"panelposition:"<<PrimaryScreenGeometry.value("panelposition").toString();
        qDebug()<<"physical_primary_screen_x:"<<PrimaryScreenGeometry.value("physical_primary_screen_x").toString();
        qDebug()<<"physical_primary_screen_y:"<<PrimaryScreenGeometry.value("physical_primary_screen_y").toString();
        qDebug()<<"physical_primary_screen_width:"<<PrimaryScreenGeometry.value("physical_primary_screen_width").toString();
        qDebug()<<"physical_primary_screen_height:"<<PrimaryScreenGeometry.value("physical_primary_screen_height").toString();
    }

}

MainTest::~MainTest()
{
}

