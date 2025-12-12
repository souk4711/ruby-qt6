#include "qdial-rb.hpp"
#include <qdial.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDial;

void Init_qdial(Module rb_mQt6QtWidgets)
{
    rb_cQDial =
        // RubyQt6::QtWidgets::QDial
        define_class_under<QDial, QAbstractSlider>(rb_mQt6QtWidgets, "QDial")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDial::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDial, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("notch_size", &QDial::notchSize)
            .define_method("notch_target", &QDial::notchTarget)
            .define_method("notches_visible", &QDial::notchesVisible)
            .define_method("set_notch_target", &QDial::setNotchTarget, Arg("target"))
            .define_method("wrapping", &QDial::wrapping)
            // Public Slots
            .define_method("set_notches_visible", &QDial::setNotchesVisible, Arg("visible"))
            .define_method("set_wrapping", &QDial::setWrapping, Arg("on"));
}
