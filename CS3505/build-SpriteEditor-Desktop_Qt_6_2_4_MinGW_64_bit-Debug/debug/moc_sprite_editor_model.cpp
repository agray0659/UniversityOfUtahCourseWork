/****************************************************************************
** Meta object code from reading C++ file 'sprite_editor_model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SpriteEditor/sprite_editor_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sprite_editor_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sprite_Editor_Model_t {
    const uint offsetsAndSize[56];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Sprite_Editor_Model_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Sprite_Editor_Model_t qt_meta_stringdata_Sprite_Editor_Model = {
    {
QT_MOC_LITERAL(0, 19), // "Sprite_Editor_Model"
QT_MOC_LITERAL(20, 12), // "spriteLoaded"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 5), // "Frame"
QT_MOC_LITERAL(40, 11), // "activeFrame"
QT_MOC_LITERAL(52, 17), // "spritePreviewData"
QT_MOC_LITERAL(70, 6), // "Sprite"
QT_MOC_LITERAL(77, 6), // "sprite"
QT_MOC_LITERAL(84, 13), // "sendNextFrame"
QT_MOC_LITERAL(98, 9), // "nextFrame"
QT_MOC_LITERAL(108, 13), // "sendPrevFrame"
QT_MOC_LITERAL(122, 9), // "prevFrame"
QT_MOC_LITERAL(132, 12), // "sendNewFrame"
QT_MOC_LITERAL(145, 8), // "newFrame"
QT_MOC_LITERAL(154, 20), // "hasNextAndPrevFrames"
QT_MOC_LITERAL(175, 12), // "hasNextFrame"
QT_MOC_LITERAL(188, 12), // "hasPrevFrame"
QT_MOC_LITERAL(201, 18), // "loadSpriteFromFile"
QT_MOC_LITERAL(220, 8), // "filename"
QT_MOC_LITERAL(229, 9), // "newSprite"
QT_MOC_LITERAL(239, 5), // "width"
QT_MOC_LITERAL(245, 6), // "height"
QT_MOC_LITERAL(252, 15), // "generatePreview"
QT_MOC_LITERAL(268, 10), // "saveSprite"
QT_MOC_LITERAL(279, 17), // "updateSpritePixel"
QT_MOC_LITERAL(297, 3), // "row"
QT_MOC_LITERAL(301, 3), // "col"
QT_MOC_LITERAL(305, 5) // "color"

    },
    "Sprite_Editor_Model\0spriteLoaded\0\0"
    "Frame\0activeFrame\0spritePreviewData\0"
    "Sprite\0sprite\0sendNextFrame\0nextFrame\0"
    "sendPrevFrame\0prevFrame\0sendNewFrame\0"
    "newFrame\0hasNextAndPrevFrames\0"
    "hasNextFrame\0hasPrevFrame\0loadSpriteFromFile\0"
    "filename\0newSprite\0width\0height\0"
    "generatePreview\0saveSprite\0updateSpritePixel\0"
    "row\0col\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sprite_Editor_Model[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       5,    2,  101,    2, 0x06,    3 /* Public */,
       8,    1,  106,    2, 0x06,    6 /* Public */,
      10,    1,  109,    2, 0x06,    8 /* Public */,
      12,    1,  112,    2, 0x06,   10 /* Public */,
      14,    2,  115,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    1,  120,    2, 0x0a,   15 /* Public */,
      19,    2,  123,    2, 0x0a,   17 /* Public */,
      22,    0,  128,    2, 0x0a,   20 /* Public */,
      23,    1,  129,    2, 0x0a,   21 /* Public */,
      24,    3,  132,    2, 0x0a,   23 /* Public */,
       9,    0,  139,    2, 0x0a,   27 /* Public */,
      11,    0,  140,    2, 0x0a,   28 /* Public */,
      13,    0,  141,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void, 0x80000000 | 3,   13,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   15,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor,   25,   26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Sprite_Editor_Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Sprite_Editor_Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->spriteLoaded((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 1: _t->spritePreviewData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Sprite>>(_a[2]))); break;
        case 2: _t->sendNextFrame((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 3: _t->sendPrevFrame((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 4: _t->sendNewFrame((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 5: _t->hasNextAndPrevFrames((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->loadSpriteFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->newSprite((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->generatePreview(); break;
        case 9: _t->saveSprite((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->updateSpritePixel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 11: _t->nextFrame(); break;
        case 12: _t->prevFrame(); break;
        case 13: _t->newFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Sprite_Editor_Model::*)(Frame );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite_Editor_Model::spriteLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Sprite_Editor_Model::*)(int , Sprite );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite_Editor_Model::spritePreviewData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Sprite_Editor_Model::*)(Frame );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite_Editor_Model::sendNextFrame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Sprite_Editor_Model::*)(Frame );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite_Editor_Model::sendPrevFrame)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Sprite_Editor_Model::*)(Frame );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite_Editor_Model::sendNewFrame)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Sprite_Editor_Model::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite_Editor_Model::hasNextAndPrevFrames)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Sprite_Editor_Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Sprite_Editor_Model.offsetsAndSize,
    qt_meta_data_Sprite_Editor_Model,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Sprite_Editor_Model_t
, QtPrivate::TypeAndForceComplete<Sprite_Editor_Model, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Frame, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Sprite, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Frame, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Frame, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Frame, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Sprite_Editor_Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sprite_Editor_Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sprite_Editor_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Sprite_Editor_Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Sprite_Editor_Model::spriteLoaded(Frame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sprite_Editor_Model::spritePreviewData(int _t1, Sprite _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Sprite_Editor_Model::sendNextFrame(Frame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Sprite_Editor_Model::sendPrevFrame(Frame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Sprite_Editor_Model::sendNewFrame(Frame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Sprite_Editor_Model::hasNextAndPrevFrames(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
