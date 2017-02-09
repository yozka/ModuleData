/****************************************************************************
** Meta object code from reading C++ file 'ModuleData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/ModuleData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModuleData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AModuleData_t {
    QByteArrayData data[15];
    char stringdata0[322];
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
QT_MOC_LITERAL(6, 116, 28), // "on_actionChartPlay_triggered"
QT_MOC_LITERAL(7, 145, 29), // "on_actionChartPause_triggered"
QT_MOC_LITERAL(8, 175, 28), // "on_actionChartStop_triggered"
QT_MOC_LITERAL(9, 204, 34), // "on_actionRandomGenerator_trig..."
QT_MOC_LITERAL(10, 239, 22), // "slot_refreshDataSource"
QT_MOC_LITERAL(11, 262, 21), // "slot_deleteDataSource"
QT_MOC_LITERAL(12, 284, 8), // "QAction*"
QT_MOC_LITERAL(13, 293, 6), // "action"
QT_MOC_LITERAL(14, 300, 21) // "slot_selectDataSource"

    },
    "AModuleData\0on_actionMarking_triggered\0"
    "\0on_actionChartNew_triggered\0"
    "on_actionChartClose_triggered\0"
    "slot_refreshChart\0on_actionChartPlay_triggered\0"
    "on_actionChartPause_triggered\0"
    "on_actionChartStop_triggered\0"
    "on_actionRandomGenerator_triggered\0"
    "slot_refreshDataSource\0slot_deleteDataSource\0"
    "QAction*\0action\0slot_selectDataSource"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AModuleData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,

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
        case 4: _t->on_actionChartPlay_triggered(); break;
        case 5: _t->on_actionChartPause_triggered(); break;
        case 6: _t->on_actionChartStop_triggered(); break;
        case 7: _t->on_actionRandomGenerator_triggered(); break;
        case 8: _t->slot_refreshDataSource(); break;
        case 9: _t->slot_deleteDataSource((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 10: _t->slot_selectDataSource((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
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
QT_END_MOC_NAMESPACE
