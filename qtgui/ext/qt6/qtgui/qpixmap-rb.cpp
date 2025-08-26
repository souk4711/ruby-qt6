#include "qpixmap-rb.hpp"
#include <qpixmap.h>

using namespace Rice;

Rice::Class rb_cQPixmap;

void Init_qpixmap(Rice::Module rb_mQt6QtGui)
{
    rb_cQPixmap =
        // RubyQt6::QtGui::QPixmap
        define_class_under<QPixmap, QPaintDevice>(rb_mQt6QtGui, "QPixmap");
}
