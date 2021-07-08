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

    m_Menu->addAction(QString("open"));

    m_Menu->addSeparator();

    connect(m_TrayIcon,&UkuiSystemTrayIcon::activated,this,&UkuiSystemTrayIconTest::activate);
    connect(m_TrayIcon,&UkuiSystemTrayIcon::Context,this,&UkuiSystemTrayIconTest::Context);
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
    m_Menu->setGeometry(x,y-200,200,200);
    m_Menu->show();
}

