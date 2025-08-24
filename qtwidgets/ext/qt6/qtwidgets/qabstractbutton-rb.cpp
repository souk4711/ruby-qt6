#include "qabstractbutton-rb.hpp"
#include <qabstractbutton.h>

using namespace Rice;

Rice::Class rb_cQAbstractButton;

void Init_qabstractbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractButton =
        // RubyQt6::QtWidgets::QAbstractButton
        define_class_under<QAbstractButton, QWidget>(rb_mQt6QtWidgets, "QAbstractButton");
}
