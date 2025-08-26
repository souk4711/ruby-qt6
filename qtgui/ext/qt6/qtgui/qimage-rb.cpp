#include "qimage-rb.hpp"
#include <qimage.h>

using namespace Rice;

Rice::Class rb_cQImage;

void Init_qimage(Rice::Module rb_mQt6QtGui)
{
    rb_cQImage =
        // RubyQt6::QtGui::QImage
        define_class_under<QImage, QPaintDevice>(rb_mQt6QtGui, "QImage");
}
