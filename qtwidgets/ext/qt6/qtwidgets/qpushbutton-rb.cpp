#include "qpushbutton-rb.hpp"
#include <qpushbutton.h>

using namespace Rice;

Rice::Class rb_cQPushButton;

void Init_qpushbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQPushButton =
        // RubyQt6::QtWidgets::QPushButton
        define_class_under<QPushButton, QAbstractButton>(rb_mQt6QtWidgets, "QPushButton")
            .define_constructor(Constructor<QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent") = static_cast<QWidget *>(nullptr));
}
