#include "qframe-rb.hpp"
#include <qframe.h>

using namespace Rice;

Rice::Class rb_cQFrame;

void Init_qframe(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFrame =
        // RubyQt6::QtWidgets::QFrame
        define_class_under<QFrame, QWidget>(rb_mQt6QtWidgets, "QFrame");
}
