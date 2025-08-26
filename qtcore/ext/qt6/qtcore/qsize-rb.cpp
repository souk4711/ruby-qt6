#include "qsize-rb.hpp"
#include <qsize.h>

using namespace Rice;

Rice::Class rb_cQSize;
Rice::Class rb_cQSizeF;

void Init_qsize(Rice::Module rb_mQt6QtCore)
{
    rb_cQSize =
        // RubyQt6::QtCore::QSize
        define_class_under<QSize>(rb_mQt6QtCore, "QSize");

    rb_cQSizeF =
        // RubyQt6::QtCore::QSize
        define_class_under<QSizeF>(rb_mQt6QtCore, "QSizeF");
}
