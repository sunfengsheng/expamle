#ifndef SNIWATCHER_H
#define SNIWATCHER_H

#include <QWidget>
#include <QtDBus/QtDBus>
#include "statusnotifierwatcher_interface.h"
class SniWatcher : public QObject
{
    Q_OBJECT

public:
    SniWatcher(QWidget *parent = nullptr);
    ~SniWatcher();
    void init();
    void newItem(const QString &service);

private:

private:
    QString m_serviceName;
    org::kde::StatusNotifierWatcher *m_statusNotifierWatcher;

protected Q_SLOTS:
    void serviceChange(const QString& name,
                       const QString& oldOwner,
                       const QString& newOwner);
    void registerWatcher(const QString& service);
    void unregisterWatcher(const QString& service);
    void serviceRegistered(const QString &service);
    void serviceUnregistered(const QString &service);

};
#endif // SNIWATCHER_H
