/****************************************************************************
** Meta object code from reading C++ file 'authenticationthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "authenticationthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authenticationthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AuthenticationThread_t {
    QByteArrayData data[14];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AuthenticationThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AuthenticationThread_t qt_meta_stringdata_AuthenticationThread = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AuthenticationThread"
QT_MOC_LITERAL(1, 21, 24), // "sendAuthenticationOutput"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 3), // "run"
QT_MOC_LITERAL(4, 51, 11), // "onReadyRead"
QT_MOC_LITERAL(5, 63, 11), // "setUserName"
QT_MOC_LITERAL(6, 75, 4), // "name"
QT_MOC_LITERAL(7, 80, 15), // "setUserPassword"
QT_MOC_LITERAL(8, 96, 8), // "password"
QT_MOC_LITERAL(9, 105, 7), // "setPort"
QT_MOC_LITERAL(10, 113, 4), // "port"
QT_MOC_LITERAL(11, 118, 7), // "setHost"
QT_MOC_LITERAL(12, 126, 4), // "host"
QT_MOC_LITERAL(13, 131, 10) // "disconnect"

    },
    "AuthenticationThread\0sendAuthenticationOutput\0"
    "\0run\0onReadyRead\0setUserName\0name\0"
    "setUserPassword\0password\0setPort\0port\0"
    "setHost\0host\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthenticationThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   57,    2, 0x0a /* Public */,
       4,    0,   58,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x0a /* Public */,
       7,    1,   62,    2, 0x0a /* Public */,
       9,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void AuthenticationThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AuthenticationThread *_t = static_cast<AuthenticationThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAuthenticationOutput((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->setUserName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setUserPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setHost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->disconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AuthenticationThread::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AuthenticationThread::sendAuthenticationOutput)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AuthenticationThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AuthenticationThread.data,
      qt_meta_data_AuthenticationThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AuthenticationThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthenticationThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AuthenticationThread.stringdata0))
        return static_cast<void*>(const_cast< AuthenticationThread*>(this));
    return QObject::qt_metacast(_clname);
}

int AuthenticationThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AuthenticationThread::sendAuthenticationOutput(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
