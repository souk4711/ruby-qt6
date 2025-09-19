#include "qchar-rb.hpp"
#include <qchar.h>

using namespace Rice;

Rice::Class rb_cQChar;

void Init_qchar(Rice::Module rb_mQt6QtCore)
{
    rb_cQChar =
        // RubyQt6::QtCore::QChar
        define_class_under<QChar>(rb_mQt6QtCore, "QChar");
}
