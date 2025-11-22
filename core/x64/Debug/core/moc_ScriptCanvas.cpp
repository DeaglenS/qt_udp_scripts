/****************************************************************************
** Meta object code from reading C++ file 'ScriptCanvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ScriptCanvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptCanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScriptCanvas_t {
    QByteArrayData data[33];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptCanvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptCanvas_t qt_meta_stringdata_ScriptCanvas = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScriptCanvas"
QT_MOC_LITERAL(1, 13, 7), // "message"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "text"
QT_MOC_LITERAL(4, 27, 5), // "clear"
QT_MOC_LITERAL(5, 33, 4), // "line"
QT_MOC_LITERAL(6, 38, 2), // "x1"
QT_MOC_LITERAL(7, 41, 2), // "y1"
QT_MOC_LITERAL(8, 44, 2), // "x2"
QT_MOC_LITERAL(9, 47, 2), // "y2"
QT_MOC_LITERAL(10, 50, 5), // "color"
QT_MOC_LITERAL(11, 56, 5), // "width"
QT_MOC_LITERAL(12, 62, 8), // "colorStr"
QT_MOC_LITERAL(13, 71, 4), // "rect"
QT_MOC_LITERAL(14, 76, 1), // "x"
QT_MOC_LITERAL(15, 78, 1), // "y"
QT_MOC_LITERAL(16, 80, 6), // "height"
QT_MOC_LITERAL(17, 87, 9), // "fillColor"
QT_MOC_LITERAL(18, 97, 11), // "strokeColor"
QT_MOC_LITERAL(19, 109, 8), // "penWidth"
QT_MOC_LITERAL(20, 118, 12), // "fillColorStr"
QT_MOC_LITERAL(21, 131, 14), // "strokeColorStr"
QT_MOC_LITERAL(22, 146, 6), // "circle"
QT_MOC_LITERAL(23, 153, 6), // "radius"
QT_MOC_LITERAL(24, 160, 12), // "filledCircle"
QT_MOC_LITERAL(25, 173, 8), // "triangle"
QT_MOC_LITERAL(26, 182, 2), // "x3"
QT_MOC_LITERAL(27, 185, 2), // "y3"
QT_MOC_LITERAL(28, 188, 13), // "setBackground"
QT_MOC_LITERAL(29, 202, 7), // "setZoom"
QT_MOC_LITERAL(30, 210, 4), // "zoom"
QT_MOC_LITERAL(31, 215, 5), // "print"
QT_MOC_LITERAL(32, 221, 3) // "msg"

    },
    "ScriptCanvas\0message\0\0text\0clear\0line\0"
    "x1\0y1\0x2\0y2\0color\0width\0colorStr\0rect\0"
    "x\0y\0height\0fillColor\0strokeColor\0"
    "penWidth\0fillColorStr\0strokeColorStr\0"
    "circle\0radius\0filledCircle\0triangle\0"
    "x3\0y3\0setBackground\0setZoom\0zoom\0print\0"
    "msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptCanvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,  137,    2, 0x02 /* Public */,
       5,    6,  138,    2, 0x02 /* Public */,
       5,    5,  151,    2, 0x22 /* Public | MethodCloned */,
       5,    6,  162,    2, 0x02 /* Public */,
       5,    5,  175,    2, 0x22 /* Public | MethodCloned */,
      13,    7,  186,    2, 0x02 /* Public */,
      13,    6,  201,    2, 0x22 /* Public | MethodCloned */,
      13,    7,  214,    2, 0x02 /* Public */,
      13,    6,  229,    2, 0x22 /* Public | MethodCloned */,
      22,    5,  242,    2, 0x02 /* Public */,
      22,    4,  253,    2, 0x22 /* Public | MethodCloned */,
      22,    5,  262,    2, 0x02 /* Public */,
      22,    4,  273,    2, 0x22 /* Public | MethodCloned */,
      24,    4,  282,    2, 0x02 /* Public */,
      24,    4,  291,    2, 0x02 /* Public */,
      25,    9,  300,    2, 0x02 /* Public */,
      25,    8,  319,    2, 0x22 /* Public | MethodCloned */,
      25,    9,  336,    2, 0x02 /* Public */,
      25,    8,  355,    2, 0x22 /* Public | MethodCloned */,
      28,    1,  372,    2, 0x02 /* Public */,
      28,    1,  375,    2, 0x02 /* Public */,
      29,    1,  378,    2, 0x02 /* Public */,
      31,    1,  381,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor, QMetaType::QReal,    6,    7,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QReal,    6,    7,    8,    9,   12,   11,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString,    6,    7,    8,    9,   12,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor, QMetaType::QColor, QMetaType::QReal,   14,   15,   11,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor, QMetaType::QColor,   14,   15,   11,   16,   17,   18,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QString, QMetaType::QReal,   14,   15,   11,   16,   20,   21,   19,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QString,   14,   15,   11,   16,   20,   21,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor, QMetaType::QReal,   14,   15,   23,   18,   19,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor,   14,   15,   23,   18,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QReal,   14,   15,   23,   21,   19,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString,   14,   15,   23,   21,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor,   14,   15,   23,   17,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString,   14,   15,   23,   20,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor, QMetaType::QColor, QMetaType::QReal,    6,    7,    8,    9,   26,   27,   17,   18,   19,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QColor, QMetaType::QColor,    6,    7,    8,    9,   26,   27,   17,   18,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QString, QMetaType::QReal,    6,    7,    8,    9,   26,   27,   20,   21,   19,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,   26,   27,   20,   21,
    QMetaType::Void, QMetaType::QColor,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QReal,   30,
    QMetaType::Void, QMetaType::QString,   32,

       0        // eod
};

void ScriptCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptCanvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->clear(); break;
        case 2: _t->line((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QColor(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6]))); break;
        case 3: _t->line((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QColor(*)>(_a[5]))); break;
        case 4: _t->line((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6]))); break;
        case 5: _t->line((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 6: _t->rect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QColor(*)>(_a[5])),(*reinterpret_cast< const QColor(*)>(_a[6])),(*reinterpret_cast< qreal(*)>(_a[7]))); break;
        case 7: _t->rect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QColor(*)>(_a[5])),(*reinterpret_cast< const QColor(*)>(_a[6]))); break;
        case 8: _t->rect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< qreal(*)>(_a[7]))); break;
        case 9: _t->rect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 10: _t->circle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 11: _t->circle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4]))); break;
        case 12: _t->circle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 13: _t->circle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 14: _t->filledCircle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4]))); break;
        case 15: _t->filledCircle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 16: _t->triangle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< const QColor(*)>(_a[7])),(*reinterpret_cast< const QColor(*)>(_a[8])),(*reinterpret_cast< qreal(*)>(_a[9]))); break;
        case 17: _t->triangle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< const QColor(*)>(_a[7])),(*reinterpret_cast< const QColor(*)>(_a[8]))); break;
        case 18: _t->triangle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< qreal(*)>(_a[9]))); break;
        case 19: _t->triangle((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 20: _t->setBackground((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 21: _t->setBackground((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->setZoom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 23: _t->print((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScriptCanvas::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptCanvas::message)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScriptCanvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScriptCanvas.data,
    qt_meta_data_ScriptCanvas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScriptCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptCanvas.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScriptCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void ScriptCanvas::message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
