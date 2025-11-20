QT += core network

CONFIG += c++11 staticlib
TEMPLATE = lib
TARGET = network

INCLUDEPATH += $$PWD

SOURCES += \
    UdpScriptTransport.cpp \
    ProfileManager.cpp

HEADERS += \
    IScriptTransport.h \
    UdpScriptTransport.h \
    ProfileManager.h

