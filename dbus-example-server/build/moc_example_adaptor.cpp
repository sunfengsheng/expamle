/****************************************************************************
** Meta object code from reading C++ file 'example_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "example_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'example_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dbus_demo_exampleAdaptor_t {
    QByteArrayData data[24];
    char stringdata0[2009];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dbus_demo_exampleAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dbus_demo_exampleAdaptor_t qt_meta_stringdata_Dbus_demo_exampleAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Dbus_demo_exampleAdaptor"
QT_MOC_LITERAL(1, 25, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 41, 23), // "local.dbus_demo_example"
QT_MOC_LITERAL(3, 65, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 85, 1667), // "  <interface name=\"local.dbu..."
QT_MOC_LITERAL(5, 1588, 11), // "return_bool"
QT_MOC_LITERAL(6, 1600, 0), // ""
QT_MOC_LITERAL(7, 1601, 14), // "return_integer"
QT_MOC_LITERAL(8, 1616, 30), // "return_integet_and_set_integer"
QT_MOC_LITERAL(9, 1647, 6), // "argc_1"
QT_MOC_LITERAL(10, 1654, 7), // "argc_22"
QT_MOC_LITERAL(11, 1662, 8), // "QString&"
QT_MOC_LITERAL(12, 1671, 6), // "argc_2"
QT_MOC_LITERAL(13, 1678, 4), // "out1"
QT_MOC_LITERAL(14, 1683, 32), // "return_integet_and_set_integet_2"
QT_MOC_LITERAL(15, 1716, 13), // "return_string"
QT_MOC_LITERAL(16, 1730, 28), // "return_string_and_set_string"
QT_MOC_LITERAL(17, 1759, 18), // "return_variantlist"
QT_MOC_LITERAL(18, 1778, 11), // "set_integer"
QT_MOC_LITERAL(19, 1790, 4), // "argc"
QT_MOC_LITERAL(20, 1795, 10), // "set_string"
QT_MOC_LITERAL(21, 1806, 15), // "set_variantlist"
QT_MOC_LITERAL(22, 1822, 3), // "cnt"
QT_MOC_LITERAL(23, 1826, 17) // "set_variantlist_2"

    },
    "Dbus_demo_exampleAdaptor\0D-Bus Interface\0"
    "local.dbus_demo_example\0D-Bus Introspection\0"
    "  <interface name=\"local.dbus_demo_example\">\n    <method name=\"set"
    "_integer\">\n      <arg direction=\"in\" type=\"i\" name=\"argc\"/>\n "
    "   </method>\n    <method name=\"set_string\">\n      <arg direction=\""
    "in\" type=\"s\" name=\"argc\"/>\n    </method>\n    <method name=\"set"
    "_variantlist\">\n      <arg direction=\"in\" type=\"i\" name=\"cnt\"/>"
    "\n      <arg direction=\"in\" type=\"av\" name=\"argc\"/>\n    </metho"
    "d>\n    <method name=\"set_variantlist_2\">\n      <arg direction=\"ou"
    "t\" type=\"i\"/>\n      <arg direction=\"in\" type=\"av\" name=\"argc\""
    "/>\n    </method>\n    <method name=\"return_integer\">\n      <arg di"
    "rection=\"out\" type=\"i\"/>\n    </method>\n    <method name=\"return"
    "_bool\">\n      <arg direction=\"out\" type=\"b\"/>\n    </method>\n  "
    "  <method name=\"return_string\">\n      <arg direction=\"out\" type=\""
    "s\"/>\n    </method>\n    <method name=\"return_variantlist\">\n      "
    "<arg direction=\"out\" type=\"av\"/>\n    </method>\n    <method name="
    "\"return_integet_and_set_integer\">\n      <arg direction=\"out\" type"
    "=\"i\"/>\n      <arg direction=\"in\" type=\"i\" name=\"argc_1\"/>\n  "
    "    <arg direction=\"in\" type=\"s\" name=\"argc_22\"/>\n      <arg di"
    "rection=\"out\" type=\"s\" name=\"argc_2\"/>\n      <arg direction=\"o"
    "ut\" type=\"s\" name=\"out1\"/>\n    </method>\n    <method name=\"ret"
    "urn_integet_and_set_integet_2\">\n      <arg direction=\"out\" type=\""
    "i\"/>\n      <arg direction=\"in\" type=\"i\" name=\"argc_1\"/>\n    <"
    "/method>\n    <method name=\"return_string_and_set_string\">\n      <a"
    "rg direction=\"out\" type=\"s\"/>\n      <arg direction=\"in\" type=\""
    "s\" name=\"argc_1\"/>\n    </method>\n  </interface>\n\0"
    "return_bool\0\0return_integer\0"
    "return_integet_and_set_integer\0argc_1\0"
    "argc_22\0QString&\0argc_2\0out1\0"
    "return_integet_and_set_integet_2\0"
    "return_string\0return_string_and_set_string\0"
    "return_variantlist\0set_integer\0argc\0"
    "set_string\0set_variantlist\0cnt\0"
    "set_variantlist_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dbus_demo_exampleAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
      11,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    0,   73,    6, 0x0a /* Public */,
       7,    0,   74,    6, 0x0a /* Public */,
       8,    4,   75,    6, 0x0a /* Public */,
      14,    1,   84,    6, 0x0a /* Public */,
      15,    0,   87,    6, 0x0a /* Public */,
      16,    1,   88,    6, 0x0a /* Public */,
      17,    0,   91,    6, 0x0a /* Public */,
      18,    1,   92,    6, 0x0a /* Public */,
      20,    1,   95,    6, 0x0a /* Public */,
      21,    2,   98,    6, 0x0a /* Public */,
      23,    1,  103,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 11, 0x80000000 | 11,    9,   10,   12,   13,
    QMetaType::Int, QMetaType::Int,    9,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,    9,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantList,   22,   19,
    QMetaType::Int, QMetaType::QVariantList,   19,

       0        // eod
};

void Dbus_demo_exampleAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dbus_demo_exampleAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->return_bool();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->return_integer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->return_integet_and_set_integer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->return_integet_and_set_integet_2((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->return_string();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->return_string_and_set_string((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantList _r = _t->return_variantlist();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->set_integer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_string((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->set_variantlist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QVariantList(*)>(_a[2]))); break;
        case 10: { int _r = _t->set_variantlist_2((*reinterpret_cast< const QVariantList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dbus_demo_exampleAdaptor::staticMetaObject = { {
    &QDBusAbstractAdaptor::staticMetaObject,
    qt_meta_stringdata_Dbus_demo_exampleAdaptor.data,
    qt_meta_data_Dbus_demo_exampleAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dbus_demo_exampleAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dbus_demo_exampleAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dbus_demo_exampleAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int Dbus_demo_exampleAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
