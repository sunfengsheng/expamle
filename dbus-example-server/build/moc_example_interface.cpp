/****************************************************************************
** Meta object code from reading C++ file 'example_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "example_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'example_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalDbus_demo_exampleInterface_t {
    QByteArrayData data[27];
    char stringdata0[469];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalDbus_demo_exampleInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalDbus_demo_exampleInterface_t qt_meta_stringdata_LocalDbus_demo_exampleInterface = {
    {
QT_MOC_LITERAL(0, 0, 31), // "LocalDbus_demo_exampleInterface"
QT_MOC_LITERAL(1, 32, 11), // "return_bool"
QT_MOC_LITERAL(2, 44, 23), // "QDBusPendingReply<bool>"
QT_MOC_LITERAL(3, 68, 0), // ""
QT_MOC_LITERAL(4, 69, 14), // "return_integer"
QT_MOC_LITERAL(5, 84, 22), // "QDBusPendingReply<int>"
QT_MOC_LITERAL(6, 107, 30), // "return_integet_and_set_integer"
QT_MOC_LITERAL(7, 138, 38), // "QDBusPendingReply<int,QString..."
QT_MOC_LITERAL(8, 177, 6), // "argc_1"
QT_MOC_LITERAL(9, 184, 7), // "argc_22"
QT_MOC_LITERAL(10, 192, 15), // "QDBusReply<int>"
QT_MOC_LITERAL(11, 208, 8), // "QString&"
QT_MOC_LITERAL(12, 217, 6), // "argc_2"
QT_MOC_LITERAL(13, 224, 4), // "out1"
QT_MOC_LITERAL(14, 229, 32), // "return_integet_and_set_integet_2"
QT_MOC_LITERAL(15, 262, 13), // "return_string"
QT_MOC_LITERAL(16, 276, 26), // "QDBusPendingReply<QString>"
QT_MOC_LITERAL(17, 303, 28), // "return_string_and_set_string"
QT_MOC_LITERAL(18, 332, 18), // "return_variantlist"
QT_MOC_LITERAL(19, 351, 31), // "QDBusPendingReply<QVariantList>"
QT_MOC_LITERAL(20, 383, 11), // "set_integer"
QT_MOC_LITERAL(21, 395, 19), // "QDBusPendingReply<>"
QT_MOC_LITERAL(22, 415, 4), // "argc"
QT_MOC_LITERAL(23, 420, 10), // "set_string"
QT_MOC_LITERAL(24, 431, 15), // "set_variantlist"
QT_MOC_LITERAL(25, 447, 3), // "cnt"
QT_MOC_LITERAL(26, 451, 17) // "set_variantlist_2"

    },
    "LocalDbus_demo_exampleInterface\0"
    "return_bool\0QDBusPendingReply<bool>\0"
    "\0return_integer\0QDBusPendingReply<int>\0"
    "return_integet_and_set_integer\0"
    "QDBusPendingReply<int,QString,QString>\0"
    "argc_1\0argc_22\0QDBusReply<int>\0QString&\0"
    "argc_2\0out1\0return_integet_and_set_integet_2\0"
    "return_string\0QDBusPendingReply<QString>\0"
    "return_string_and_set_string\0"
    "return_variantlist\0QDBusPendingReply<QVariantList>\0"
    "set_integer\0QDBusPendingReply<>\0argc\0"
    "set_string\0set_variantlist\0cnt\0"
    "set_variantlist_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalDbus_demo_exampleInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    3, 0x0a /* Public */,
       4,    0,   75,    3, 0x0a /* Public */,
       6,    2,   76,    3, 0x0a /* Public */,
       6,    4,   81,    3, 0x0a /* Public */,
      14,    1,   90,    3, 0x0a /* Public */,
      15,    0,   93,    3, 0x0a /* Public */,
      17,    1,   94,    3, 0x0a /* Public */,
      18,    0,   97,    3, 0x0a /* Public */,
      20,    1,   98,    3, 0x0a /* Public */,
      23,    1,  101,    3, 0x0a /* Public */,
      24,    2,  104,    3, 0x0a /* Public */,
      26,    1,  109,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 5,
    0x80000000 | 7, QMetaType::Int, QMetaType::QString,    8,    9,
    0x80000000 | 10, QMetaType::Int, QMetaType::QString, 0x80000000 | 11, 0x80000000 | 11,    8,    9,   12,   13,
    0x80000000 | 5, QMetaType::Int,    8,
    0x80000000 | 16,
    0x80000000 | 16, QMetaType::QString,    8,
    0x80000000 | 19,
    0x80000000 | 21, QMetaType::Int,   22,
    0x80000000 | 21, QMetaType::QString,   22,
    0x80000000 | 21, QMetaType::Int, QMetaType::QVariantList,   25,   22,
    0x80000000 | 5, QMetaType::QVariantList,   22,

       0        // eod
};

void LocalDbus_demo_exampleInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocalDbus_demo_exampleInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QDBusPendingReply<bool> _r = _t->return_bool();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusPendingReply<int> _r = _t->return_integer();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<int,QString,QString> _r = _t->return_integet_and_set_integer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int,QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusReply<int> _r = _t->return_integet_and_set_integer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QDBusReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDBusPendingReply<int> _r = _t->return_integet_and_set_integet_2((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QDBusPendingReply<QString> _r = _t->return_string();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QString>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QDBusPendingReply<QString> _r = _t->return_string_and_set_string((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QString>*>(_a[0]) = std::move(_r); }  break;
        case 7: { QDBusPendingReply<QVariantList> _r = _t->return_variantlist();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantList>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QDBusPendingReply<> _r = _t->set_integer((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 9: { QDBusPendingReply<> _r = _t->set_string((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QDBusPendingReply<> _r = _t->set_variantlist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QVariantList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 11: { QDBusPendingReply<int> _r = _t->set_variantlist_2((*reinterpret_cast< const QVariantList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalDbus_demo_exampleInterface::staticMetaObject = { {
    &QDBusAbstractInterface::staticMetaObject,
    qt_meta_stringdata_LocalDbus_demo_exampleInterface.data,
    qt_meta_data_LocalDbus_demo_exampleInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LocalDbus_demo_exampleInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalDbus_demo_exampleInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalDbus_demo_exampleInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int LocalDbus_demo_exampleInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
