#include "kseparator-rb.hpp"
#include <kseparator.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cKSeparator;

void Init_kseparator(Module rb_mQt6KWidgetsAddons)
{
    rb_cKSeparator =
        // RubyQt6::KWidgetsAddons::KSeparator
        define_qlass_under<KSeparator, QFrame>(rb_mQt6KWidgetsAddons, "KSeparator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &KSeparator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<KSeparator, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method("orientation", &KSeparator::orientation)
            .define_method("set_orientation", &KSeparator::setOrientation, Arg("orientation"));
}
