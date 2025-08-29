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
            .define_method("_auto_default?", &QPushButton::autoDefault)
            .define_method("_default?", &QPushButton::isDefault)
            .define_method("_flat?", &QPushButton::isFlat)
            .define_method("_set_auto_default", &QPushButton::setAutoDefault, Arg("enabled"))
            .define_method("_set_default", &QPushButton::setDefault, Arg("enabled"))
            .define_method("_set_flat", &QPushButton::setFlat, Arg("enabled"))
            .define_method("_menu", &QPushButton::menu)
            .define_method("_set_menu", &QPushButton::setMenu, Arg("menu"))
            .define_method("_show_menu", &QPushButton::showMenu);
}
