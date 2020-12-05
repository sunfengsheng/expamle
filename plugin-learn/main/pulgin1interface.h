#ifndef PULGIN1INTERFACE_H
#define PULGIN1INTERFACE_H

#include <QObject>
#include "../main/pluginInface.h"
#include <QPushButton>
class pulgin1interface :  public  AnimalInterface
{
public:
    virtual QPushButton *createPluginWidget(QWidget *parent) = 0;

signals:

};

#define AbstractInterface_iid "Welcome to use focusmode"
Q_DECLARE_INTERFACE(pulgin1interface,AbstractInterface_iid)
#endif // PULGIN1INTERFACE_H
