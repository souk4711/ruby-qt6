#include "qframe-rb.hpp"
#include <qframe.h>

using namespace Rice;

Rice::Class rb_cQFrame;

void Init_qframe(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFrame =
        // RubyQt6::QtWidgets::QFrame
        define_class_under<QFrame, QWidget>(rb_mQt6QtWidgets, "QFrame")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFrame::staticMetaObject; })
            // Public Functions
            .define_method("frame_rect", &QFrame::frameRect)
            .define_method("frame_shadow", &QFrame::frameShadow)
            .define_method("frame_shape", &QFrame::frameShape)
            .define_method("frame_style", &QFrame::frameStyle)
            .define_method("frame_width", &QFrame::frameWidth)
            .define_method("line_width", &QFrame::lineWidth)
            .define_method("mid_line_width", &QFrame::midLineWidth)
            .define_method("set_frame_rect", &QFrame::setFrameRect, Arg("rect"))
            .define_method("set_frame_shadow", &QFrame::setFrameShadow, Arg("shadow"))
            .define_method("set_frame_shape", &QFrame::setFrameShape, Arg("shape"))
            .define_method("set_frame_style", &QFrame::setFrameStyle, Arg("style"))
            .define_method("set_line_width", &QFrame::setLineWidth, Arg("w"))
            .define_method("set_mid_line_width", &QFrame::setMidLineWidth, Arg("w"))
            .define_method("size_hint", &QFrame::sizeHint);

    Enum<QFrame::Shape> rb_cQFrameShape =
        // RubyQt6::QtWidgets::QFrame::Shape
        define_enum_under<QFrame::Shape>("Shape", rb_cQFrame)
            .define_value("NoFrame", QFrame::Shape::NoFrame)
            .define_value("Box", QFrame::Shape::Box)
            .define_value("Panel", QFrame::Shape::Panel)
            .define_value("WinPanel", QFrame::Shape::WinPanel)
            .define_value("HLine", QFrame::Shape::HLine)
            .define_value("VLine", QFrame::Shape::VLine)
            .define_value("StyledPanel", QFrame::Shape::StyledPanel);

    Enum<QFrame::Shadow> rb_cQFrameShadow =
        // RubyQt6::QtWidgets::QFrame::Shadow
        define_enum_under<QFrame::Shadow>("Shadow", rb_cQFrame)
            .define_value("Plain", QFrame::Shadow::Plain)
            .define_value("Raised", QFrame::Shadow::Raised)
            .define_value("Sunken", QFrame::Shadow::Sunken);
}
