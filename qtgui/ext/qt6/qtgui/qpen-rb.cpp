#include "qpen-rb.hpp"
#include <qpen.h>

using namespace Rice;

Rice::Class rb_cQPen;

void Init_qpen(Rice::Module rb_mQt6QtGui)
{
    rb_cQPen =
        // RubyQt6::QtGui::QPen
        define_class_under<QPen>(rb_mQt6QtGui, "QPen")
            // Constructor
            .define_constructor(Constructor<QPen, Qt::PenStyle>(), Arg("style"))
            .define_constructor(Constructor<QPen, const QColor &>(), Arg("color"))
            .define_constructor(Constructor<QPen, const QBrush &, qreal>(), Arg("brush"), Arg("width"))
            // Public Functions
            .define_method("brush", &QPen::brush)
            .define_method("cap_style", &QPen::capStyle)
            .define_method("color", &QPen::color)
            .define_method("dash_offset", &QPen::dashOffset)
            .define_method("dash_pattern", &QPen::dashPattern)
            .define_method("cosmetic?", &QPen::isCosmetic)
            .define_method("detached?", &QPen::isDetached)
            .define_method("solid?", &QPen::isSolid)
            .define_method("join_style", &QPen::joinStyle)
            .define_method("miter_limit", &QPen::miterLimit)
            .define_method("set_brush", &QPen::setBrush, Arg("brush"))
            .define_method("set_cap_style", &QPen::setCapStyle, Arg("pcs"))
            .define_method("set_color", &QPen::setColor, Arg("color"))
            .define_method("set_cosmetic", &QPen::setCosmetic, Arg("cosmetic"))
            .define_method("set_dash_offset", &QPen::setDashOffset, Arg("doffset"))
            .define_method("set_dash_pattern", &QPen::setDashPattern, Arg("pattern"))
            .define_method("set_join_style", &QPen::setJoinStyle, Arg("pcs"))
            .define_method("set_miter_limit", &QPen::setMiterLimit, Arg("limit"))
            .define_method("set_style", &QPen::setStyle, Arg("style"))
            .define_method("set_width", &QPen::setWidth, Arg("width"))
            .define_method("set_width_f", &QPen::setWidthF, Arg("width"))
            .define_method("style", &QPen::style)
            .define_method("width", &QPen::width)
            .define_method("width_f", &QPen::widthF);
}
