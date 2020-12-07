#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include "server.h"

class tcpserver : public QDialog
{
    Q_OBJECT

public:
    tcpserver(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~tcpserver();

private:
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;


private:
    int port;
    Server *server;

public slots:
    void slotCreateServer();
    void updateServer(QString,int);


};
#endif // TCPSERVER_H
