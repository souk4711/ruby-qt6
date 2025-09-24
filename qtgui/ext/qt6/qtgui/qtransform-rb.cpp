#include "qtransform-rb.hpp"
#include <qtransform.h>

using namespace Rice;

Rice::Class rb_cQTransform;

void Init_qtransform(Rice::Module rb_mQt6QtGui)
{
    rb_cQTransform =
        // RubyQt6::QtGui::QTransform
        define_class_under<QTransform>(rb_mQt6QtGui, "QTransform")
            // Constructor
            .define_constructor(Constructor<QTransform>())
            .define_constructor(Constructor<QTransform, qreal, qreal, qreal, qreal, qreal, qreal>(), Arg("h11"), Arg("h12"), Arg("h21"), Arg("h22"), Arg("dx"), Arg("dy"))
            .define_constructor(Constructor<QTransform, qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal>(), Arg("h11"), Arg("h12"), Arg("h13"), Arg("h21"), Arg("h22"), Arg("h23"), Arg("h31"), Arg("h32"), Arg("h33"))
            // Public Functions
            .define_method("adjoint", &QTransform::adjoint)
            .define_method("as_affine_matrix", &QTransform::asAffineMatrix)
            .define_method("determinant", &QTransform::determinant)
            .define_method("dx", &QTransform::dx)
            .define_method("dy", &QTransform::dy)
            .define_method("inverted", &QTransform::inverted, Arg("invertible") = static_cast<bool *>(nullptr))
            .define_method("affine?", &QTransform::isAffine)
            .define_method("identity?", &QTransform::isIdentity)
            .define_method("invertible?", &QTransform::isInvertible)
            .define_method("rotating?", &QTransform::isRotating)
            .define_method("scaling?", &QTransform::isScaling)
            .define_method("translating?", &QTransform::isTranslating)
            .define_method("m11", &QTransform::m11)
            .define_method("m12", &QTransform::m12)
            .define_method("m13", &QTransform::m13)
            .define_method("m21", &QTransform::m21)
            .define_method("m22", &QTransform::m22)
            .define_method("m23", &QTransform::m23)
            .define_method("m31", &QTransform::m31)
            .define_method("m32", &QTransform::m32)
            .define_method("m33", &QTransform::m33)
            .define_method<QLine (QTransform::*)(const QLine &) const>("map", &QTransform::map, Arg("l"))
            .define_method<QLineF (QTransform::*)(const QLineF &) const>("map", &QTransform::map, Arg("l"))
            .define_method<QPoint (QTransform::*)(const QPoint &) const>("map", &QTransform::map, Arg("p"))
            .define_method<QPointF (QTransform::*)(const QPointF &) const>("map", &QTransform::map, Arg("p"))
            // .define_method<QPolygon (QTransform::*)(const QPolygon &) const>("map", &QTransform::map, Arg("a"))
            // .define_method<QPolygonF (QTransform::*)(const QPolygonF &) const>("map", &QTransform::map, Arg("a"))
            .define_method<QRegion (QTransform::*)(const QRegion &) const>("map", &QTransform::map, Arg("r"))
            .define_method<void (QTransform::*)(int, int, int *, int *) const>("map", &QTransform::map, Arg("x"), Arg("y"), Arg("tx"), Arg("ty"))
            .define_method<void (QTransform::*)(qreal, qreal, qreal *, qreal *) const>("map", &QTransform::map, Arg("x"), Arg("y"), Arg("tx"), Arg("ty"))
            .define_method<QRect (QTransform::*)(const QRect &) const>("map_rect", &QTransform::mapRect, Arg("rect"))
            .define_method<QRectF (QTransform::*)(const QRectF &) const>("map_rect", &QTransform::mapRect, Arg("rect"))
            .define_method("map_to_polygon", &QTransform::mapToPolygon, Arg("r"))
            .define_method("reset", &QTransform::reset)
            .define_method<QTransform &(QTransform::*)(qreal, Qt::Axis)>("rotate", &QTransform::rotate, Arg("a"), Arg("axis") = static_cast<Qt::Axis>(Qt::ZAxis))
            .define_method<QTransform &(QTransform::*)(qreal, Qt::Axis, qreal)>("rotate", &QTransform::rotate, Arg("a"), Arg("axis"), Arg("distance_to_plane"))
            .define_method<QTransform &(QTransform::*)(qreal, Qt::Axis)>("rotate_radians", &QTransform::rotateRadians, Arg("a"), Arg("axis") = static_cast<Qt::Axis>(Qt::ZAxis))
            .define_method<QTransform &(QTransform::*)(qreal, Qt::Axis, qreal)>("rotate_radians", &QTransform::rotateRadians, Arg("a"), Arg("axis"), Arg("distance_to_plane"))
            .define_method("scale", &QTransform::scale, Arg("sx"), Arg("sy"))
            .define_method("set_matrix", &QTransform::setMatrix, Arg("m11"), Arg("m12"), Arg("m13"), Arg("m21"), Arg("m22"), Arg("m23"), Arg("m31"), Arg("m32"), Arg("m33"))
            .define_method("shear", &QTransform::shear, Arg("sh"), Arg("sv"))
            .define_method("translate", &QTransform::translate, Arg("dx"), Arg("dy"))
            .define_method("transposed", &QTransform::transposed)
            .define_method("type", &QTransform::type)
            // Static Public Members
            .define_singleton_function("from_scale", &QTransform::fromScale, Arg("dx"), Arg("dy"))
            .define_singleton_function("from_translate", &QTransform::fromTranslate, Arg("dx"), Arg("dy"))
            .define_singleton_function("quad_to_quad", &QTransform::quadToQuad, Arg("one"), Arg("two"), Arg("result"))
            .define_singleton_function("quad_to_square", &QTransform::quadToSquare, Arg("quad"), Arg("result"))
            .define_singleton_function("square_to_quad", &QTransform::squareToQuad, Arg("square"), Arg("result"));

    Enum<QTransform::TransformationType> rb_cQTransformTransformationType =
        // RubyQt6::QtGui::QTransform::TransformationType
        define_enum_under<QTransform::TransformationType>("TransformationType", rb_cQTransform)
            .define_value("TxNone", QTransform::TransformationType::TxNone)
            .define_value("TxTranslate", QTransform::TransformationType::TxTranslate)
            .define_value("TxScale", QTransform::TransformationType::TxScale)
            .define_value("TxRotate", QTransform::TransformationType::TxRotate)
            .define_value("TxShear", QTransform::TransformationType::TxShear)
            .define_value("TxProject", QTransform::TransformationType::TxProject);
}
