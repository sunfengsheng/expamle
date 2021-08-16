QT       += core gui KWindowSystem x11extras dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 link_pkgconfig
PKGCONFIG += xcb x11 xrender xcb-util xcb-damage xcb-image xcb-composite xcb-shape

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_xcbDISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    snixembedproxy.cpp \
    sniproxy.cpp \
    snidbus.cpp \
    statusnotifierwatcher_interface.cpp

HEADERS += \
    snixembedproxy.h \
    sniproxy.h \
    snidbus.h \
    statusnotifierwatcher_interface.h \
    systemtraytypedefs.h \
    xcbutilss.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
