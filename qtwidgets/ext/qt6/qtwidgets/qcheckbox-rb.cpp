#include "qcheckbox-rb.hpp"
#include <qcheckbox.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCheckBox;

void Init_qcheckbox(Module rb_mQt6QtWidgets)
{
    rb_cQCheckBox =
        // RubyQt6::QtWidgets::QCheckBox
        define_qlass_under<QCheckBox, QAbstractButton>(rb_mQt6QtWidgets, "QCheckBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QCheckBox * { return qobject_cast<QCheckBox *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QCheckBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QCheckBox, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("check_state", &QCheckBox::checkState)
            .define_method("tristate?", &QCheckBox::isTristate)
            .define_method("set_check_state", &QCheckBox::setCheckState, Arg("state"))
            .define_method("set_tristate", &QCheckBox::setTristate, Arg("y") = static_cast<bool>(true));
            // Signals
            // .define_method("check_state_changed", &QCheckBox::checkStateChanged, Arg("state"));
}
