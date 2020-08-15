#include "dbus.h"

Dbus::Dbus(QObject *parent) : QObject(parent)
{

}

bool Dbus::method1(int input){
    return true;
}
