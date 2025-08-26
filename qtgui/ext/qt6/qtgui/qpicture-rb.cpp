#include "qpicture-rb.hpp"
#include <qpicture.h>

using namespace Rice;

Rice::Class rb_cQPicture;

void Init_qpicture(Rice::Module rb_mQt6QtGui)
{
    rb_cQPicture =
        // RubyQt6::QtGui::QPicture
        define_class_under<QPicture, QPaintDevice>(rb_mQt6QtGui, "QPicture");
}
