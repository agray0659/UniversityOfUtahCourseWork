/****************************************************************************
** Meta object code from reading C++ file 'preview_displayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SpriteEditor/preview_displayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preview_displayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreviewDisplayer_t {
    const uint offsetsAndSize[20];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PreviewDisplayer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PreviewDisplayer_t qt_meta_stringdata_PreviewDisplayer = {
    {
QT_MOC_LITERAL(0, 16), // "PreviewDisplayer"
QT_MOC_LITERAL(17, 12), // "setFrameData"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 5), // "Frame"
QT_MOC_LITERAL(37, 8), // "newFrame"
QT_MOC_LITERAL(46, 12), // "setCurrFrame"
QT_MOC_LITERAL(59, 6), // "Sprite"
QT_MOC_LITERAL(66, 6), // "sprite"
QT_MOC_LITERAL(73, 4), // "int&"
QT_MOC_LITERAL(78, 12) // "currFrameIdx"

    },
    "PreviewDisplayer\0setFrameData\0\0Frame\0"
    "newFrame\0setCurrFrame\0Sprite\0sprite\0"
    "int&\0currFrameIdx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreviewDisplayer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       5,    2,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,

       0        // eod
};

void PreviewDisplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreviewDisplayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setFrameData((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 1: _t->setCurrFrame((*reinterpret_cast< std::add_pointer_t<Sprite>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject PreviewDisplayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PreviewDisplayer.offsetsAndSize,
    qt_meta_data_PreviewDisplayer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PreviewDisplayer_t
, QtPrivate::TypeAndForceComplete<PreviewDisplayer, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Frame, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Sprite, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>


>,
    nullptr
} };


const QMetaObject *PreviewDisplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreviewDisplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreviewDisplayer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PreviewDisplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
