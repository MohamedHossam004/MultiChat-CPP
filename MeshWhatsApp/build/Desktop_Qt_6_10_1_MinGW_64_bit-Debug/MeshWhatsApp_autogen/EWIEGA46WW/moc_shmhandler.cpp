/****************************************************************************
** Meta object code from reading C++ file 'shmhandler.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../shmhandler.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shmhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10ShmHandlerE_t {};
} // unnamed namespace

template <> constexpr inline auto ShmHandler::qt_create_metaobjectdata<qt_meta_tag_ZN10ShmHandlerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ShmHandler",
        "logMessage",
        "",
        "text",
        "messageReceived",
        "sender",
        "setAlgorithm",
        "index",
        "processSharedMemory"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'logMessage'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'messageReceived'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 3 },
        }}),
        // Slot 'setAlgorithm'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'processSharedMemory'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ShmHandler, qt_meta_tag_ZN10ShmHandlerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ShmHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ShmHandlerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ShmHandlerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10ShmHandlerE_t>.metaTypes,
    nullptr
} };

void ShmHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ShmHandler *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->messageReceived((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->setAlgorithm((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->processSharedMemory(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ShmHandler::*)(const QString & )>(_a, &ShmHandler::logMessage, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ShmHandler::*)(const QString & , const QString & )>(_a, &ShmHandler::messageReceived, 1))
            return;
    }
}

const QMetaObject *ShmHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShmHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ShmHandlerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ShmHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ShmHandler::logMessage(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ShmHandler::messageReceived(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
QT_WARNING_POP
