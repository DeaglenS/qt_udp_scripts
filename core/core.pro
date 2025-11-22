QT += core gui widgets

CONFIG += c++11 staticlib
TEMPLATE = lib
TARGET = core

INCLUDEPATH += $$PWD

SOURCES += \
    ScriptCanvas.cpp \
    ScriptDocument.cpp \
    CanvasState.cpp

HEADERS += \
    ScriptCanvas.h \
    Shapes.h \
    ScriptDocument.h \
    CanvasState.h

