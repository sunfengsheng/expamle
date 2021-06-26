#ifndef TRAYTOSTATUSNOTIFIER_H
#define TRAYTOSTATUSNOTIFIER_H

#include <QWidget>
#include <QDebug>
#include <QAbstractNativeEventFilter>
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QFileInfo>
#include <QSystemTrayIcon>

#include <X11/X.h>
#include <X11/Xlib.h>

#include <QtX11Extras/QX11Info>

#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xrender.h>
#include <X11/extensions/Xdamage.h>

#include <xcb/xcb.h>
#include <xcb/damage.h>
#include <xcb/xcb_event.h>

#include <KWindowSystem>

#include "fixx11h.h"
#include <glib.h>


class TrayToStatusnotifier : public QWidget,QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    TrayToStatusnotifier(QWidget *parent = nullptr);
    ~TrayToStatusnotifier();

    bool nativeEventFilter(const QByteArray &eventType, void *message, long *);

private:
    void startTray();
    VisualID getVisual();

    void clientMessageEvent(xcb_generic_event_t *e);

    void createSystemIcon(QIcon icon);

    void drawIcon(Window id);

    QString pidToIcon(int pid);

private:
    Display* mDisplay;
    Atom _NET_SYSTEM_TRAY_OPCODE;
    Window mTrayId;
    QSize mIconSize;
    QHBoxLayout *mLayout;


    int mDamageEvent;
    int mDamageError;

    int count;

protected:



};
#endif // TRAYTOSTATUSNOTIFIER_H
