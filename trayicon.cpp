/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Copyright: 2011 Razor team
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * Copyright: 2019-2020 UKUI team
 * Modified by  minglequn <minglequn@kylinos.cn>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


// Warning: order of those include is important.
#include <QDebug>
#include <QApplication>
#include <QResizeEvent>
#include <QPainter>
#include <QBitmap>
#include <QStyle>
#include <QScreen>

#include "trayicon.h"
#include "traytostatusnotifier.h"

#include <QtX11Extras/QX11Info>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xcomposite.h>
#include <X11/extensions/Xrender.h>
#include <QTimer>

#define XEMBED_EMBEDDED_NOTIFY 0


static bool xError;

/************************************************

************************************************/
int windowErrorHandler(Display *d, XErrorEvent *e)
{
    xError = true;
    if (e->error_code != BadWindow) {
        char str[1024];
        XGetErrorText(d, e->error_code,  str, 1024);
        qWarning() << "Error handler" << e->error_code
                   << str;
    }
    return 0;
}


/************************************************

 ************************************************/
TrayIcon::TrayIcon(Window iconId, QSize const & iconSize, QWidget* parent):
    QFrame(parent),
    mIconId(iconId),
    mWindowId(0),
    mIconSize(iconSize),
    mDamage(0),
    mDisplay(QX11Info::display())
{
    setObjectName("TrayIcon");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QTimer::singleShot(200, [this] { init();});

    mTimer=new QTimer(this);
    connect(mTimer,&QTimer::timeout,this,[=](){
        createIcon();
    });
    mTimer->start(200);

    mRectSize.setWidth(30);
    mRectSize.setHeight(40);
    QString str("res");
    QDir dir;
    dir.mkdir(str);
}

/************************************************

 ************************************************/
void TrayIcon::init()
{
    Display* dsp = mDisplay;

    XWindowAttributes attr;
    if (! XGetWindowAttributes(dsp, mIconId, &attr))
    {
        deleteLater();
        return;
    }

    unsigned long mask = 0;
    XSetWindowAttributes set_attr;

    Visual* visual = attr.visual;
    set_attr.colormap = attr.colormap;
    set_attr.background_pixel = 0;
    set_attr.border_pixel = 0;
    mask = CWColormap|CWBackPixel|CWBorderPixel;

    const QRect icon_geom = iconGeometry();
    mWindowId = XCreateWindow(dsp, this->winId(), icon_geom.x(), icon_geom.y(), icon_geom.width() * metric(PdmDevicePixelRatio), icon_geom.height() * metric(PdmDevicePixelRatio),
                              0, attr.depth, InputOutput, visual, mask, &set_attr);
    WindowId=mWindowId;

    xError = false;
    XErrorHandler old;
    old = XSetErrorHandler(windowErrorHandler);
    XReparentWindow(dsp, mIconId, mWindowId, 0, 0);
    XSync(dsp, false);
    XSetErrorHandler(old);

    if (xError)
    {
        qWarning() << "****************************************";
        qWarning() << "* Not icon_swallow                     *";
        qWarning() << "****************************************";
        XDestroyWindow(dsp, mWindowId);
        mWindowId = 0;
        deleteLater();
        return;
    }

    {
        Atom acttype;
        int actfmt;
        unsigned long nbitem, bytes;
        unsigned char *data = 0;
        int ret;

        ret = XGetWindowProperty(dsp, mIconId, XfitMan::atom("_XEMBED_INFO"),
                                 0, 2, false, XfitMan::atom("_XEMBED_INFO"),
                                 &acttype, &actfmt, &nbitem, &bytes, &data);

        qDebug()<<"data     ::::::"<<data;
        if (ret == Success)
        {
            if (data)
                XFree(data);
        }
        else
        {
            qWarning() << "TrayIcon: xembed error";
            XDestroyWindow(dsp, mWindowId);
            deleteLater();
            return;
        }
    }

    {
        XEvent e;
        e.xclient.type = ClientMessage;
        e.xclient.serial = 0;
        e.xclient.send_event = True;
        e.xclient.message_type = XfitMan::atom("_XEMBED");
        e.xclient.window = mIconId;
        e.xclient.format = 32;
        e.xclient.data.l[0] = CurrentTime;
        e.xclient.data.l[1] = XEMBED_EMBEDDED_NOTIFY;
        e.xclient.data.l[2] = 0;
        e.xclient.data.l[3] = mWindowId;
        e.xclient.data.l[4] = 0;
        XSendEvent(dsp, mIconId, false, 0xFFFFFF, &e);
    }

    XSelectInput(dsp, mIconId, StructureNotifyMask);
    mDamage = XDamageCreate(dsp, mIconId, XDamageReportRawRectangles);
    XCompositeRedirectWindow(dsp, mWindowId, CompositeRedirectManual);

    XMapWindow(dsp, mIconId);
    XMapRaised(dsp, mWindowId);

    const QSize req_size{mIconSize * metric(PdmDevicePixelRatio)};
    XResizeWindow(dsp, mIconId, req_size.width(), req_size.height());
}


/************************************************

 ************************************************/
TrayIcon::~TrayIcon()
{
    Display* dsp = mDisplay;
    XSelectInput(dsp, mIconId, NoEventMask);

    if (mDamage)
        XDamageDestroy(dsp, mDamage);

    // reparent to root
    xError = false;
    XErrorHandler old = XSetErrorHandler(windowErrorHandler);

    XUnmapWindow(dsp, mIconId);
    XReparentWindow(dsp, mIconId, QX11Info::appRootWindow(), 0, 0);

    if (mWindowId)
        XDestroyWindow(dsp, mWindowId);
    XSync(dsp, False);
    XSetErrorHandler(old);
}

/************************************************

 ************************************************/
bool TrayIcon::event(QEvent *event)
{
    if (mWindowId)
    {
        switch (event->type())
        {
        case QEvent::Paint:
//            draw(static_cast<QPaintEvent*>(event));
            break;
        }
    }

    return QFrame::event(event);
}


/************************************************

 ************************************************/
QRect TrayIcon::iconGeometry()
{
    QRect res = QRect(QPoint(0, 0), mIconSize);

    res.moveCenter(QRect(0, 0, width(), height()).center());
    return res;
}

void TrayIcon::createIcon()
{
    Display* dsp = mDisplay;
    XWindowAttributes attr;
    if (!XGetWindowAttributes(dsp, mIconId, &attr))
    {
        qWarning() << "Paint error";
        return;
    }
    QImage image;
    XImage* ximage = XGetImage(dsp, mIconId, 0, 0, attr.width, attr.height, AllPlanes, ZPixmap);
    if(ximage)
    {
        image = QImage((const uchar*) ximage->data, ximage->width, ximage->height, ximage->bytes_per_line,  QImage::Format_ARGB32_Premultiplied);
        TrayImage=image;

        TrayImage.save("res/"+QString::number(this->mIconId)+".png");
        mTimer->stop();
        Q_EMIT addImage(TrayImage);
    }
    else
    {
        qWarning() << "    * Error image is NULL";
        XClearArea(mDisplay, (Window)winId(), 0, 0, attr.width, attr.height, False);
        image = qApp->primaryScreen()->grabWindow(mIconId).toImage();
    }
}
