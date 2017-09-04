/****************************************************************************
** Meta object code from reading C++ file 'registerthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "registerthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegisterThread_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegisterThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegisterThread_t qt_meta_stringdata_RegisterThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RegisterThread"
QT_MOC_LITERAL(1, 15, 22), // "sendRegistrationOutput"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "run"
QT_MOC_LITERAL(4, 43, 11), // "onReadyRead"
QT_MOC_LITERAL(5, 55, 10) // "disconnect"

    },
    "RegisterThread\0sendRegistrationOutput\0"
    "\0run\0onReadyRead\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegisterThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   37,    2, 0x0a /* Public */,
       4,    0,   38,    2, 0x0a /* Public */,
       5,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RegisterThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegisterThread *_t = static_cast<RegisterThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendRegistrationOutput((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->disconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RegisterThread::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisterThread::sendRegistrationOutput)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RegisterThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RegisterThread.data,
      qt_meta_data_RegisterThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RegisterThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegisterThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterThread.stringdata0))
        return static_cast<void*>(const_cast< RegisterThread*>(this));
    return QObject::qt_metacast(_clname);
}

int RegisterThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RegisterThread::sendRegistrationOutput(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
