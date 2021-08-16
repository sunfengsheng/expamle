#include "sniwatcher.h"
#include "dbusproperties.h"
static const QString s_watcherServiceName(QStringLiteral("org.kde.StatusNotifierWatcher"));
SniWatcher::SniWatcher(QWidget *parent)
{
    m_statusNotifierWatcher=NULL;
    init();
}

SniWatcher::~SniWatcher()
{
}

void SniWatcher::init(){
    if (QDBusConnection::sessionBus().isConnected()) {
        m_serviceName = "org.kde.StatusNotifierHost-" + QString::number(QCoreApplication::applicationPid());
        QDBusConnection::sessionBus().registerService(m_serviceName);

        QDBusServiceWatcher *watcher = new QDBusServiceWatcher(s_watcherServiceName, QDBusConnection::sessionBus(),
                                                               QDBusServiceWatcher::WatchForOwnerChange, this);
        connect(watcher, &QDBusServiceWatcher::serviceOwnerChanged,
                this, &SniWatcher::serviceChange);
        registerWatcher(s_watcherServiceName);
    }
}

void SniWatcher::registerWatcher(const QString& service)
{
    //qCDebug(DATAENGINE_SNI)<<"service appeared"<<service;
    if (service == s_watcherServiceName) {

        m_statusNotifierWatcher = new org::kde::StatusNotifierWatcher(s_watcherServiceName, QStringLiteral("/StatusNotifierWatcher"),
                                      QDBusConnection::sessionBus());
        if (m_statusNotifierWatcher->isValid()) {
            m_statusNotifierWatcher->call(QDBus::NoBlock, QStringLiteral("RegisterStatusNotifierHost"), m_serviceName);

            OrgFreedesktopDBusPropertiesInterface  propetriesIface(m_statusNotifierWatcher->service(), m_statusNotifierWatcher->path(), m_statusNotifierWatcher->connection());

            QDBusPendingReply<QDBusVariant> pendingItems = propetriesIface.Get(m_statusNotifierWatcher->interface(), "RegisteredStatusNotifierItems");

            QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pendingItems, this);
            connect(watcher, &QDBusPendingCallWatcher::finished, this, [=]() {
                watcher->deleteLater();
                QDBusReply<QDBusVariant> reply = *watcher;
                QStringList registeredItems = reply.value().variant().toStringList();
                foreach (const QString &service, registeredItems) {
                    newItem(service);
                }
            });

            connect(m_statusNotifierWatcher, &OrgKdeStatusNotifierWatcherInterface::StatusNotifierItemRegistered, this, &SniWatcher::serviceRegistered);
            connect(m_statusNotifierWatcher, &OrgKdeStatusNotifierWatcherInterface::StatusNotifierItemUnregistered, this, &SniWatcher::serviceUnregistered);

        } else {
            delete m_statusNotifierWatcher;
            m_statusNotifierWatcher = nullptr;
        }
    }
}

void SniWatcher::serviceChange(const QString& name, const QString& oldOwner, const QString& newOwner)
{
    qDebug()<< "Service" << name << "status change, old owner:" << oldOwner << "new:" << newOwner;

    if (newOwner.isEmpty()) {
        //unregistered
        unregisterWatcher(name);
    } else if (oldOwner.isEmpty()) {
        //registered
        registerWatcher(name);
    }
}

void SniWatcher::unregisterWatcher(const QString& service)
{
    if (service == s_watcherServiceName) {
        qDebug()<< s_watcherServiceName << "disappeared";

        disconnect(m_statusNotifierWatcher, &OrgKdeStatusNotifierWatcherInterface::StatusNotifierItemRegistered, this, &SniWatcher::serviceRegistered);
        disconnect(m_statusNotifierWatcher, &OrgKdeStatusNotifierWatcherInterface::StatusNotifierItemUnregistered, this, &SniWatcher::serviceUnregistered);

//        removeAllSources();

        delete m_statusNotifierWatcher;
        m_statusNotifierWatcher = nullptr;
    }
}

void SniWatcher::serviceRegistered(const QString &service)
{
    qDebug() << "Registering"<<service;
    newItem(service);
}

void SniWatcher::serviceUnregistered(const QString &service)
{
    qDebug()<<"serviceUnregistered"<<service;
//    removeSource(service);
}

void SniWatcher::newItem(const QString &service)
{
}
