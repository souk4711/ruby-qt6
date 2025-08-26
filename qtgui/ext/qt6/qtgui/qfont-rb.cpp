#include "qfont-rb.hpp"
#include <qfont.h>

using namespace Rice;

Rice::Class rb_cQFont;

void Init_qfont(Rice::Module rb_mQt6QtGui)
{
    rb_cQFont =
        // RubyQt6::QtGui::QFont
        define_class_under<QFont>(rb_mQt6QtGui, "QFont");
}
