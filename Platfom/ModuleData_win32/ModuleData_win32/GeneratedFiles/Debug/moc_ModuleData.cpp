/****************************************************************************
** Meta object code from reading C++ file 'ModuleData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/ModuleData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModuleData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AModuleData_t {
    QByteArrayData data[19];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AModuleData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AModuleData_t qt_meta_stringdata_AModuleData = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AModuleData"
QT_MOC_LITERAL(1, 12, 26), // "on_actionMarking_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 27), // "on_actionChartNew_triggered"
QT_MOC_LITERAL(4, 68, 29), // "on_actionChartClose_triggered"
QT_MOC_LITERAL(5, 98, 17), // "slot_refreshChart"
QT_MOC_LITERAL(6, 116, 22), // "slot_tabCurrentChanged"
QT_MOC_LITERAL(7, 139, 5), // "index"
QT_MOC_LITERAL(8, 145, 28), // "on_actionChartPlay_triggered"
QT_MOC_LITERAL(9, 174, 29), // "on_actionChartPause_triggered"
QT_MOC_LITERAL(10, 204, 28), // "on_actionChartStop_triggered"
QT_MOC_LITERAL(11, 233, 28), // "on_actionChartData_triggered"
QT_MOC_LITERAL(12, 262, 34), // "on_actionRandomGenerator_trig..."
QT_MOC_LITERAL(13, 297, 32), // "on_actionManualControl_triggered"
QT_MOC_LITERAL(14, 330, 26), // "on_actionComPort_triggered"
QT_MOC_LITERAL(15, 357, 22), // "slot_refreshDataSource"
QT_MOC_LITERAL(16, 380, 19), // "slot_menuDataSource"
QT_MOC_LITERAL(17, 400, 8), // "QAction*"
QT_MOC_LITERAL(18, 409, 6) // "action"

    },
    "AModuleData\0on_actionMarking_triggered\0"
    "\0on_actionChartNew_triggered\0"
    "on_actionChartClose_triggered\0"
    "slot_refreshChart\0slot_tabCurrentChanged\0"
    "index\0on_actionChartPlay_triggered\0"
    "on_actionChartPause_triggered\0"
    "on_actionChartStop_triggered\0"
    "on_actionChartData_triggered\0"
    "on_actionRandomGenerator_triggered\0"
    "on_actionManualControl_triggered\0"
    "on_actionComPort_triggered\0"
    "slot_refreshDataSource\0slot_menuDataSource\0"
    "QAction*\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AModuleData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void AModuleData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AModuleData *_t = static_cast<AModuleData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionMarking_triggered(); break;
        case 1: _t->on_actionChartNew_triggered(); break;
        case 2: _t->on_actionChartClose_triggered(); break;
        case 3: _t->slot_refreshChart(); break;
        case 4: _t->slot_tabCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_actionChartPlay_triggered(); break;
        case 6: _t->on_actionChartPause_triggered(); break;
        case 7: _t->on_actionChartStop_triggered(); break;
        case 8: _t->on_actionChartData_triggered(); break;
        case 9: _t->on_actionRandomGenerator_triggered(); break;
        case 10: _t->on_actionManualControl_triggered(); break;
        case 11: _t->on_actionComPort_triggered(); break;
        case 12: _t->slot_refreshDataSource(); break;
        case 13: _t->slot_menuDataSource((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject AModuleData::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AModuleData.data,
      qt_meta_data_AModuleData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AModuleData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AModuleData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AModuleData.stringdata0))
        return static_cast<void*>(const_cast< AModuleData*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AModuleData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
