/****************************************************************************
** Meta object code from reading C++ file 'CanvasWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CanvasWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CanvasWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CanvasWidget_t {
    QByteArrayData data[9];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanvasWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanvasWidget_t qt_meta_stringdata_CanvasWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CanvasWidget"
QT_MOC_LITERAL(1, 13, 15), // "onShapesChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "ShapeList"
QT_MOC_LITERAL(4, 40, 6), // "shapes"
QT_MOC_LITERAL(5, 47, 19), // "onBackgroundChanged"
QT_MOC_LITERAL(6, 67, 5), // "color"
QT_MOC_LITERAL(7, 73, 13), // "onZoomChanged"
QT_MOC_LITERAL(8, 87, 4) // "zoom"

    },
    "CanvasWidget\0onShapesChanged\0\0ShapeList\0"
    "shapes\0onBackgroundChanged\0color\0"
    "onZoomChanged\0zoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanvasWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       5,    1,   32,    2, 0x08 /* Private */,
       7,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QColor,    6,
    QMetaType::Void, QMetaType::QReal,    8,

       0        // eod
};

void CanvasWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CanvasWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onShapesChanged((*reinterpret_cast< const ShapeList(*)>(_a[1]))); break;
        case 1: _t->onBackgroundChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->onZoomChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CanvasWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CanvasWidget.data,
    qt_meta_data_CanvasWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CanvasWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanvasWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CanvasWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CanvasWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
