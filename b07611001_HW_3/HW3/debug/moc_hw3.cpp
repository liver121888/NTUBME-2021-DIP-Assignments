/****************************************************************************
** Meta object code from reading C++ file 'hw3.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../hw3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hw3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hw3_t {
    const uint offsetsAndSize[36];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Hw3_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Hw3_t qt_meta_stringdata_Hw3 = {
    {
QT_MOC_LITERAL(0, 3), // "Hw3"
QT_MOC_LITERAL(4, 18), // "on_btnOpen_clicked"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 30), // "on_hsdKernelSizem_valueChanged"
QT_MOC_LITERAL(55, 5), // "value"
QT_MOC_LITERAL(61, 30), // "on_hsdKernelSizen_valueChanged"
QT_MOC_LITERAL(92, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(114, 19), // "on_btnSobel_clicked"
QT_MOC_LITERAL(134, 36), // "on_btnOrderStatisticsExecute_..."
QT_MOC_LITERAL(171, 32), // "on_hsdKernelSizem_3_valueChanged"
QT_MOC_LITERAL(204, 32), // "on_hsdKernelSizen_3_valueChanged"
QT_MOC_LITERAL(237, 17), // "on_btnLoG_clicked"
QT_MOC_LITERAL(255, 32), // "on_hsdKernelSizem_2_valueChanged"
QT_MOC_LITERAL(288, 32), // "on_hsdKernelSizen_2_valueChanged"
QT_MOC_LITERAL(321, 32), // "on_cbbFilter_currentIndexChanged"
QT_MOC_LITERAL(354, 5), // "index"
QT_MOC_LITERAL(360, 36), // "on_ckbGaussainNormalize_state..."
QT_MOC_LITERAL(397, 4) // "arg1"

    },
    "Hw3\0on_btnOpen_clicked\0\0"
    "on_hsdKernelSizem_valueChanged\0value\0"
    "on_hsdKernelSizen_valueChanged\0"
    "on_btnExecute_clicked\0on_btnSobel_clicked\0"
    "on_btnOrderStatisticsExecute_clicked\0"
    "on_hsdKernelSizem_3_valueChanged\0"
    "on_hsdKernelSizen_3_valueChanged\0"
    "on_btnLoG_clicked\0on_hsdKernelSizem_2_valueChanged\0"
    "on_hsdKernelSizen_2_valueChanged\0"
    "on_cbbFilter_currentIndexChanged\0index\0"
    "on_ckbGaussainNormalize_stateChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hw3[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    0 /* Private */,
       3,    1,   93,    2, 0x08,    1 /* Private */,
       5,    1,   96,    2, 0x08,    3 /* Private */,
       6,    0,   99,    2, 0x08,    5 /* Private */,
       7,    0,  100,    2, 0x08,    6 /* Private */,
       8,    0,  101,    2, 0x08,    7 /* Private */,
       9,    1,  102,    2, 0x08,    8 /* Private */,
      10,    1,  105,    2, 0x08,   10 /* Private */,
      11,    0,  108,    2, 0x08,   12 /* Private */,
      12,    1,  109,    2, 0x08,   13 /* Private */,
      13,    1,  112,    2, 0x08,   15 /* Private */,
      14,    1,  115,    2, 0x08,   17 /* Private */,
      16,    1,  118,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void Hw3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Hw3 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnOpen_clicked(); break;
        case 1: _t->on_hsdKernelSizem_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_hsdKernelSizen_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btnExecute_clicked(); break;
        case 4: _t->on_btnSobel_clicked(); break;
        case 5: _t->on_btnOrderStatisticsExecute_clicked(); break;
        case 6: _t->on_hsdKernelSizem_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_hsdKernelSizen_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_btnLoG_clicked(); break;
        case 9: _t->on_hsdKernelSizem_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_hsdKernelSizen_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_cbbFilter_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_ckbGaussainNormalize_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Hw3::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Hw3.offsetsAndSize,
    qt_meta_data_Hw3,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Hw3_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Hw3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hw3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hw3.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Hw3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
