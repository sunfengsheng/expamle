#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include <QUdpSocket>
#include <QTimer>
class UdpClient : public QDialog
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~UdpClient();

private:
    QTextEdit *ReceiveTextEdit;
    QPushButton *CloseBtn;
    QVBoxLayout *mainLayout;

public slots:
    void CloseBtnClicked();
    void dataReceived();
private:
    int port;
    QUdpSocket *udpSocket;

};
#endif // DIALOG_H
