#include "qrect-rb.hpp"
#include <qrect.h>

using namespace Rice;

Rice::Class rb_cQRect;
Rice::Class rb_cQRectF;

void Init_qrect(Rice::Module rb_mQt6QtCore)
{
    rb_cQRect =
        // RubyQt6::QtCore::QRect
        define_class_under<QRect>(rb_mQt6QtCore, "QRect")
            .define_constructor(Constructor<QRect, int, int, int, int>(), Arg("x"), Arg("y"), Arg("width"), Arg("height"));

    rb_cQRectF =
        // RubyQt6::QtCore::QRectF
        define_class_under<QRectF>(rb_mQt6QtCore, "QRectF");
}
