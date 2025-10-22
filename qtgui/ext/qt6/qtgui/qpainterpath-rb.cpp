#include "qpainterpath-rb.hpp"
#include <qpainterpath.h>
#include <rice/qenum.hpp>

#include <QFont>

using namespace Rice;

Rice::Class rb_cQPainterPath;
Rice::Class rb_cQPainterPathElement;

void Init_qpainterpath(Rice::Module rb_mQt6QtGui)
{
    rb_cQPainterPath =
        // RubyQt6::QtGui::QPainterPath
        define_class_under<QPainterPath>(rb_mQt6QtGui, "QPainterPath")
            // Constructor
            .define_constructor(Constructor<QPainterPath>())
            .define_constructor(Constructor<QPainterPath, const QPointF &>(), Arg("start_point"))
            // Public Functions
            .define_method<void (QPainterPath::*)(const QPointF &, qreal, qreal)>("add_ellipse", &QPainterPath::addEllipse, Arg("center"), Arg("rx"), Arg("ry"))
            .define_method<void (QPainterPath::*)(const QRectF &)>("add_ellipse", &QPainterPath::addEllipse, Arg("rect"))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal)>("add_ellipse", &QPainterPath::addEllipse, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("add_path", &QPainterPath::addPath, Arg("path"))
            .define_method("add_polygon", &QPainterPath::addPolygon, Arg("polygon"))
            .define_method<void (QPainterPath::*)(const QRectF &)>("add_rect", &QPainterPath::addRect, Arg("rect"))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal)>("add_rect", &QPainterPath::addRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("add_region", &QPainterPath::addRegion, Arg("region"))
            .define_method<void (QPainterPath::*)(const QRectF &, qreal, qreal, Qt::SizeMode)>("add_rounded_rect", &QPainterPath::addRoundedRect, Arg("rect"), Arg("x_radius"), Arg("y_radius"), Arg("mode") = static_cast<Qt::SizeMode>(Qt::AbsoluteSize))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal, qreal, qreal, Qt::SizeMode)>("add_rounded_rect", &QPainterPath::addRoundedRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("x_radius"), Arg("y_radius"), Arg("mode") = static_cast<Qt::SizeMode>(Qt::AbsoluteSize))
            .define_method<void (QPainterPath::*)(const QPointF &, const QFont &, const QString &)>("add_text", &QPainterPath::addText, Arg("point"), Arg("f"), Arg("text"))
            .define_method<void (QPainterPath::*)(qreal, qreal, const QFont &, const QString &)>("add_text", &QPainterPath::addText, Arg("x"), Arg("y"), Arg("f"), Arg("text"))
            .define_method("angle_at_percent", &QPainterPath::angleAtPercent, Arg("t"))
            .define_method<void (QPainterPath::*)(const QRectF &, qreal)>("arc_move_to", &QPainterPath::arcMoveTo, Arg("rect"), Arg("angle"))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal, qreal)>("arc_move_to", &QPainterPath::arcMoveTo, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("angle"))
            .define_method<void (QPainterPath::*)(const QRectF &, qreal, qreal)>("arc_to", &QPainterPath::arcTo, Arg("rect"), Arg("start_angle"), Arg("arc_length"))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal, qreal, qreal)>("arc_to", &QPainterPath::arcTo, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("start_angle"), Arg("arc_length"))
            .define_method("bounding_rect", &QPainterPath::boundingRect)
            .define_method("capacity", &QPainterPath::capacity)
            .define_method("clear", &QPainterPath::clear)
            .define_method("close_subpath", &QPainterPath::closeSubpath)
            .define_method("connect_path", &QPainterPath::connectPath, Arg("path"))
            .define_method<bool (QPainterPath::*)(const QPainterPath &) const>("contains", &QPainterPath::contains, Arg("p"))
            .define_method<bool (QPainterPath::*)(const QPointF &) const>("contains", &QPainterPath::contains, Arg("pt"))
            .define_method<bool (QPainterPath::*)(const QRectF &) const>("contains", &QPainterPath::contains, Arg("rect"))
            .define_method("control_point_rect", &QPainterPath::controlPointRect)
            .define_method<void (QPainterPath::*)(const QPointF &, const QPointF &, const QPointF &)>("cubic_to", &QPainterPath::cubicTo, Arg("ctrl_pt1"), Arg("ctrl_pt2"), Arg("end_pt"))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal, qreal, qreal)>("cubic_to", &QPainterPath::cubicTo, Arg("ctrl_pt1x"), Arg("ctrl_pt1y"), Arg("ctrl_pt2x"), Arg("ctrl_pt2y"), Arg("end_ptx"), Arg("end_pty"))
            .define_method("current_position", &QPainterPath::currentPosition)
            .define_method("element_at", &QPainterPath::elementAt, Arg("i"))
            .define_method("element_count", &QPainterPath::elementCount)
            .define_method("fill_rule", &QPainterPath::fillRule)
            .define_method("intersected", &QPainterPath::intersected, Arg("r"))
            .define_method<bool (QPainterPath::*)(const QPainterPath &) const>("intersects", &QPainterPath::intersects, Arg("p"))
            .define_method<bool (QPainterPath::*)(const QRectF &) const>("intersects", &QPainterPath::intersects, Arg("rect"))
            .define_method("empty?", &QPainterPath::isEmpty)
            .define_method("length", &QPainterPath::length)
            .define_method<void (QPainterPath::*)(const QPointF &)>("line_to", &QPainterPath::lineTo, Arg("p"))
            .define_method<void (QPainterPath::*)(qreal, qreal)>("line_to", &QPainterPath::lineTo, Arg("x"), Arg("y"))
            .define_method<void (QPainterPath::*)(const QPointF &)>("move_to", &QPainterPath::moveTo, Arg("p"))
            .define_method<void (QPainterPath::*)(qreal, qreal)>("move_to", &QPainterPath::moveTo, Arg("x"), Arg("y"))
            .define_method("percent_at_length", &QPainterPath::percentAtLength, Arg("t"))
            .define_method("point_at_percent", &QPainterPath::pointAtPercent, Arg("t"))
            .define_method<void (QPainterPath::*)(const QPointF &, const QPointF &)>("quad_to", &QPainterPath::quadTo, Arg("ctrl_pt"), Arg("end_pt"))
            .define_method<void (QPainterPath::*)(qreal, qreal, qreal, qreal)>("quad_to", &QPainterPath::quadTo, Arg("ctrl_ptx"), Arg("ctrl_pty"), Arg("end_ptx"), Arg("end_pty"))
            .define_method("reserve", &QPainterPath::reserve, Arg("size"))
            .define_method("set_element_position_at", &QPainterPath::setElementPositionAt, Arg("i"), Arg("x"), Arg("y"))
            .define_method("set_fill_rule", &QPainterPath::setFillRule, Arg("fill_rule"))
            .define_method("simplified", &QPainterPath::simplified)
            .define_method("slope_at_percent", &QPainterPath::slopeAtPercent, Arg("t"))
            .define_method("subtracted", &QPainterPath::subtracted, Arg("r"))
            .define_method("swap", &QPainterPath::swap, Arg("other"))
            .define_method("to_fill_polygon", &QPainterPath::toFillPolygon, Arg("matrix") = static_cast<const QTransform &>(QTransform()))
            .define_method("to_fill_polygons", &QPainterPath::toFillPolygons, Arg("matrix") = static_cast<const QTransform &>(QTransform()))
            .define_method("to_reversed", &QPainterPath::toReversed)
            .define_method("to_subpath_polygons", &QPainterPath::toSubpathPolygons, Arg("matrix") = static_cast<const QTransform &>(QTransform()))
            .define_method<void (QPainterPath::*)(const QPointF &)>("translate", &QPainterPath::translate, Arg("offset"))
            .define_method<void (QPainterPath::*)(qreal, qreal)>("translate", &QPainterPath::translate, Arg("dx"), Arg("dy"))
            .define_method<QPainterPath (QPainterPath::*)(const QPointF &) const>("translated", &QPainterPath::translated, Arg("offset"))
            .define_method<QPainterPath (QPainterPath::*)(qreal, qreal) const>("translated", &QPainterPath::translated, Arg("dx"), Arg("dy"))
            .define_method("united", &QPainterPath::united, Arg("r"));

    Enum<QPainterPath::ElementType> rb_cQPainterPathElementType =
        // RubyQt6::QtGui::QPainterPath::ElementType
        define_qenum_under<QPainterPath::ElementType>("ElementType", rb_cQPainterPath)
            .define_value("MoveToElement", QPainterPath::ElementType::MoveToElement)
            .define_value("LineToElement", QPainterPath::ElementType::LineToElement)
            .define_value("CurveToElement", QPainterPath::ElementType::CurveToElement)
            .define_value("CurveToDataElement", QPainterPath::ElementType::CurveToDataElement);

    rb_cQPainterPathElement =
        // RubyQt6::QtGui::QPainterPath::Element
        define_class_under<QPainterPath::Element>(rb_cQPainterPath, "Element")
            .define_constructor(Constructor<QPainterPath::Element>())
            .define_attr("x", &QPainterPath::Element::x)
            .define_attr("y", &QPainterPath::Element::y)
            // .define_attr("type", &QPainterPath::Element::type)
            .define_method("curve_to?", &QPainterPath::Element::isCurveTo)
            .define_method("line_to?", &QPainterPath::Element::isLineTo)
            .define_method("move_to?", &QPainterPath::Element::isMoveTo);
}
