/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Copyright: 2010-2011 Razor team
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * Copyright: 2019-2020 UKUI team
* Modified by  hepuyao <hepuyao@kylinos.cn>
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


#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
#include <QFrame>
#include <QList>
#include <QDir>

#include <X11/X.h>
#include <X11/extensions/Xdamage.h>

#include "xfitman.h"

#define TRAY_ICON_SIZE_DEFAULT 16

class QWidget;
class UKUIPanel;
int windowErrorHandler(Display *d, XErrorEvent *e);
class TrayIcon: public QFrame
{
    Q_OBJECT

public:
    TrayIcon(Window iconId, QSize const & iconSize, QWidget* parent);
    virtual ~TrayIcon();

public:
    QImage TrayImage;
    Window WindowId;

Q_SIGNALS:
    void addImage(QImage image);

protected:
    bool event(QEvent *event);
    void createIcon();

private:
    void init();
    QRect iconGeometry();
    Window mIconId;
    Window mWindowId;
    QSize mIconSize;
    Damage mDamage;
    Display* mDisplay;

    QSize mRectSize;

    QTimer *mTimer;
};

#endif // TRAYICON_H
