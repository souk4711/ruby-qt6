#include "qdbusvariant-rb.hpp"
#include <qdbusextratypes.h>

using namespace Rice;

Rice::Class rb_cQDBusVariant;

void Init_qdbusvariant(Rice::Module rb_mQt6QtDBus)
{

    rb_cQDBusVariant =
        // RubyQt6::QtDBus::QDBusVariant
        define_class_under<QDBusVariant>(rb_mQt6QtDBus, "QDBusVariant")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<QDBusVariant>(); })
            .define_singleton_function("_qvariant_from_value", [](const QDBusVariant &value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> QDBusVariant { return qvariant.value<QDBusVariant>(); })
            // Constructor
            .define_constructor(Constructor<QDBusVariant, const QVariant &>(), Arg("variant"))
            // Public Functions
            .define_method("set_variant", &QDBusVariant::setVariant, Arg("variant"))
            .define_method("variant", &QDBusVariant::variant);
}
