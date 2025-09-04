#include "qpushbutton-rb.hpp"
#include <qpushbutton.h>

#include <QMenu>

using namespace Rice;

Rice::Class rb_cQPushButton;

void Init_qpushbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQPushButton =
        // RubyQt6::QtWidgets::QPushButton
        define_class_under<QPushButton, QAbstractButton>(rb_mQt6QtWidgets, "QPushButton")
            .define_constructor(Constructor<QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent") = static_cast<QWidget *>(nullptr))
            // Public Functions
            .define_method("auto_default", &QPushButton::autoDefault)
            .define_method("default?", &QPushButton::isDefault)
            .define_method("flat?", &QPushButton::isFlat)
            .define_method("menu", &QPushButton::menu)
            .define_method("set_auto_default", &QPushButton::setAutoDefault, Arg(""))
            .define_method("set_default", &QPushButton::setDefault, Arg(""))
            .define_method("set_flat", &QPushButton::setFlat, Arg(""))
            .define_method("set_menu", &QPushButton::setMenu, Arg("menu"))
            // Public Slots
            .define_method("show_menu", &QPushButton::showMenu);
}
