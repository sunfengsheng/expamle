#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGSettings>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QGSettings *gsetting;
};

#endif // WIDGET_H
