#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSettings>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QSettings *mqsettings;
};

#endif // WIDGET_H
