/****************************************************************************
** Meta object code from reading C++ file 'ScriptDocument.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ScriptDocument.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptDocument.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScriptDocument_t {
    QByteArrayData data[16];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptDocument_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptDocument_t qt_meta_stringdata_ScriptDocument = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ScriptDocument"
QT_MOC_LITERAL(1, 15, 11), // "textChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "text"
QT_MOC_LITERAL(4, 33, 15), // "filePathChanged"
QT_MOC_LITERAL(5, 49, 4), // "path"
QT_MOC_LITERAL(6, 54, 12), // "dirtyChanged"
QT_MOC_LITERAL(7, 67, 5), // "dirty"
QT_MOC_LITERAL(8, 73, 7), // "setText"
QT_MOC_LITERAL(9, 81, 10), // "recordUndo"
QT_MOC_LITERAL(10, 92, 9), // "markDirty"
QT_MOC_LITERAL(11, 102, 8), // "loadText"
QT_MOC_LITERAL(12, 111, 11), // "setFilePath"
QT_MOC_LITERAL(13, 123, 10), // "clearDirty"
QT_MOC_LITERAL(14, 134, 4), // "undo"
QT_MOC_LITERAL(15, 139, 4) // "redo"

    },
    "ScriptDocument\0textChanged\0\0text\0"
    "filePathChanged\0path\0dirtyChanged\0"
    "dirty\0setText\0recordUndo\0markDirty\0"
    "loadText\0setFilePath\0clearDirty\0undo\0"
    "redo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptDocument[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   78,    2, 0x0a /* Public */,
       8,    2,   85,    2, 0x2a /* Public | MethodCloned */,
       8,    1,   90,    2, 0x2a /* Public | MethodCloned */,
      11,    1,   93,    2, 0x0a /* Public */,
      12,    1,   96,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,    3,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    9,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScriptDocument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptDocument *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->filePathChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->dirtyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->setText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->loadText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setFilePath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->clearDirty(); break;
        case 9: _t->undo(); break;
        case 10: _t->redo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScriptDocument::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptDocument::textChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScriptDocument::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptDocument::filePathChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScriptDocument::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptDocument::dirtyChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScriptDocument::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScriptDocument.data,
    qt_meta_data_ScriptDocument,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScriptDocument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptDocument::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptDocument.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScriptDocument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ScriptDocument::textChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScriptDocument::filePathChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScriptDocument::dirtyChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
