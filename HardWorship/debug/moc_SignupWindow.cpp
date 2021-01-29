/****************************************************************************
** Meta object code from reading C++ file 'SignupWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SignupWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SignupWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SignupWindow_t {
    QByteArrayData data[9];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignupWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignupWindow_t qt_meta_stringdata_SignupWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SignupWindow"
QT_MOC_LITERAL(1, 13, 30), // "on_UsernameLineEdit_textEdited"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 8), // "username"
QT_MOC_LITERAL(4, 54, 37), // "on_ConfirmPasswordLineEdit_te..."
QT_MOC_LITERAL(5, 92, 8), // "password"
QT_MOC_LITERAL(6, 101, 27), // "on_EmailLineEdit_textEdited"
QT_MOC_LITERAL(7, 129, 5), // "email"
QT_MOC_LITERAL(8, 135, 23) // "on_SignupButton_clicked"

    },
    "SignupWindow\0on_UsernameLineEdit_textEdited\0"
    "\0username\0on_ConfirmPasswordLineEdit_textEdited\0"
    "password\0on_EmailLineEdit_textEdited\0"
    "email\0on_SignupButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignupWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       8,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void SignupWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SignupWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_UsernameLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_ConfirmPasswordLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_EmailLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_SignupButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SignupWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SignupWindow.data,
    qt_meta_data_SignupWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SignupWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignupWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SignupWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SignupWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
