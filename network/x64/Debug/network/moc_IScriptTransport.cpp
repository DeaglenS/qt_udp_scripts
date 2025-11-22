/****************************************************************************
** Meta object code from reading C++ file 'IScriptTransport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../IScriptTransport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IScriptTransport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IScriptTransport_t {
    QByteArrayData data[9];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IScriptTransport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IScriptTransport_t qt_meta_stringdata_IScriptTransport = {
    {
QT_MOC_LITERAL(0, 0, 16), // "IScriptTransport"
QT_MOC_LITERAL(1, 17, 14), // "scriptReceived"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "script"
QT_MOC_LITERAL(4, 40, 17), // "TransportEndpoint"
QT_MOC_LITERAL(5, 58, 6), // "sender"
QT_MOC_LITERAL(6, 65, 15), // "scriptRequested"
QT_MOC_LITERAL(7, 81, 13), // "statusMessage"
QT_MOC_LITERAL(8, 95, 7) // "message"

    },
    "IScriptTransport\0scriptReceived\0\0"
    "script\0TransportEndpoint\0sender\0"
    "scriptRequested\0statusMessage\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IScriptTransport[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       6,    1,   34,    2, 0x06 /* Public */,
       7,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void IScriptTransport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IScriptTransport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scriptReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const TransportEndpoint(*)>(_a[2]))); break;
        case 1: _t->scriptRequested((*reinterpret_cast< const TransportEndpoint(*)>(_a[1]))); break;
        case 2: _t->statusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TransportEndpoint >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TransportEndpoint >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IScriptTransport::*)(const QByteArray & , const TransportEndpoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IScriptTransport::scriptReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IScriptTransport::*)(const TransportEndpoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IScriptTransport::scriptRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IScriptTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IScriptTransport::statusMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IScriptTransport::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_IScriptTransport.data,
    qt_meta_data_IScriptTransport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IScriptTransport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IScriptTransport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IScriptTransport.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IScriptTransport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void IScriptTransport::scriptReceived(const QByteArray & _t1, const TransportEndpoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IScriptTransport::scriptRequested(const TransportEndpoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IScriptTransport::statusMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
