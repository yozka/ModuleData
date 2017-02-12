/****************************************************************************
** Meta object code from reading C++ file 'DSRandomGeneratorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/DSRandomGeneratorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DSRandomGeneratorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataSource__ARandomGeneratorDialog_t {
    QByteArrayData data[4];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataSource__ARandomGeneratorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataSource__ARandomGeneratorDialog_t qt_meta_stringdata_DataSource__ARandomGeneratorDialog = {
    {
QT_MOC_LITERAL(0, 0, 34), // "DataSource::ARandomGeneratorD..."
QT_MOC_LITERAL(1, 35, 17), // "slot_editInterval"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 4) // "text"

    },
    "DataSource::ARandomGeneratorDialog\0"
    "slot_editInterval\0\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataSource__ARandomGeneratorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void DataSource::ARandomGeneratorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ARandomGeneratorDialog *_t = static_cast<ARandomGeneratorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_editInterval((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DataSource::ARandomGeneratorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DataSource__ARandomGeneratorDialog.data,
      qt_meta_data_DataSource__ARandomGeneratorDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataSource::ARandomGeneratorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataSource::ARandomGeneratorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataSource__ARandomGeneratorDialog.stringdata0))
        return static_cast<void*>(const_cast< ARandomGeneratorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DataSource::ARandomGeneratorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
