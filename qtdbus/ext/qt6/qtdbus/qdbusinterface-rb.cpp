#include "qdbusinterface-rb.hpp"
#include <qdbusinterface.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDBusInterface;

void Init_qdbusinterface(Module rb_mQt6QtDBus)
{
    rb_cQDBusInterface =
        // RubyQt6::QtDBus::QDBusInterface
        define_class_under<QDBusInterface, QDBusAbstractInterface>(rb_mQt6QtDBus, "QDBusInterface")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDBusInterface::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDBusInterface, const QString &, const QString &, const QString &, const QDBusConnection &, QObject *>(), Arg("service"), Arg("path"), Arg("interface"), Arg("connection"), Arg("parent"));
}
