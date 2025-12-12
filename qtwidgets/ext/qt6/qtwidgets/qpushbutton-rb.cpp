#include "qpushbutton-rb.hpp"
#include <qpushbutton.h>

#include <QMenu>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPushButton;

void Init_qpushbutton(Module rb_mQt6QtWidgets)
{
    rb_cQPushButton =
        // RubyQt6::QtWidgets::QPushButton
        define_class_under<QPushButton, QAbstractButton>(rb_mQt6QtWidgets, "QPushButton")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QPushButton::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("auto_default", &QPushButton::autoDefault)
            .define_method("default?", &QPushButton::isDefault)
            .define_method("flat?", &QPushButton::isFlat)
            .define_method("menu", &QPushButton::menu)
            .define_method("set_auto_default", &QPushButton::setAutoDefault, Arg("auto_default"))
            .define_method("set_default", &QPushButton::setDefault, Arg("default"))
            .define_method("set_flat", &QPushButton::setFlat, Arg("flat"))
            .define_method("set_menu", &QPushButton::setMenu, Arg("menu"))
            // Public Slots
            .define_method("show_menu", &QPushButton::showMenu);
}
