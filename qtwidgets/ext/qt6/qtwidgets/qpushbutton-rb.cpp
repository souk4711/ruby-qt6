#include "qpushbutton-rb.hpp"
#include <QPushButton>

using namespace Rice;

Rice::Class rb_cQPushButton;

void Init_QPushButton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQPushButton = // Qt6::qtwidgets::qpushbutton
        define_class_under<QPushButton, QAbstractButton>(rb_mQt6QtWidgets, "QPushButton")
            .define_constructor(Constructor<QPushButton, QWidget *>(), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_constructor(Constructor<QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_constructor(Constructor<QPushButton, const QIcon &, const QString &, QWidget *>(), Arg("icon"), Arg("text"), Arg("parent") = static_cast<QWidget *>(nullptr));
}
