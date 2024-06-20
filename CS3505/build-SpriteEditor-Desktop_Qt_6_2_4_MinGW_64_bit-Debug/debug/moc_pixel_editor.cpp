/****************************************************************************
** Meta object code from reading C++ file 'pixel_editor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SpriteEditor/pixel_editor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pixel_editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PixelEditor_t {
    const uint offsetsAndSize[22];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PixelEditor_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PixelEditor_t qt_meta_stringdata_PixelEditor = {
    {
QT_MOC_LITERAL(0, 11), // "PixelEditor"
QT_MOC_LITERAL(12, 13), // "pixelModified"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 3), // "row"
QT_MOC_LITERAL(31, 3), // "col"
QT_MOC_LITERAL(35, 5), // "color"
QT_MOC_LITERAL(41, 12), // "setFrameData"
QT_MOC_LITERAL(54, 5), // "Frame"
QT_MOC_LITERAL(60, 8), // "newFrame"
QT_MOC_LITERAL(69, 12), // "colorChanged"
QT_MOC_LITERAL(82, 8) // "newColor"

    },
    "PixelEditor\0pixelModified\0\0row\0col\0"
    "color\0setFrameData\0Frame\0newFrame\0"
    "colorChanged\0newColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PixelEditor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   39,    2, 0x0a,    5 /* Public */,
       9,    1,   42,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QColor,   10,

       0        // eod
};

void PixelEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PixelEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pixelModified((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 1: _t->setFrameData((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 2: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PixelEditor::*)(int , int , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixelEditor::pixelModified)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PixelEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PixelEditor.offsetsAndSize,
    qt_meta_data_PixelEditor,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PixelEditor_t
, QtPrivate::TypeAndForceComplete<PixelEditor, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Frame, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>


>,
    nullptr
} };


const QMetaObject *PixelEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PixelEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PixelEditor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PixelEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PixelEditor::pixelModified(int _t1, int _t2, QColor _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
