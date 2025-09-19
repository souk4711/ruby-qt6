#include "qline-rb.hpp"
#include <qline.h>

using namespace Rice;

Rice::Class rb_cQLine;
Rice::Class rb_cQLineF;

void Init_qline(Rice::Module rb_mQt6QtCore)
{
    rb_cQLine =
        // RubyQt6::QtCore::QLine
        define_class_under<QLine>(rb_mQt6QtCore, "QLine");

    rb_cQLineF =
        // RubyQt6::QtCore::QLineF
        define_class_under<QLineF>(rb_mQt6QtCore, "QLineF");
}
