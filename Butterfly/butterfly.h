#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QFile>
#include <QIcon>
class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *);
    QRectF boundingRect() const;
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;

signals:

};

#endif // BUTTERFLY_H
