#include "traytostatusnotifier.h"
#include "trayicon.h"
#include "xfitman.h"

#define _NET_SYSTEM_TRAY_ORIENTATION_HORZ 0
#define _NET_SYSTEM_TRAY_ORIENTATION_VERT 1

#define SYSTEM_TRAY_REQUEST_DOCK    0
#define SYSTEM_TRAY_BEGIN_MESSAGE   1
#define SYSTEM_TRAY_CANCEL_MESSAGE  2


TrayToStatusnotifier::TrayToStatusnotifier(QWidget *parent)
    : QWidget(parent),
      mDisplay(QX11Info::display()),
      mIconSize(50,50)
{
    this->setFixedSize(800,500);
    mLayout=new QHBoxLayout(this);
    _NET_SYSTEM_TRAY_OPCODE = XfitMan::atom("_NET_SYSTEM_TRAY_OPCODE");
    qApp->installNativeEventFilter(this);
    startTray();
}

TrayToStatusnotifier::~TrayToStatusnotifier()
{
}

void TrayToStatusnotifier::startTray()
{
    Display* dsp = mDisplay;
    Window root = QX11Info::appRootWindow();

    QString s = QString("_NET_SYSTEM_TRAY_S%1").arg(DefaultScreen(dsp));
    Atom _NET_SYSTEM_TRAY_S = XfitMan::atom(s.toLatin1());
    //this limit the tray apps  | will not run more Same apps
    if (XGetSelectionOwner(dsp, _NET_SYSTEM_TRAY_S) != None){
        qWarning() << "Another systray is running";
        return;
    }

    // init systray protocol
    mTrayId = XCreateSimpleWindow(dsp, root, -1, -1, 1, 1, 0, 0, 0);

    XSetSelectionOwner(dsp, _NET_SYSTEM_TRAY_S, mTrayId, CurrentTime);
    if (XGetSelectionOwner(dsp, _NET_SYSTEM_TRAY_S) != mTrayId){
        qWarning() << "Can't get systray manager";
        return;
    }

    int orientation = _NET_SYSTEM_TRAY_ORIENTATION_HORZ;
    XChangeProperty(dsp,
                    mTrayId,
                    XfitMan::atom("_NET_SYSTEM_TRAY_ORIENTATION"),
                    XA_CARDINAL,
                    32,
                    PropModeReplace,
                    (unsigned char *) &orientation,
                    1);

    // ** Visual ********************************
    VisualID visualId = getVisual();
    if (visualId){
        XChangeProperty(mDisplay,
                        mTrayId,
                        XfitMan::atom("_NET_SYSTEM_TRAY_VISUAL"),
                        XA_VISUALID,
                        32,
                        PropModeReplace,
                        (unsigned char*)&visualId,
                        1);
    }

    XClientMessageEvent ev;
    ev.type = ClientMessage;
    ev.window = root;
    ev.message_type = XfitMan::atom("MANAGER");
    ev.format = 32;
    ev.data.l[0] = CurrentTime;
    ev.data.l[1] = _NET_SYSTEM_TRAY_S;
    ev.data.l[2] = mTrayId;
    ev.data.l[3] = 0;
    ev.data.l[4] = 0;
    XSendEvent(dsp, root, False, StructureNotifyMask, (XEvent*)&ev);
    XDamageQueryExtension(mDisplay, &mDamageEvent, &mDamageError);
}


VisualID TrayToStatusnotifier::getVisual()
{
    VisualID visualId = 0;
    Display* dsp = mDisplay;

    XVisualInfo templ;
    templ.screen=QX11Info::appScreen();
    templ.depth=32;
    templ.c_class=TrueColor;

    int nvi;
    XVisualInfo* xvi = XGetVisualInfo(dsp, VisualScreenMask|VisualDepthMask|VisualClassMask, &templ, &nvi);

    if (xvi)
    {
        int i;
        XRenderPictFormat* format;
        for (i = 0; i < nvi; i++){
            format = XRenderFindVisualFormat(dsp, xvi[i].visual);
            if (format &&
                    format->type == PictTypeDirect &&
                    format->direct.alphaMask)
            {
                visualId = xvi[i].visualid;
                break;
            }
        }
        XFree(xvi);
    }

    return visualId;
}


