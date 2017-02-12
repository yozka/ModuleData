/****************************************************************************
** Meta object code from reading C++ file 'DSComPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/DSComPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DSComPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataSource__AComPort_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataSource__AComPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataSource__AComPort_t qt_meta_stringdata_DataSource__AComPort = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DataSource::AComPort"
QT_MOC_LITERAL(1, 21, 13), // "slot_readData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "text"
QT_MOC_LITERAL(4, 41, 18), // "slot_readDataNativ"
QT_MOC_LITERAL(5, 60, 15), // "slot_errorNativ"
QT_MOC_LITERAL(6, 76, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(7, 105, 15) // "serialPortError"

    },
    "DataSource::AComPort\0slot_readData\0\0"
    "text\0slot_readDataNativ\0slot_errorNativ\0"
    "QSerialPort::SerialPortError\0"
    "serialPortError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataSource__AComPort[] = {

 // content:
       7,       // revision
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
       4,    0,   32,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void DataSource::AComPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AComPort *_t = static_cast<AComPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_readData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_readDataNativ(); break;
        case 2: _t->slot_errorNativ((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DataSource::AComPort::staticMetaObject = {
    { &ADataSource::staticMetaObject, qt_meta_stringdata_DataSource__AComPort.data,
      qt_meta_data_DataSource__AComPort,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataSource::AComPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataSource::AComPort::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataSource__AComPort.stringdata0))
        return static_cast<void*>(const_cast< AComPort*>(this));
    return ADataSource::qt_metacast(_clname);
}

int DataSource::AComPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ADataSource::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
