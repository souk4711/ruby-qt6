#include "qpolygon-rb.hpp"
#include <qpolygon.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPolygon;
Class rb_cQPolygonF;

void Init_qpolygon(Module rb_mQt6QtGui)
{
    rb_cQPolygon =
        // RubyQt6::QtGui::QPolygon
        define_qlass_under<QPolygon, QList<QPoint>>(rb_mQt6QtGui, "QPolygon")
            // Constructor
            .define_constructor(Constructor<QPolygon>())
            // Public Functions
            .define_method("bounding_rect", &QPolygon::boundingRect)
            .define_method("contains_point", &QPolygon::containsPoint, Arg("pt"), Arg("fill_rule"))
            .define_method("intersected", &QPolygon::intersected, Arg("r"))
            .define_method("intersects", &QPolygon::intersects, Arg("r"))
            .define_method<QPoint (QPolygon::*)(int) const>("point", &QPolygon::point, Arg("i"))
            .define_method<void (QPolygon::*)(int, int, const QPolygon &, int)>("put_points", &QPolygon::putPoints, Arg("index"), Arg("n_points"), Arg("from"), Arg("from_index") = static_cast<int>(0))
            // .define_method<void (QPolygon::*)(int, int, int, int)>("put_points", &QPolygon::putPoints, Arg("index"), Arg("n_points"), Arg("firstx"), Arg("firsty"))
            .define_method<void (QPolygon::*)(int, const QPoint &)>("set_point", &QPolygon::setPoint, Arg("index"), Arg("p"))
            .define_method<void (QPolygon::*)(int, int, int)>("set_point", &QPolygon::setPoint, Arg("index"), Arg("x"), Arg("y"))
            // .define_method<void (QPolygon::*)(int, int, int)>("set_points", &QPolygon::setPoints, Arg("n_points"), Arg("firstx"), Arg("firsty"))
            .define_method("subtracted", &QPolygon::subtracted, Arg("r"))
            .define_method("to_polygon_f", &QPolygon::toPolygonF)
            .define_method<void (QPolygon::*)(const QPoint &)>("translate", &QPolygon::translate, Arg("offset"))
            .define_method<void (QPolygon::*)(int, int)>("translate", &QPolygon::translate, Arg("dx"), Arg("dy"))
            .define_method<QPolygon (QPolygon::*)(const QPoint &) const>("translated", &QPolygon::translated, Arg("offset"))
            .define_method<QPolygon (QPolygon::*)(int, int) const>("translated", &QPolygon::translated, Arg("dx"), Arg("dy"))
            .define_method("united", &QPolygon::united, Arg("r"));

    rb_cQPolygonF =
        // RubyQt6::QtGui::QPolygonF
        define_qlass_under<QPolygonF, QList<QPointF>>(rb_mQt6QtGui, "QPolygonF")
            // Constructor
            .define_constructor(Constructor<QPolygonF>())
            .define_constructor(Constructor<QPolygonF, const QPolygon &>(), Arg("polygon"))
            // Public Functions
            .define_method("bounding_rect", &QPolygonF::boundingRect)
            .define_method("contains_point", &QPolygonF::containsPoint, Arg("pt"), Arg("fill_rule"))
            .define_method("intersected", &QPolygonF::intersected, Arg("r"))
            .define_method("intersects", &QPolygonF::intersects, Arg("r"))
            .define_method("closed?", &QPolygonF::isClosed)
            .define_method("subtracted", &QPolygonF::subtracted, Arg("r"))
            .define_method("to_polygon", &QPolygonF::toPolygon)
            .define_method<void (QPolygonF::*)(const QPointF &)>("translate", &QPolygonF::translate, Arg("offset"))
            .define_method<void (QPolygonF::*)(qreal, qreal)>("translate", &QPolygonF::translate, Arg("dx"), Arg("dy"))
            .define_method<QPolygonF (QPolygonF::*)(const QPointF &) const>("translated", &QPolygonF::translated, Arg("offset"))
            .define_method<QPolygonF (QPolygonF::*)(qreal, qreal) const>("translated", &QPolygonF::translated, Arg("dx"), Arg("dy"))
            .define_method("united", &QPolygonF::united, Arg("r"));
}
