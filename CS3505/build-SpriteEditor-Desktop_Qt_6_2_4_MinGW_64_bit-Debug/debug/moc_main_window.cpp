/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SpriteEditor/main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Main_Window_t {
    const uint offsetsAndSize[48];
    char stringdata0[380];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Main_Window_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Main_Window_t qt_meta_stringdata_Main_Window = {
    {
QT_MOC_LITERAL(0, 11), // "Main_Window"
QT_MOC_LITERAL(12, 9), // "newSprite"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 5), // "width"
QT_MOC_LITERAL(29, 6), // "height"
QT_MOC_LITERAL(36, 16), // "newColorSelected"
QT_MOC_LITERAL(53, 13), // "selectedColor"
QT_MOC_LITERAL(67, 18), // "loadSpriteFromFile"
QT_MOC_LITERAL(86, 8), // "filename"
QT_MOC_LITERAL(95, 10), // "saveSprite"
QT_MOC_LITERAL(106, 15), // "generatePreview"
QT_MOC_LITERAL(122, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(145, 28), // "on_colorPickerButton_clicked"
QT_MOC_LITERAL(174, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(198, 22), // "on_eraseButton_clicked"
QT_MOC_LITERAL(221, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(245, 24), // "on_previewSprite_clicked"
QT_MOC_LITERAL(270, 20), // "displayPreviewWindow"
QT_MOC_LITERAL(291, 14), // "activeFrameIdx"
QT_MOC_LITERAL(306, 6), // "Sprite"
QT_MOC_LITERAL(313, 15), // "spriteToPreview"
QT_MOC_LITERAL(329, 24), // "toggleNextAndPrevButtons"
QT_MOC_LITERAL(354, 12), // "hasNextFrame"
QT_MOC_LITERAL(367, 12) // "hasPrevFrame"

    },
    "Main_Window\0newSprite\0\0width\0height\0"
    "newColorSelected\0selectedColor\0"
    "loadSpriteFromFile\0filename\0saveSprite\0"
    "generatePreview\0on_actionNew_triggered\0"
    "on_colorPickerButton_clicked\0"
    "on_actionLoad_triggered\0on_eraseButton_clicked\0"
    "on_actionSave_triggered\0"
    "on_previewSprite_clicked\0displayPreviewWindow\0"
    "activeFrameIdx\0Sprite\0spriteToPreview\0"
    "toggleNextAndPrevButtons\0hasNextFrame\0"
    "hasPrevFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_Window[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   92,    2, 0x06,    1 /* Public */,
       5,    1,   97,    2, 0x06,    4 /* Public */,
       7,    1,  100,    2, 0x06,    6 /* Public */,
       9,    1,  103,    2, 0x06,    8 /* Public */,
      10,    0,  106,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  107,    2, 0x08,   11 /* Private */,
      12,    0,  108,    2, 0x08,   12 /* Private */,
      13,    0,  109,    2, 0x08,   13 /* Private */,
      14,    0,  110,    2, 0x08,   14 /* Private */,
      15,    0,  111,    2, 0x08,   15 /* Private */,
      16,    0,  112,    2, 0x08,   16 /* Private */,
      17,    2,  113,    2, 0x08,   17 /* Private */,
      21,    2,  118,    2, 0x08,   20 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QColor,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 19,   18,   20,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   22,   23,

       0        // eod
};

void Main_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main_Window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newSprite((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->newColorSelected((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 2: _t->loadSpriteFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->saveSprite((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->generatePreview(); break;
        case 5: _t->on_actionNew_triggered(); break;
        case 6: _t->on_colorPickerButton_clicked(); break;
        case 7: _t->on_actionLoad_triggered(); break;
        case 8: _t->on_eraseButton_clicked(); break;
        case 9: _t->on_actionSave_triggered(); break;
        case 10: _t->on_previewSprite_clicked(); break;
        case 11: _t->displayPreviewWindow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Sprite>>(_a[2]))); break;
        case 12: _t->toggleNextAndPrevButtons((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Main_Window::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window::newSprite)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Main_Window::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window::newColorSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Main_Window::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window::loadSpriteFromFile)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Main_Window::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window::saveSprite)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Main_Window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window::generatePreview)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Main_Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Main_Window.offsetsAndSize,
    qt_meta_data_Main_Window,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Main_Window_t
, QtPrivate::TypeAndForceComplete<Main_Window, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Sprite, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Main_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main_Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Main_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Main_Window::newSprite(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Main_Window::newColorSelected(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Main_Window::loadSpriteFromFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Main_Window::saveSprite(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Main_Window::generatePreview()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
