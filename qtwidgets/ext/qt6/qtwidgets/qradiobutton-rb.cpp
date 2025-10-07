#include "qradiobutton-rb.hpp"
#include <qradiobutton.h>

using namespace Rice;

Rice::Class rb_cQRadioButton;

void Init_qradiobutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQRadioButton =
        // RubyQt6::QtWidgets::QRadioButton
        define_class_under<QRadioButton, QAbstractButton>(rb_mQt6QtWidgets, "QRadioButton")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QRadioButton::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QRadioButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
