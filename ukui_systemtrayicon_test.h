#ifndef UKUISYSTEMTRAYICONTEST_H
#define UKUISYSTEMTRAYICONTEST_H

#include <QWidget>
#include <QMenu>

#include "ukui_systemtrayicon.h"
class UkuiSystemTrayIconTest : public QWidget
{
    Q_OBJECT

public:
    UkuiSystemTrayIconTest(QWidget *parent = nullptr);
    ~UkuiSystemTrayIconTest();

private:
     UkuiSystemTrayIcon *m_TrayIcon;
     QMenu *m_Menu;

private slots:
     void activate(int x,int y);
     void Context(int x,int y);

};
#endif // UKUISYSTEMTRAYICONTEST_H
