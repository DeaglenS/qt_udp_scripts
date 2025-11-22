/****************************************************************************
** Meta object code from reading C++ file 'ScriptEditorWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ScriptEditorWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptEditorWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScriptEditorWindow_t {
    QByteArrayData data[15];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptEditorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptEditorWindow_t qt_meta_stringdata_ScriptEditorWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ScriptEditorWindow"
QT_MOC_LITERAL(1, 19, 18), // "openScriptFromFile"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "saveScriptToFile"
QT_MOC_LITERAL(4, 56, 12), // "saveScriptAs"
QT_MOC_LITERAL(5, 69, 19), // "insertExampleScript"
QT_MOC_LITERAL(6, 89, 11), // "bindUdpPort"
QT_MOC_LITERAL(7, 101, 18), // "sendScriptToRunner"
QT_MOC_LITERAL(8, 120, 19), // "handleScriptRequest"
QT_MOC_LITERAL(9, 140, 17), // "TransportEndpoint"
QT_MOC_LITERAL(10, 158, 6), // "sender"
QT_MOC_LITERAL(11, 165, 25), // "handleServerStatusMessage"
QT_MOC_LITERAL(12, 191, 7), // "message"
QT_MOC_LITERAL(13, 199, 16), // "onProfileChanged"
QT_MOC_LITERAL(14, 216, 5) // "index"

    },
    "ScriptEditorWindow\0openScriptFromFile\0"
    "\0saveScriptToFile\0saveScriptAs\0"
    "insertExampleScript\0bindUdpPort\0"
    "sendScriptToRunner\0handleScriptRequest\0"
    "TransportEndpoint\0sender\0"
    "handleServerStatusMessage\0message\0"
    "onProfileChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptEditorWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      11,    1,   68,    2, 0x08 /* Private */,
      13,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void ScriptEditorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptEditorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openScriptFromFile(); break;
        case 1: _t->saveScriptToFile(); break;
        case 2: _t->saveScriptAs(); break;
        case 3: _t->insertExampleScript(); break;
        case 4: _t->bindUdpPort(); break;
        case 5: _t->sendScriptToRunner(); break;
        case 6: _t->handleScriptRequest((*reinterpret_cast< const TransportEndpoint(*)>(_a[1]))); break;
        case 7: _t->handleServerStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onProfileChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScriptEditorWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ScriptEditorWindow.data,
    qt_meta_data_ScriptEditorWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScriptEditorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptEditorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptEditorWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ScriptEditorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
