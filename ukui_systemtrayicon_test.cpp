#include <QApplication>
#include <QDebug>

#include "ukui_systemtrayicon_test.h"
UkuiSystemTrayIconTest::UkuiSystemTrayIconTest(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<qApp->applicationPid();
    int pid = qApp->applicationPid();
    m_TrayIcon = new UkuiSystemTrayIcon(this,pid);
    m_Menu = new QMenu(this);

    QAction *a2 = new QAction("a2", m_Menu);
    m_Menu->addAction(a2);
    m_TrayIcon->setMenu(m_Menu);
    connect(m_TrayIcon,&UkuiSystemTrayIcon::activated,this,&UkuiSystemTrayIconTest::activate);
    connect(m_TrayIcon,&UkuiSystemTrayIcon::Context,this,&UkuiSystemTrayIconTest::Context);
    connect(a2,&QAction::triggered,this,[=](){
        qDebug()<<"a2 is click !!!!!!!!!";
        qApp->exit();
    });
    m_TrayIcon->setIcon(QIcon::fromTheme("network-wired-connected-symbolic"));
}

UkuiSystemTrayIconTest::~UkuiSystemTrayIconTest()
{
}
void UkuiSystemTrayIconTest::activate(int x,int y){
    if(this->isHidden()){
        this->show();
    }else{
        this->hide();
    }
}

void UkuiSystemTrayIconTest::Context(int x,int y){
//    m_Menu->setGeometry(x,y-200,200,200);
//    m_Menu->show();
}

