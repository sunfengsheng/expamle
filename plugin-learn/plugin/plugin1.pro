QT       += core gui widgets
TARGET = Plugin1
TEMPLATE = lib
CONFIG += c++11
CONFIG +=plugin
SOURCES  +=plugin.cpp

HEADERS  +=plugin.h


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
