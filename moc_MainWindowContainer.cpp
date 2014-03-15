/****************************************************************************
** Meta object code from reading C++ file 'MainWindowContainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindowContainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindowContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindowContainer_t {
    QByteArrayData data[18];
    char stringdata[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindowContainer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindowContainer_t qt_meta_stringdata_MainWindowContainer = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 14),
QT_MOC_LITERAL(4, 51, 11),
QT_MOC_LITERAL(5, 63, 11),
QT_MOC_LITERAL(6, 75, 1),
QT_MOC_LITERAL(7, 77, 13),
QT_MOC_LITERAL(8, 91, 12),
QT_MOC_LITERAL(9, 104, 14),
QT_MOC_LITERAL(10, 119, 5),
QT_MOC_LITERAL(11, 125, 11),
QT_MOC_LITERAL(12, 137, 3),
QT_MOC_LITERAL(13, 141, 8),
QT_MOC_LITERAL(14, 150, 15),
QT_MOC_LITERAL(15, 166, 3),
QT_MOC_LITERAL(16, 170, 16),
QT_MOC_LITERAL(17, 187, 7)
    },
    "MainWindowContainer\0adjustLocation\0\0"
    "changeLocation\0adjustTitle\0setProgress\0"
    "p\0finishLoading\0finishedSlot\0"
    "QNetworkReply*\0reply\0linkClicked\0url\0"
    "CloseApp\0sslErrorHandler\0qnr\0"
    "QList<QSslError>\0errlist\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowContainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a,
       3,    0,   60,    2, 0x0a,
       4,    0,   61,    2, 0x0a,
       5,    1,   62,    2, 0x0a,
       7,    1,   65,    2, 0x0a,
       8,    1,   68,    2, 0x0a,
      11,    1,   71,    2, 0x0a,
      13,    0,   74,    2, 0x0a,
      14,    2,   75,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QUrl,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 16,   15,   17,

       0        // eod
};

void MainWindowContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowContainer *_t = static_cast<MainWindowContainer *>(_o);
        switch (_id) {
        case 0: _t->adjustLocation(); break;
        case 1: _t->changeLocation(); break;
        case 2: _t->adjustTitle(); break;
        case 3: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->finishLoading((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->finishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->linkClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 7: _t->CloseApp(); break;
        case 8: _t->sslErrorHandler((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindowContainer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowContainer.data,
      qt_meta_data_MainWindowContainer,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindowContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowContainer.stringdata))
        return static_cast<void*>(const_cast< MainWindowContainer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
