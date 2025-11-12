#include "qgradient-rb.hpp"
#include <qbrush.h>

using namespace Rice;

Rice::Class rb_cQGradient;
Rice::Class rb_cQConicalGradient;
Rice::Class rb_cQLinearGradient;
Rice::Class rb_cQRadialGradient;

void Init_qgradient(Rice::Module rb_mQt6QtGui)
{
    rb_cQGradient =
        // RubyQt6::QtGui::QGradient
        define_class_under<QGradient>(rb_mQt6QtGui, "QGradient")
            // Constructor
            .define_constructor(Constructor<QGradient>())
            .define_constructor(Constructor<QGradient, QGradient::Preset>(), Arg("preset"))
            // Public Functions
            .define_method("coordinate_mode", &QGradient::coordinateMode)
            .define_method("interpolation_mode", &QGradient::interpolationMode)
            .define_method("set_color_at", &QGradient::setColorAt, Arg("pos"), Arg("color"))
            .define_method("set_coordinate_mode", &QGradient::setCoordinateMode, Arg("mode"))
            .define_method("set_interpolation_mode", &QGradient::setInterpolationMode, Arg("mode"))
            .define_method("set_spread", &QGradient::setSpread, Arg("spread"))
            .define_method("set_stops", &QGradient::setStops, Arg("stops"))
            .define_method("spread", &QGradient::spread)
            .define_method("stops", &QGradient::stops)
            .define_method("type", &QGradient::type);

    rb_cQConicalGradient =
        // RubyQt6::QtGui::QConicalGradient
        define_class_under<QConicalGradient, QGradient>(rb_mQt6QtGui, "QConicalGradient")
            // Constructor
            .define_constructor(Constructor<QConicalGradient>())
            .define_constructor(Constructor<QConicalGradient, qreal, qreal, qreal>(), Arg("center_x"), Arg("center_y"), Arg("start_angle"))
            .define_constructor(Constructor<QConicalGradient, const QPointF &, qreal>(), Arg("center"), Arg("start_angle"))
            // Public Functions
            .define_method("angle", &QConicalGradient::angle)
            .define_method("center", &QConicalGradient::center)
            .define_method("set_angle", &QConicalGradient::setAngle, Arg("angle"))
            .define_method<void (QConicalGradient::*)(qreal, qreal)>("set_center", &QConicalGradient::setCenter, Arg("x"), Arg("y"))
            .define_method<void (QConicalGradient::*)(const QPointF &)>("set_center", &QConicalGradient::setCenter, Arg("center"));

    rb_cQLinearGradient =
        // RubyQt6::QtGui::QLinearGradient
        define_class_under<QLinearGradient, QGradient>(rb_mQt6QtGui, "QLinearGradient")
            // Constructor
            .define_constructor(Constructor<QLinearGradient>())
            .define_constructor(Constructor<QLinearGradient, qreal, qreal, qreal, qreal>(), Arg("start_x"), Arg("start_y"), Arg("final_stop_x"), Arg("final_stop_y"))
            .define_constructor(Constructor<QLinearGradient, const QPointF &, const QPointF &>(), Arg("start"), Arg("final_stop"))
            // Public Functions
            .define_method("final_stop", &QLinearGradient::finalStop)
            .define_method<void (QLinearGradient::*)(qreal, qreal)>("set_final_stop", &QLinearGradient::setFinalStop, Arg("x"), Arg("y"))
            .define_method<void (QLinearGradient::*)(const QPointF &)>("set_final_stop", &QLinearGradient::setFinalStop, Arg("stop"))
            .define_method<void (QLinearGradient::*)(qreal, qreal)>("set_start", &QLinearGradient::setStart, Arg("x"), Arg("y"))
            .define_method<void (QLinearGradient::*)(const QPointF &)>("set_start", &QLinearGradient::setStart, Arg("start"))
            .define_method("start", &QLinearGradient::start);

    rb_cQRadialGradient =
        // RubyQt6::QtGui::QRadialGradient
        define_class_under<QRadialGradient, QGradient>(rb_mQt6QtGui, "QRadialGradient")
            // Constructor
            .define_constructor(Constructor<QRadialGradient>())
            .define_constructor(Constructor<QRadialGradient, qreal, qreal, qreal, qreal, qreal, qreal>(), Arg("cx"), Arg("cy"), Arg("center_radius"), Arg("fx"), Arg("fy"), Arg("focal_radius"))
            .define_constructor(Constructor<QRadialGradient, qreal, qreal, qreal, qreal, qreal>(), Arg("cx"), Arg("cy"), Arg("radius"), Arg("fx"), Arg("fy"))
            .define_constructor(Constructor<QRadialGradient, qreal, qreal, qreal>(), Arg("cx"), Arg("cy"), Arg("radius"))
            .define_constructor(Constructor<QRadialGradient, const QPointF &, qreal, const QPointF &, qreal>(), Arg("center"), Arg("center_radius"), Arg("focal_point"), Arg("focal_radius"))
            .define_constructor(Constructor<QRadialGradient, const QPointF &, qreal, const QPointF &>(), Arg("center"), Arg("radius"), Arg("focal_point"))
            .define_constructor(Constructor<QRadialGradient, const QPointF &, qreal>(), Arg("center"), Arg("radius"))
            // Public Functions
            .define_method("center", &QRadialGradient::center)
            .define_method("center_radius", &QRadialGradient::centerRadius)
            .define_method("focal_point", &QRadialGradient::focalPoint)
            .define_method("focal_radius", &QRadialGradient::focalRadius)
            .define_method("radius", &QRadialGradient::radius)
            .define_method<void (QRadialGradient::*)(qreal, qreal)>("set_center", &QRadialGradient::setCenter, Arg("x"), Arg("y"))
            .define_method<void (QRadialGradient::*)(const QPointF &)>("set_center", &QRadialGradient::setCenter, Arg("center"))
            .define_method("set_center_radius", &QRadialGradient::setCenterRadius, Arg("radius"))
            .define_method<void (QRadialGradient::*)(qreal, qreal)>("set_focal_point", &QRadialGradient::setFocalPoint, Arg("x"), Arg("y"))
            .define_method<void (QRadialGradient::*)(const QPointF &)>("set_focal_point", &QRadialGradient::setFocalPoint, Arg("focal_point"))
            .define_method("set_focal_radius", &QRadialGradient::setFocalRadius, Arg("radius"))
            .define_method("set_radius", &QRadialGradient::setRadius, Arg("radius"));
}