bool TrayToStatusnotifier::nativeEventFilter(const QByteArray &eventType, void *message, long *)
{
    if (eventType != "xcb_generic_event_t")
        return false;

    xcb_generic_event_t* event = static_cast<xcb_generic_event_t *>(message);

    int event_type = event->response_type & ~0x80;

    switch (event_type)
    {
    /* 监听到托盘应用的启动事件
     */
    case ClientMessage:
        clientMessageEvent(event);
        break;


        /*
         * 监听到托盘应用的退出事件
         */
    case DestroyNotify: {
        /*
         * 在这里本应该刷新收纳栏 handleStorageUi()
         * 由于收纳栏不刷新可能会导致任务栏的崩溃
         * 在freeze信号接受的地方freezeTrayApp（）同样进行刷新收纳栏的操作
         * 但是如果在这里刷新收纳栏目会导致收纳栏的应用异常退出
         */

        unsigned long event_window;
        event_window = reinterpret_cast<xcb_destroy_notify_event_t*>(event)->window;
        break;
    }
    default:
        if (event_type == mDamageEvent + XDamageNotify)
        {
            xcb_damage_notify_event_t* dmg = reinterpret_cast<xcb_damage_notify_event_t*>(event);
        }
        break;
    }

    return false;
}

void TrayToStatusnotifier::clientMessageEvent(xcb_generic_event_t *e)
{
    unsigned long opcode;
    unsigned long message_type;
    Window id;
    xcb_client_message_event_t* event = reinterpret_cast<xcb_client_message_event_t*>(e);
    uint32_t* data32 = event->data.data32;
    message_type = event->type;
    opcode = data32[1];
    if(message_type != _NET_SYSTEM_TRAY_OPCODE)
        return;

    switch (opcode)
    {
    case SYSTEM_TRAY_REQUEST_DOCK:
        id = data32[2];
        if(id){
            drawIcon(id);
        }

    case SYSTEM_TRAY_BEGIN_MESSAGE:
    case SYSTEM_TRAY_CANCEL_MESSAGE:
//        qDebug() << "we don't show balloon messages.";
        break;

    default:
        //            if (opcode == xfitMan().atom("_NET_SYSTEM_TRAY_MESSAGE_DATA"))
        //                qDebug() << "message from dockapp:" << e->data.b;
        //            else
        //                qDebug() << "SYSTEM_TRAY : unknown message type" << opcode;
        break;
    }
}

void TrayToStatusnotifier::drawIcon(Window id){
    TrayIcon *icon= new TrayIcon(id, mIconSize, this);
    mLayout->addWidget(icon);
    connect(icon,&TrayIcon::addImage,this,[=](){
        QDir mTrayDir;
        mTrayDir.setPath("res/");
        QStringList fileList=mTrayDir.entryList();
        for(int i=0;i<fileList.size();i++){
            if(fileList.at(i).contains(QString::number(id))){
                QLabel *label=new QLabel(this);
                createSystemIcon(QIcon("res/"+fileList.at(i)));
                label->setPixmap("res/"+fileList.at(i));
                mLayout->addWidget(label);
                icon->hide();
            }
        }
    });

    QString name = xfitMan().getApplicationName(id);
    QString title = xfitMan().getWindowTitle(id);
    qDebug()<<"WindowId"<<icon->WindowId;
    qDebug()<<"id"<<id;
    qDebug()<<"name :"<<name;
    qDebug()<<"title :"<<title;
    KWindowInfo info(id, NET::WMVisibleName | NET::WMName);

    pidToIcon(info.pid());
    QIcon::fromTheme(pidToIcon(info.pid()));
    createSystemIcon( QIcon::fromTheme(pidToIcon(info.pid())));



}

void TrayToStatusnotifier::createSystemIcon(QIcon icon){
    QSystemTrayIcon *trayicon=new QSystemTrayIcon(icon);
    trayicon->show();
}

QString TrayToStatusnotifier::pidToIcon(int pid){
    QIcon icon;
    QString desktop_file_path = "";
    QFile file("/proc/" + QString::number(pid) + "/environ");
    file.open(QIODevice::ReadOnly);
    QByteArray BA = file.readAll();
    file.close();
    QList<QByteArray> list_BA = BA.split('\0');
    for(int i=0; i<list_BA.length(); i++){
       if(list_BA.at(i).startsWith("GIO_LAUNCHED_DESKTOP_FILE=")){
           desktop_file_path = list_BA.at(i);
           qDebug() << desktop_file_path;
           desktop_file_path = desktop_file_path.mid(desktop_file_path.indexOf("=") + 1);
           qDebug() << desktop_file_path;
           break;
       }
    }

    QString icon_path = "";
    file.setFileName(desktop_file_path);
    file.open(QIODevice::ReadOnly);
    BA = file.readAll();
    file.close();
    list_BA = BA.split('\n');
    for(int i=0; i<list_BA.length(); i++){
        if(list_BA.at(i).toLower().startsWith("icon=")){
            icon_path = list_BA.at(i);
            qDebug() << list_BA.at(i);
            icon_path = icon_path.mid(icon_path.indexOf("=") + 1);
            qDebug() <<"icon :"<<icon_path;
            icon = QIcon(icon_path);
            break;
        }
    }
    return icon_path;
}
