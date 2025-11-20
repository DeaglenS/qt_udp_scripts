QT += core gui widgets network script

CONFIG += c++11
TEMPLATE = app
TARGET = ScriptRunner

INCLUDEPATH += $$PWD/../core
INCLUDEPATH += $$PWD/../network

CONFIG(debug, debug|release) {
    LIBS += -L$$OUT_PWD/../core/debug -lcore
    LIBS += -L$$OUT_PWD/../network/debug -lnetwork
} else {
    LIBS += -L$$OUT_PWD/../core/release -lcore
    LIBS += -L$$OUT_PWD/../network/release -lnetwork
}

SOURCES += \
    main.cpp \
    CanvasWidget.cpp \
    ScriptRunnerWindow.cpp

HEADERS += \
    CanvasWidget.h \
    ScriptRunnerWindow.h
