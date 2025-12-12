#include "qframe-rb.hpp"
#include <qframe.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFrame;

void Init_qframe(Module rb_mQt6QtWidgets)
{
    rb_cQFrame =
        // RubyQt6::QtWidgets::QFrame
        define_class_under<QFrame, QWidget>(rb_mQt6QtWidgets, "QFrame")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFrame::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFrame, QWidget *>(), Arg("parent"))
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
            .define_method("set_mid_line_width", &QFrame::setMidLineWidth, Arg("w"));

    Data_Type<QFrame::Shape> rb_cQFrameShape =
        // RubyQt6::QtWidgets::QFrame::Shape
        define_qenum_under<QFrame::Shape>(rb_cQFrame, "Shape");
        define_qenum_value_under(rb_cQFrameShape, "NoFrame", QFrame::Shape::NoFrame);
        define_qenum_value_under(rb_cQFrameShape, "Box", QFrame::Shape::Box);
        define_qenum_value_under(rb_cQFrameShape, "Panel", QFrame::Shape::Panel);
        define_qenum_value_under(rb_cQFrameShape, "WinPanel", QFrame::Shape::WinPanel);
        define_qenum_value_under(rb_cQFrameShape, "HLine", QFrame::Shape::HLine);
        define_qenum_value_under(rb_cQFrameShape, "VLine", QFrame::Shape::VLine);
        define_qenum_value_under(rb_cQFrameShape, "StyledPanel", QFrame::Shape::StyledPanel);

    Data_Type<QFrame::Shadow> rb_cQFrameShadow =
        // RubyQt6::QtWidgets::QFrame::Shadow
        define_qenum_under<QFrame::Shadow>(rb_cQFrame, "Shadow");
        define_qenum_value_under(rb_cQFrameShadow, "Plain", QFrame::Shadow::Plain);
        define_qenum_value_under(rb_cQFrameShadow, "Raised", QFrame::Shadow::Raised);
        define_qenum_value_under(rb_cQFrameShadow, "Sunken", QFrame::Shadow::Sunken);
}
