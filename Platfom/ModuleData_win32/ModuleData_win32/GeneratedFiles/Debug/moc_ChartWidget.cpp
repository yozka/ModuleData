/****************************************************************************
** Meta object code from reading C++ file 'ChartWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/ChartWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChartWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chart__AChartWidget_t {
    QByteArrayData data[15];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chart__AChartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chart__AChartWidget_t qt_meta_stringdata_Chart__AChartWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Chart::AChartWidget"
QT_MOC_LITERAL(1, 20, 17), // "slot_rangeChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 8), // "QCPRange"
QT_MOC_LITERAL(4, 48, 8), // "newRange"
QT_MOC_LITERAL(5, 57, 16), // "slot_timeChanged"
QT_MOC_LITERAL(6, 74, 5), // "value"
QT_MOC_LITERAL(7, 80, 16), // "slot_treeChanged"
QT_MOC_LITERAL(8, 97, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(9, 114, 7), // "current"
QT_MOC_LITERAL(10, 122, 8), // "previous"
QT_MOC_LITERAL(11, 131, 17), // "slot_graphClicked"
QT_MOC_LITERAL(12, 149, 21), // "QCPAbstractPlottable*"
QT_MOC_LITERAL(13, 171, 9), // "plottable"
QT_MOC_LITERAL(14, 181, 9) // "dataIndex"

    },
    "Chart::AChartWidget\0slot_rangeChanged\0"
    "\0QCPRange\0newRange\0slot_timeChanged\0"
    "value\0slot_treeChanged\0QTreeWidgetItem*\0"
    "current\0previous\0slot_graphClicked\0"
    "QCPAbstractPlottable*\0plottable\0"
    "dataIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chart__AChartWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       7,    2,   40,    2, 0x0a /* Public */,
      11,    2,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    9,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,

       0        // eod
};

void Chart::AChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AChartWidget *_t = static_cast<AChartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_rangeChanged((*reinterpret_cast< const QCPRange(*)>(_a[1]))); break;
        case 1: _t->slot_timeChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->slot_treeChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 3: _t->slot_graphClicked((*reinterpret_cast< QCPAbstractPlottable*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractPlottable* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Chart::AChartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Chart__AChartWidget.data,
      qt_meta_data_Chart__AChartWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Chart::AChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chart::AChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Chart__AChartWidget.stringdata0))
        return static_cast<void*>(const_cast< AChartWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Chart::AChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
