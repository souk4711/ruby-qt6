#include "qframe-rb.hpp"
#include <qframe.h>

using namespace Rice;

Rice::Class rb_cQFrame;

void Init_QFrame(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFrame =
        // Qt6::QtWidgets::QFrame
        define_class_under<QFrame, QWidget>(rb_mQt6QtWidgets, "QFrame")
            // Public Functions
            .define_constructor(Constructor<QFrame, QWidget *, Qt::WindowFlags>(), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("f") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
            .define_method("frame_rect", &QFrame::frameRect)
            .define_method("frame_shadow", &QFrame::frameShadow)
            .define_method("frame_shape", &QFrame::frameShape)
            .define_method("frame_style", &QFrame::frameStyle)
            .define_method("frame_width", &QFrame::frameWidth)
            .define_method("line_width", &QFrame::lineWidth)
            .define_method("mid_line_width", &QFrame::midLineWidth)
            .define_method("set_frame_rect", &QFrame::setFrameRect, Arg(""))
            .define_method("set_frame_shadow", &QFrame::setFrameShadow, Arg(""))
            .define_method("set_frame_shape", &QFrame::setFrameShape, Arg(""))
            .define_method("set_frame_style", &QFrame::setFrameStyle, Arg(""))
            .define_method("set_line_width", &QFrame::setLineWidth, Arg(""))
            .define_method("set_mid_line_width", &QFrame::setMidLineWidth, Arg(""))
            // Reimplemented Public Functions
            .define_method("size_hint", &QFrame::sizeHint);

    // clang-format off
    Enum<QFrame::Shape> rb_cQFrameShape =
        // Qt6::QtWidgets::QFrame::Shape
        define_enum_under<QFrame::Shape>("Shape", rb_cQFrame)
            .define_value("NoFrame", QFrame::Shape::NoFrame)
            .define_value("Box", QFrame::Shape::Box)
            .define_value("Panel", QFrame::Shape::Panel)
            .define_value("WinPanel", QFrame::Shape::WinPanel)
            .define_value("HLine", QFrame::Shape::HLine)
            .define_value("VLine", QFrame::Shape::VLine)
            .define_value("StyledPanel", QFrame::Shape::StyledPanel);

    Enum<QFrame::Shadow> rb_cQFrameShadow =
        // Qt6::QtWidgets::QFrame::Shadow
        define_enum_under<QFrame::Shadow>("Shadow", rb_cQFrame)
            .define_value("Plain", QFrame::Shadow::Plain)
            .define_value("Raised", QFrame::Shadow::Raised)
            .define_value("Sunken", QFrame::Shadow::Sunken);

    Enum<QFrame::StyleMask> rb_cQFrameStyleMask =
        // Qt6::QtWidgets::QFrame::StyleMask
        define_enum_under<QFrame::StyleMask>("StyleMask", rb_cQFrame)
            .define_value("Shadow_Mask", QFrame::StyleMask::Shadow_Mask)
            .define_value("Shape_Mask", QFrame::StyleMask::Shape_Mask);
}
