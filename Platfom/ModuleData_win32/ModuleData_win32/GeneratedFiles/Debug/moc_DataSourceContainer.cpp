/****************************************************************************
** Meta object code from reading C++ file 'DataSourceContainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/DataSourceContainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataSourceContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataSource__ADataSourceContainer_t {
    QByteArrayData data[6];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataSource__ADataSourceContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataSource__ADataSourceContainer_t qt_meta_stringdata_DataSource__ADataSourceContainer = {
    {
QT_MOC_LITERAL(0, 0, 32), // "DataSource::ADataSourceContainer"
QT_MOC_LITERAL(1, 33, 13), // "signal_change"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 11), // "slot_change"
QT_MOC_LITERAL(4, 60, 18), // "const ADataSource*"
QT_MOC_LITERAL(5, 79, 4) // "data"

    },
    "DataSource::ADataSourceContainer\0"
    "signal_change\0\0slot_change\0"
    "const ADataSource*\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataSource__ADataSourceContainer[] = {

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
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void DataSource::ADataSourceContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ADataSourceContainer *_t = static_cast<ADataSourceContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_change(); break;
        case 1: _t->slot_change((*reinterpret_cast< const ADataSource*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ADataSourceContainer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ADataSourceContainer::signal_change)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject DataSource::ADataSourceContainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataSource__ADataSourceContainer.data,
      qt_meta_data_DataSource__ADataSourceContainer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataSource::ADataSourceContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataSource::ADataSourceContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataSource__ADataSourceContainer.stringdata0))
        return static_cast<void*>(const_cast< ADataSourceContainer*>(this));
    return QObject::qt_metacast(_clname);
}

int DataSource::ADataSourceContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DataSource::ADataSourceContainer::signal_change()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
