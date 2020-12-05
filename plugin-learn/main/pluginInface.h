#ifndef PLUGININFACE_H
#define PLUGININFACE_H
#include <QtPlugin>
#include <QObject>
class QWidget;
class QString;

class AnimalInterface
{
public:
    virtual const QString name() = 0;

};

#endif // PLUGININFACE_H
