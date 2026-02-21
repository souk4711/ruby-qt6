#include "qprocess-rb.hpp"
#include <qprocess.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQProcessEnvironment;

void Init_qprocessenvironment(Module rb_mQt6QtCore)
{
    rb_cQProcessEnvironment =
        // RubyQt6::QtCore::QProcessEnvironment
        define_qlass_under<QProcessEnvironment>(rb_mQt6QtCore, "QProcessEnvironment")
            // Public Functions
            .define_method("clear", &QProcessEnvironment::clear)
            .define_method("_contains", &QProcessEnvironment::contains, Arg("name"))
            .define_method("inherits_from_parent", &QProcessEnvironment::inheritsFromParent)
            .define_method<void (QProcessEnvironment::*)(const QString &, const QString &)>("_insert", &QProcessEnvironment::insert, Arg("name"), Arg("value"))
            .define_method("empty?", &QProcessEnvironment::isEmpty)
            .define_method("keys", &QProcessEnvironment::keys)
            .define_method("_remove", &QProcessEnvironment::remove, Arg("name"))
            .define_method("to_string_list", &QProcessEnvironment::toStringList)
            .define_method("_value", &QProcessEnvironment::value, Arg("name"), Arg("default_value") = static_cast<const QString &>(QString()))
            // Static Public Members
            .define_singleton_function("system_environment", &QProcessEnvironment::systemEnvironment);

    Data_Type<QProcessEnvironment::Initialization> rb_cQProcessEnvironmentInitialization =
        // RubyQt6::QtCore::QProcessEnvironment::Initialization
        define_qenum_under<QProcessEnvironment::Initialization>(rb_cQProcessEnvironment, "Initialization");
        define_qenum_value_under(rb_cQProcessEnvironmentInitialization, "InheritFromParent", QProcessEnvironment::Initialization::InheritFromParent);
}
