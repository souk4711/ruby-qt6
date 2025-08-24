#include "qlabel-rb.hpp"
#include <qlabel.h>

using namespace Rice;

Rice::Class rb_cQLabel;

void Init_qlabel(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLabel =
        // RubyQt6::QtWidgets::QLabel
        define_class_under<QLabel, QFrame>(rb_mQt6QtWidgets, "QLabel")
            .define_constructor(Constructor<QLabel, const QString &, QWidget *, Qt::WindowFlags>(), Arg("text"), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("f") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()));
}
