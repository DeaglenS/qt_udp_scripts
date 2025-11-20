QT += core gui widgets network

CONFIG += c++11
TEMPLATE = app
TARGET = ScriptEditor

INCLUDEPATH += $$PWD/../network
INCLUDEPATH += $$PWD/../core

CONFIG(debug, debug|release) {
    LIBS += -L$$OUT_PWD/../network/debug -lnetwork
    LIBS += -L$$OUT_PWD/../core/debug -lcore
} else {
    LIBS += -L$$OUT_PWD/../network/release -lnetwork
    LIBS += -L$$OUT_PWD/../core/release -lcore
}

SOURCES += \
    main.cpp \
    ScriptEditorWindow.cpp \
    ScriptEditorController.cpp

HEADERS += \
    ScriptEditorWindow.h \
    ScriptEditorController.h
