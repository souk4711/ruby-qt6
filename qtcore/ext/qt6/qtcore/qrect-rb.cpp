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
            // Constructor
            .define_constructor(Constructor<QRect, int, int, int, int>(), Arg("x"), Arg("y"), Arg("width"), Arg("height"))
            // Public Functions
            .define_method("bottom", &QRect::bottom)
            .define_method("bottom_left", &QRect::bottomLeft)
            .define_method("bottom_right", &QRect::bottomRight)
            .define_method<bool (QRect::*)(const QPoint &, bool) const noexcept>("contains", &QRect::contains, Arg("p"), Arg("proper") = false)
            .define_method<bool (QRect::*)(const QRect &, bool) const noexcept>("contains", &QRect::contains, Arg("r"), Arg("proper") = false)
            .define_method<bool (QRect::*)(int, int) const noexcept>("contains", &QRect::contains, Arg("x"), Arg("y"))
            .define_method("intersected", &QRect::intersected, Arg("other"))
            .define_method("intersects", &QRect::intersects, Arg("r"))
            .define_method("left", &QRect::left)
            .define_method("normalized", &QRect::normalized)
            .define_method("right", &QRect::right)
            .define_method("set_x", &QRect::setX, Arg("pos"))
            .define_method("set_y", &QRect::setY, Arg("pos"))
            .define_method("top", &QRect::top)
            .define_method("top_left", &QRect::topLeft)
            .define_method("top_right", &QRect::topRight)
            .define_method("united", &QRect::united, Arg("other"))
            .define_method("|", &QRect::operator|, Arg("r"))
            .define_method("&", &QRect::operator&, Arg("r"))
            .define_method("|=", &QRect::operator|=, Arg("r"))
            .define_method("&=", &QRect::operator&=, Arg("r"));

    rb_cQRectF =
        // RubyQt6::QtCore::QRectF
        define_class_under<QRectF>(rb_mQt6QtCore, "QRectF")
            // Constructor
            .define_constructor(Constructor<QRectF, qreal, qreal, qreal, qreal>(), Arg("x"), Arg("y"), Arg("width"), Arg("height"))
            // Public Functions
            .define_method("bottom", &QRectF::bottom)
            .define_method("bottom_left", &QRectF::bottomLeft)
            .define_method("bottom_right", &QRectF::bottomRight)
            .define_method<bool (QRectF::*)(const QPointF &) const noexcept>("contains", &QRectF::contains, Arg("p"))
            .define_method<bool (QRectF::*)(const QRectF &) const noexcept>("contains", &QRectF::contains, Arg("r"))
            .define_method<bool (QRectF::*)(qreal, qreal) const noexcept>("contains", &QRectF::contains, Arg("x"), Arg("y"))
            .define_method("intersected", &QRectF::intersected, Arg("other"))
            .define_method("intersects", &QRectF::intersects, Arg("r"))
            .define_method("left", &QRectF::left)
            .define_method("normalized", &QRectF::normalized)
            .define_method("right", &QRectF::right)
            .define_method("set_x", &QRectF::setX, Arg("pos"))
            .define_method("set_y", &QRectF::setY, Arg("pos"))
            .define_method("top", &QRectF::top)
            .define_method("top_left", &QRectF::topLeft)
            .define_method("top_right", &QRectF::topRight)
            .define_method("united", &QRectF::united, Arg("other"))
            .define_method("|", &QRectF::operator|, Arg("r"))
            .define_method("&", &QRectF::operator&, Arg("r"))
            .define_method("|=", &QRectF::operator|=, Arg("r"))
            .define_method("&=", &QRectF::operator&=, Arg("r"));
}
