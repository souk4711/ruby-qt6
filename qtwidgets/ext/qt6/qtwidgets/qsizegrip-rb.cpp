#include "qsizegrip-rb.hpp"
#include <qsizegrip.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSizeGrip;

void Init_qsizegrip(Module rb_mQt6QtWidgets)
{
    rb_cQSizeGrip =
        // RubyQt6::QtWidgets::QSizeGrip
        define_qlass_under<QSizeGrip, QWidget>(rb_mQt6QtWidgets, "QSizeGrip")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QSizeGrip * { return qobject_cast<QSizeGrip *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSizeGrip::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSizeGrip, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("set_visible", &QSizeGrip::setVisible, Arg("visible"));
}
