#include "qline-rb.hpp"
#include <qline.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQLine;
Class rb_cQLineF;

void Init_qline(Module rb_mQt6QtCore)
{
    rb_cQLine =
        // RubyQt6::QtCore::QLine
        define_qlass_under<QLine>(rb_mQt6QtCore, "QLine")
            // RubyQt6-Defined Functions
            .define_singleton_function("_operator_equal", [](QLine *lhs, QLine  *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_operator_equal", [](QLine *lhs, QLineF *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QLine>())
            .define_constructor(Constructor<QLine, int, int, int, int>(), Arg("x1"), Arg("y1"), Arg("x2"), Arg("y2"))
            .define_constructor(Constructor<QLine, const QPoint &, const QPoint &>(), Arg("p1"), Arg("p2"))
            // Public Functions
            .define_method("p1", &QLine::p1)
            .define_method("p2", &QLine::p2)
            .define_method("x1", &QLine::x1)
            .define_method("x2", &QLine::x2)
            .define_method("y1", &QLine::y1)
            .define_method("y2", &QLine::y2)
            .define_method("center", &QLine::center)
            .define_method("dx", &QLine::dx)
            .define_method("dy", &QLine::dy)
            .define_method("null?", &QLine::isNull)
            .define_method("set_p1", &QLine::setP1, Arg("p1"))
            .define_method("set_p2", &QLine::setP2, Arg("p2"))
            .define_method("set_line", &QLine::setLine, Arg("x1"), Arg("y1"), Arg("x2"), Arg("y2"))
            .define_method("set_points", &QLine::setPoints, Arg("p1"), Arg("p2"))
            .define_method("to_line_f", &QLine::toLineF)
            .define_method<void (QLine::*)(const QPoint &)>("translate", &QLine::translate, Arg("offset"))
            .define_method<void (QLine::*)(int, int)>("translate", &QLine::translate, Arg("dx"), Arg("dy"))
            .define_method<QLine (QLine::*)(const QPoint &) const>("translated", &QLine::translated, Arg("offset"))
            .define_method<QLine (QLine::*)(int, int) const>("translated", &QLine::translated, Arg("dx"), Arg("dy"));

    rb_cQLineF =
        // RubyQt6::QtCore::QLineF
        define_qlass_under<QLineF>(rb_mQt6QtCore, "QLineF")
            // RubyQt6-Defined Functions
            .define_singleton_function("_operator_equal", [](QLineF *lhs, QLine  *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_operator_equal", [](QLineF *lhs, QLineF *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QLineF>())
            .define_constructor(Constructor<QLineF, qreal, qreal, qreal, qreal>(), Arg("x1"), Arg("y1"), Arg("x2"), Arg("y2"))
            .define_constructor(Constructor<QLineF, const QPointF &, const QPointF &>(), Arg("p1"), Arg("p2"))
            .define_constructor(Constructor<QLineF, const QLine &>(), Arg("line"))
            // Public Functions
            .define_method("p1", &QLineF::p1)
            .define_method("p2", &QLineF::p2)
            .define_method("x1", &QLineF::x1)
            .define_method("x2", &QLineF::x2)
            .define_method("y1", &QLineF::y1)
            .define_method("y2", &QLineF::y2)
            .define_method("angle", &QLineF::angle)
            .define_method("angle_to", &QLineF::angleTo, Arg("line"))
            .define_method("center", &QLineF::center)
            .define_method("dx", &QLineF::dx)
            .define_method("dy", &QLineF::dy)
            .define_method("intersects", &QLineF::intersects, Arg("line"), Arg("intersection_point") = static_cast<QLineF *>(nullptr))
            .define_method("null?", &QLineF::isNull)
            .define_method("length", &QLineF::length)
            .define_method("normal_vector", &QLineF::normalVector)
            .define_method("point_at", &QLineF::pointAt, Arg("t"))
            .define_method("set_p1", &QLineF::setP1, Arg("p1"))
            .define_method("set_p2", &QLineF::setP2, Arg("p2"))
            .define_method("set_angle", &QLineF::setAngle, Arg("angle"))
            .define_method("set_length", &QLineF::setLength, Arg("length"))
            .define_method("set_line", &QLineF::setLine, Arg("x1"), Arg("y1"), Arg("x2"), Arg("y2"))
            .define_method("set_points", &QLineF::setPoints, Arg("p1"), Arg("p2"))
            .define_method("to_line", &QLineF::toLine)
            .define_method<void (QLineF::*)(const QPointF &)>("translate", &QLineF::translate, Arg("offset"))
            .define_method<void (QLineF::*)(qreal, qreal)>("translate", &QLineF::translate, Arg("dx"), Arg("dy"))
            .define_method<QLineF (QLineF::*)(const QPointF &) const>("translated", &QLineF::translated, Arg("offset"))
            .define_method<QLineF (QLineF::*)(qreal, qreal) const>("translated", &QLineF::translated, Arg("dx"), Arg("dy"))
            .define_method("unit_vector", &QLineF::unitVector)
            // Static Public Members
            .define_singleton_function("from_polar", &QLineF::fromPolar, Arg("length"), Arg("angle"));
}
