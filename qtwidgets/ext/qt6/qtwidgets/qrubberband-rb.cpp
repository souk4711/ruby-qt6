#include "qrubberband-rb.hpp"
#include <qrubberband.h>

using namespace Rice;

Rice::Class rb_cQRubberBand;

void Init_qrubberband(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQRubberBand =
        // RubyQt6::QtWidgets::QRubberBand
        define_class_under<QRubberBand, QWidget>(rb_mQt6QtWidgets, "QRubberBand")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QRubberBand::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QRubberBand, QRubberBand::Shape, QWidget *>(), Arg("shape"), Arg("parent"))
            // Public Functions
            .define_method<void (QRubberBand::*)(const QPoint &)>("move", &QRubberBand::move, Arg("p"))
            .define_method<void (QRubberBand::*)(int, int)>("move", &QRubberBand::move, Arg("x"), Arg("y"))
            .define_method<void (QRubberBand::*)(const QSize &)>("resize", &QRubberBand::resize, Arg("s"))
            .define_method<void (QRubberBand::*)(int, int)>("resize", &QRubberBand::resize, Arg("w"), Arg("h"))
            .define_method<void (QRubberBand::*)(const QRect &)>("set_geometry", &QRubberBand::setGeometry, Arg("r"))
            .define_method<void (QRubberBand::*)(int, int, int, int)>("set_geometry", &QRubberBand::setGeometry, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("shape", &QRubberBand::shape);

    Enum<QRubberBand::Shape> rb_cQRubberBandShape =
        // RubyQt6::QtWidgets::QRubberBand::Shape
        define_enum_under<QRubberBand::Shape>("Shape", rb_cQRubberBand)
            .define_value("Line", QRubberBand::Shape::Line)
            .define_value("Rectangle", QRubberBand::Shape::Rectangle);
}
