#ifndef CONCURRENT_H
#define CONCURRENT_H

#include <QWidget>
#include <QtConcurrent/qtconcurrent_global.h>
void Func();
class Concurrent : public QWidget
{
    Q_OBJECT

public:
    Concurrent(QWidget *parent = nullptr);
    ~Concurrent();

private:


};
#endif // CONCURRENT_H
