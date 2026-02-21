#include "qdbusabstractinterface-rb.hpp"
#include <qdbusabstractinterface.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDBusAbstractInterface;

void Init_qdbusabstractinterface(Module rb_mQt6QtDBus)
{
    rb_cQDBusAbstractInterface =
        // RubyQt6::QtDBus::QDBusAbstractInterface
        define_qlass_under<QDBusAbstractInterface, QObject>(rb_mQt6QtDBus, "QDBusAbstractInterface")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDBusAbstractInterface::staticMetaObject; })
            // Public Functions
            .define_method("async_call_with_argument_list", &QDBusAbstractInterface::asyncCallWithArgumentList, Arg("method"), Arg("args"))
            .define_method("call_with_argument_list", &QDBusAbstractInterface::callWithArgumentList, Arg("mode"), Arg("method"), Arg("args"))
            // .define_method<bool (QDBusAbstractInterface::*)(const QString &, const QList &, QObject *, const char *)>("call_with_callback", &QDBusAbstractInterface::callWithCallback, Arg("method"), Arg("args"), Arg("receiver"), Arg("member"))
            // .define_method<bool (QDBusAbstractInterface::*)(const QString &, const QList &, QObject *, const char *, const char *)>("call_with_callback", &QDBusAbstractInterface::callWithCallback, Arg("method"), Arg("args"), Arg("receiver"), Arg("member"), Arg("error_slot"))
            .define_method("connection", &QDBusAbstractInterface::connection)
            .define_method("interface", &QDBusAbstractInterface::interface)
            .define_method("interactive_authorization_allowed?", &QDBusAbstractInterface::isInteractiveAuthorizationAllowed)
            .define_method("valid?", &QDBusAbstractInterface::isValid)
            .define_method("last_error", &QDBusAbstractInterface::lastError)
            .define_method("path", &QDBusAbstractInterface::path)
            .define_method("service", &QDBusAbstractInterface::service)
            .define_method("set_interactive_authorization_allowed", &QDBusAbstractInterface::setInteractiveAuthorizationAllowed, Arg("enable"))
            .define_method("set_timeout", &QDBusAbstractInterface::setTimeout, Arg("timeout"))
            .define_method("timeout", &QDBusAbstractInterface::timeout);
}
