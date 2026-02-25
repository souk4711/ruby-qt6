#include "qradiobutton-rb.hpp"
#include <qradiobutton.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQRadioButton;

void Init_qradiobutton(Module rb_mQt6QtWidgets)
{
    rb_cQRadioButton =
        // RubyQt6::QtWidgets::QRadioButton
        define_qlass_under<QRadioButton, QAbstractButton>(rb_mQt6QtWidgets, "QRadioButton")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QRadioButton * { return qobject_cast<QRadioButton *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QRadioButton::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QRadioButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
