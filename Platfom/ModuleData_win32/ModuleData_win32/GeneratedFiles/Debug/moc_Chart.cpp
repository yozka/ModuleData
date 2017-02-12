/****************************************************************************
** Meta object code from reading C++ file 'Chart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Chart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Chart__AChart_t {
    QByteArrayData data[5];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chart__AChart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chart__AChart_t qt_meta_stringdata_Chart__AChart = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Chart::AChart"
QT_MOC_LITERAL(1, 14, 13), // "signal_change"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 20), // "slot_destroyedWidget"
QT_MOC_LITERAL(4, 50, 3) // "obj"

    },
    "Chart::AChart\0signal_change\0\0"
    "slot_destroyedWidget\0obj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chart__AChart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    4,

       0        // eod
};

void Chart::AChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AChart *_t = static_cast<AChart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_change(); break;
        case 1: _t->slot_destroyedWidget((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AChart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AChart::signal_change)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Chart::AChart::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Chart__AChart.data,
      qt_meta_data_Chart__AChart,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Chart::AChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chart::AChart::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Chart__AChart.stringdata0))
        return static_cast<void*>(const_cast< AChart*>(this));
    if (!strcmp(_clname, "DataProxy::IInterface_receiv"))
        return static_cast< DataProxy::IInterface_receiv*>(const_cast< AChart*>(this));
    return QObject::qt_metacast(_clname);
}

int Chart::AChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Chart::AChart::signal_change()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
