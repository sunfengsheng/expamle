QT       += core gui widgets
TARGET = plugin-learn
CONFIG += c++11
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

SOURCES  += \
    main.cpp \
    pluginmanager.cpp \
    widget.cpp\
    pulgin1interface.cpp
HEADERS  += \
    pluginInface.h \
    pluginmanager.h \
    widget.h\
    pulgin1interface.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
