#include "qmargins-rb.hpp"
#include <qmargins.h>

using namespace Rice;

Rice::Class rb_cQMargins;
Rice::Class rb_cQMarginsF;

void Init_qmargins(Rice::Module rb_mQt6QtCore)
{
    rb_cQMargins =
        // RubyQt6::QtCore::QMargins
        define_class_under<QMargins>(rb_mQt6QtCore, "QMargins");

    rb_cQMarginsF =
        // RubyQt6::QtCore::QMarginsF
        define_class_under<QMarginsF>(rb_mQt6QtCore, "QMarginsF");
}
