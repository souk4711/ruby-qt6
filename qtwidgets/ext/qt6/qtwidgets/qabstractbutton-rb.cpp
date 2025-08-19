// clang-format off

#include "qabstractbutton-rb.hpp"
#include <QAbstractButton>

using namespace Rice;

Rice::Class rb_cQAbstractButton;

void Init_QAbstractButton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractButton = // Qt6::QtWidgets::QAbstractButton
        define_class_under<QAbstractButton, QWidget>(rb_mQt6QtWidgets, "QAbstractButton")
            .define_method("text", &QAbstractButton::text)
            .define_method("set_text", &QAbstractButton::setText, Arg("text"));
}
