#include "qdbusabstractinterface-rb.hpp"
#include <qdbusabstractinterface.h>

using namespace Rice;

Rice::Class rb_cQDBusAbstractInterface;

void Init_qdbusabstractinterface(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusAbstractInterface =
        // RubyQt6::QtDBus::QDBusAbstractInterface
        define_class_under<QDBusAbstractInterface, QObject>(rb_mQt6QtDBus, "QDBusAbstractInterface")
            // RubyQt6-Defined Functions
            .define_method("call", [](QDBusAbstractInterface *self, QDBus::CallMode mode, const char *method) -> QDBusMessage { return self->call(mode, method); })
            .define_method("call", [](QDBusAbstractInterface *self, const char *method) -> QDBusMessage { return self->call(method); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDBusAbstractInterface::staticMetaObject; })
            // Public Functions
            // .define_method("async_call", &QDBusAbstractInterface::asyncCall, Arg("method"))
            .define_method("async_call_with_argument_list", &QDBusAbstractInterface::asyncCallWithArgumentList, Arg("method"), Arg("args"))
            .define_method<QDBusMessage (QDBusAbstractInterface::*)(QDBus::CallMode, const QString &)>("call", &QDBusAbstractInterface::call, Arg("mode"), Arg("method"))
            .define_method<QDBusMessage (QDBusAbstractInterface::*)(const QString &)>("call", &QDBusAbstractInterface::call, Arg("method"))
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
