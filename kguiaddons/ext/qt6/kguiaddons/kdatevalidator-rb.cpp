#include "kdatevalidator-rb.hpp"
#include <kdatevalidator.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cKDateValidator;

void Init_kdatevalidator(Module rb_mQt6KGuiAddons)
{
    rb_cKDateValidator =
        // RubyQt6::KGuiAddons::KDateValidator
        define_class_under<KDateValidator, QValidator>(rb_mQt6KGuiAddons, "KDateValidator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &KDateValidator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<KDateValidator, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("date", &KDateValidator::date, Arg("text"), Arg("date"))
            .define_method("fixup", &KDateValidator::fixup, Arg("input"))
            .define_method("validate", &KDateValidator::validate, Arg("text"), Arg("e"));
}
