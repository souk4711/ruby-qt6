#include "qpainterpathstroker-rb.hpp"
#include <qpainterpath.h>

#include <QPen>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPainterPathStroker;

void Init_qpainterpathstroker(Module rb_mQt6QtGui)
{
    rb_cQPainterPathStroker =
        // RubyQt6::QtGui::QPainterPathStroker
        define_class_under<QPainterPathStroker>(rb_mQt6QtGui, "QPainterPathStroker")
            // Constructor
            .define_constructor(Constructor<QPainterPathStroker>())
            .define_constructor(Constructor<QPainterPathStroker, const QPen &>(), Arg("pen"))
            // Public Functions
            .define_method("cap_style", &QPainterPathStroker::capStyle)
            .define_method("create_stroke", &QPainterPathStroker::createStroke, Arg("path"))
            .define_method("curve_threshold", &QPainterPathStroker::curveThreshold)
            .define_method("dash_offset", &QPainterPathStroker::dashOffset)
            .define_method("dash_pattern", &QPainterPathStroker::dashPattern)
            .define_method("join_style", &QPainterPathStroker::joinStyle)
            .define_method("miter_limit", &QPainterPathStroker::miterLimit)
            .define_method("set_cap_style", &QPainterPathStroker::setCapStyle, Arg("style"))
            .define_method("set_curve_threshold", &QPainterPathStroker::setCurveThreshold, Arg("threshold"))
            .define_method("set_dash_offset", &QPainterPathStroker::setDashOffset, Arg("offset"))
            .define_method<void (QPainterPathStroker::*)(Qt::PenStyle)>("set_dash_pattern", &QPainterPathStroker::setDashPattern, Arg("style"))
            .define_method<void (QPainterPathStroker::*)(const QList<qreal> &)>("set_dash_pattern", &QPainterPathStroker::setDashPattern, Arg("dash_pattern"))
            .define_method("set_join_style", &QPainterPathStroker::setJoinStyle, Arg("style"))
            .define_method("set_miter_limit", &QPainterPathStroker::setMiterLimit, Arg("length"))
            .define_method("set_width", &QPainterPathStroker::setWidth, Arg("width"))
            .define_method("width", &QPainterPathStroker::width);
}
