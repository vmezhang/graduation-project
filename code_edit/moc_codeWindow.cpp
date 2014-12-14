/****************************************************************************
** Meta object code from reading C++ file 'codeWindow.h'
**
** Created: Sun Dec 14 11:29:12 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "codeWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CodeWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      46,   38,   11,   11, 0x08,
      93,   38,   11,   11, 0x08,
     129,   38,   11,   11, 0x08,
     165,   38,   11,   11, 0x08,
     205,  199,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     294,   11,   11,   11, 0x08,
     320,   11,   11,   11, 0x08,
     345,   11,   11,   11, 0x08,
     371,   11,   11,   11, 0x08,
     397,   11,   11,   11, 0x08,
     425,   11,   11,   11, 0x08,
     451,   11,   11,   11, 0x08,
     481,   11,   11,   11, 0x08,
     508,   11,   11,   11, 0x08,
     534,   11,   11,   11, 0x08,
     559,  199,   11,   11, 0x08,
     595,   11,   11,   11, 0x08,
     624,   11,   11,   11, 0x08,
     651,   11,   11,   11, 0x08,
     677,   11,   11,   11, 0x08,
     693,   11,   11,   11, 0x08,
     705,   11,   11,   11, 0x08,
     722,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeWindow[] = {
    "CodeWindow\0\0on_actionFont_triggered()\0"
    "checked\0on_actionHightlightCurrentLine_triggered(bool)\0"
    "on_actionLineNumber_triggered(bool)\0"
    "on_actionHightlight_triggered(bool)\0"
    "on_actionWordWrap_triggered(bool)\0"
    "index\0on_tabWidget_currentChanged(int)\0"
    "on_actionSaveAll_triggered()\0"
    "on_actionPaste_triggered()\0"
    "on_actionCopy_triggered()\0"
    "on_actionCut_triggered()\0"
    "on_actionRedo_triggered()\0"
    "on_actionUndo_triggered()\0"
    "on_actionSaveAs_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionCloseAll_triggered()\0"
    "on_actionClose_triggered()\0"
    "on_actionOpen_triggered()\0"
    "on_actionNew_triggered()\0"
    "on_tabWidget_tabCloseRequested(int)\0"
    "on_actionAboutQt_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_actionExit_triggered()\0tabTextChange()\0"
    "setupMenu()\0openRecentFile()\0setupCodec()\0"
};

void CodeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CodeWindow *_t = static_cast<CodeWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionFont_triggered(); break;
        case 1: _t->on_actionHightlightCurrentLine_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_actionLineNumber_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actionHightlight_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_actionWordWrap_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_actionSaveAll_triggered(); break;
        case 7: _t->on_actionPaste_triggered(); break;
        case 8: _t->on_actionCopy_triggered(); break;
        case 9: _t->on_actionCut_triggered(); break;
        case 10: _t->on_actionRedo_triggered(); break;
        case 11: _t->on_actionUndo_triggered(); break;
        case 12: _t->on_actionSaveAs_triggered(); break;
        case 13: _t->on_actionSave_triggered(); break;
        case 14: _t->on_actionCloseAll_triggered(); break;
        case 15: _t->on_actionClose_triggered(); break;
        case 16: _t->on_actionOpen_triggered(); break;
        case 17: _t->on_actionNew_triggered(); break;
        case 18: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_actionAboutQt_triggered(); break;
        case 20: _t->on_actionAbout_triggered(); break;
        case 21: _t->on_actionExit_triggered(); break;
        case 22: _t->tabTextChange(); break;
        case 23: _t->setupMenu(); break;
        case 24: _t->openRecentFile(); break;
        case 25: _t->setupCodec(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CodeWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CodeWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CodeWindow,
      qt_meta_data_CodeWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeWindow))
        return static_cast<void*>(const_cast< CodeWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CodeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
