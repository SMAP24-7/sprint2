/****************************************************************************
** Meta object code from reading C++ file 'cliente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cliente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cliente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cliente_t {
    QByteArrayData data[16];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cliente_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cliente_t qt_meta_stringdata_Cliente = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Cliente"
QT_MOC_LITERAL(1, 8, 8), // "sendName"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "sendPassword"
QT_MOC_LITERAL(4, 31, 8), // "sendHost"
QT_MOC_LITERAL(5, 40, 8), // "sendPort"
QT_MOC_LITERAL(6, 49, 15), // "on_Open_clicked"
QT_MOC_LITERAL(7, 65, 19), // "on_Send_bnt_clicked"
QT_MOC_LITERAL(8, 85, 17), // "on_Open_2_clicked"
QT_MOC_LITERAL(9, 103, 21), // "on_Send_bnt_2_clicked"
QT_MOC_LITERAL(10, 125, 34), // "on_actionConexion_Segura_trig..."
QT_MOC_LITERAL(11, 160, 31), // "on_authenticationButton_clicked"
QT_MOC_LITERAL(12, 192, 25), // "on_RegisterButton_clicked"
QT_MOC_LITERAL(13, 218, 17), // "getAuthentication"
QT_MOC_LITERAL(14, 236, 4), // "code"
QT_MOC_LITERAL(15, 241, 21) // "getRegistrationOutput"

    },
    "Cliente\0sendName\0\0sendPassword\0sendHost\0"
    "sendPort\0on_Open_clicked\0on_Send_bnt_clicked\0"
    "on_Open_2_clicked\0on_Send_bnt_2_clicked\0"
    "on_actionConexion_Segura_triggered\0"
    "on_authenticationButton_clicked\0"
    "on_RegisterButton_clicked\0getAuthentication\0"
    "code\0getRegistrationOutput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cliente[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x0a /* Public */,
      15,    1,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void, QMetaType::LongLong,   14,

       0        // eod
};

void Cliente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cliente *_t = static_cast<Cliente *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendHost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_Open_clicked(); break;
        case 5: _t->on_Send_bnt_clicked(); break;
        case 6: _t->on_Open_2_clicked(); break;
        case 7: _t->on_Send_bnt_2_clicked(); break;
        case 8: _t->on_actionConexion_Segura_triggered(); break;
        case 9: _t->on_authenticationButton_clicked(); break;
        case 10: _t->on_RegisterButton_clicked(); break;
        case 11: _t->getAuthentication((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: _t->getRegistrationOutput((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cliente::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cliente::sendName)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Cliente::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cliente::sendPassword)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Cliente::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cliente::sendHost)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Cliente::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cliente::sendPort)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Cliente::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Cliente.data,
      qt_meta_data_Cliente,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cliente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cliente::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cliente.stringdata0))
        return static_cast<void*>(const_cast< Cliente*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Cliente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Cliente::sendName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cliente::sendPassword(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cliente::sendHost(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Cliente::sendPort(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
