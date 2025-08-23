#include "qcolor-rb.hpp"
#include <qcolor.h>

using namespace Rice;

Rice::Class rb_cQColor;

void Init_qcolor(Rice::Module rb_mQt6QtGui)
{
    rb_cQColor =
        // RubyQt6::QtGui::QColor
        define_class_under<QColor>(rb_mQt6QtGui, "QColor");
}
