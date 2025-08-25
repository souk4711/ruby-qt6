#include "qobject-rb.hpp"
#include <qobject.h>

#include <QMetaObject>

using namespace Rice;

Rice::Class rb_cQObject;

void Init_qobject(Rice::Module rb_mQt6QtCore)
{
    rb_cQObject =
        // RubyQt6::QtCore::QObject
        define_class_under<QObject>(rb_mQt6QtCore, "QObject")
            .define_method("_dump_object_info", &QObject::dumpObjectInfo)
            .define_method("_dump_object_tree", &QObject::dumpObjectTree);
            .define_singleton_function<QMetaObject::Connection (*)(const QObject *, const char *, const QObject *, const char *, Qt::ConnectionType)>("_connect", &QObject::connect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("slot"), Arg("") = static_cast<Qt::ConnectionType>(Qt::AutoConnection))
            .define_singleton_function<bool (*)(const QMetaObject::Connection &)>("_disconnect", &QObject::disconnect, Arg("connection"))
}
