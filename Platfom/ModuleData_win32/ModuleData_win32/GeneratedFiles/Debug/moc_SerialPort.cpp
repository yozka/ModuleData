/****************************************************************************
** Meta object code from reading C++ file 'SerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/SerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Utils__ASerialPort_t {
    QByteArrayData data[10];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Utils__ASerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Utils__ASerialPort_t qt_meta_stringdata_Utils__ASerialPort = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Utils::ASerialPort"
QT_MOC_LITERAL(1, 19, 15), // "signal_readLine"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "data"
QT_MOC_LITERAL(4, 41, 12), // "signal_error"
QT_MOC_LITERAL(5, 54, 5), // "error"
QT_MOC_LITERAL(6, 60, 8), // "slot_run"
QT_MOC_LITERAL(7, 69, 10), // "slot_error"
QT_MOC_LITERAL(8, 80, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 109, 15) // "serialPortError"

    },
    "Utils::ASerialPort\0signal_readLine\0\0"
    "data\0signal_error\0error\0slot_run\0"
    "slot_error\0QSerialPort::SerialPortError\0"
    "serialPortError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Utils__ASerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void Utils::ASerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ASerialPort *_t = static_cast<ASerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_readLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signal_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slot_run(); break;
        case 3: _t->slot_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ASerialPort::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ASerialPort::signal_readLine)) {
                *result = 0;
            }
        }
        {
            typedef void (ASerialPort::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ASerialPort::signal_error)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Utils::ASerialPort::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Utils__ASerialPort.data,
      qt_meta_data_Utils__ASerialPort,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Utils::ASerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Utils::ASerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Utils__ASerialPort.stringdata0))
        return static_cast<void*>(const_cast< ASerialPort*>(this));
    if (!strcmp(_clname, "QEnableSharedFromThis<ASerialPort>"))
        return static_cast< QEnableSharedFromThis<ASerialPort>*>(const_cast< ASerialPort*>(this));
    return QObject::qt_metacast(_clname);
}

int Utils::ASerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Utils::ASerialPort::signal_readLine(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Utils::ASerialPort::signal_error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
