/****************************************************************************
** Meta object code from reading C++ file 'codeEdit.h'
**
** Created: Sun Dec 14 10:48:48 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "codeEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CodePad[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,    9,    8,    8, 0x08,
      54,    8,    8,    8, 0x08,
      81,   77,    8,    8, 0x08,
     113,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CodePad[] = {
    "CodePad\0\0newBlockCount\0"
    "updateLineNumberAreaWidth(int)\0"
    "highlightCurrentLine()\0,dy\0"
    "updateLineNumberArea(QRect,int)\0"
    "updateTextEdit()\0"
};

void CodePad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CodePad *_t = static_cast<CodePad *>(_o);
        switch (_id) {
        case 0: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->highlightCurrentLine(); break;
        case 2: _t->updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->updateTextEdit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CodePad::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CodePad::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_CodePad,
      qt_meta_data_CodePad, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodePad::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodePad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodePad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodePad))
        return static_cast<void*>(const_cast< CodePad*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int CodePad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
