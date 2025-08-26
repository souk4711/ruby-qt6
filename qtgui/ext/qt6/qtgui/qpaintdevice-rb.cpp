#include "qpaintdevice-rb.hpp"
#include <qpaintdevice.h>

using namespace Rice;

Rice::Class rb_cQPaintDevice;

void Init_qpaintdevice(Rice::Module rb_mQt6QtGui)
{
    rb_cQPaintDevice =
        // RubyQt6::QtGui::QPaintDevice
        define_class_under<QPaintDevice>(rb_mQt6QtGui, "QPaintDevice");
}
