#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "../main/pulgin1interface.h"

class plugin : public QObject,public  pulgin1interface
{
    Q_OBJECT
    Q_INTERFACES(pulgin1interface)
    Q_PLUGIN_METADATA(IID "Welcom to use focusmode" FILE "focusplugin.json")
public:
    const QString name() override {return QObject::tr("plugin1");}
    QPushButton *createPluginWidget(QWidget *parent) override;
signals:

};

#endif // PLUGIN_H
