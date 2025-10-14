#include "qpoint-rb.hpp"
#include <qpoint.h>

using namespace Rice;

Rice::Class rb_cQPoint;
Rice::Class rb_cQPointF;

void Init_qpoint(Rice::Module rb_mQt6QtCore)
{
    rb_cQPoint =
        // RubyQt6::QtCore::QPoint
        define_class_under<QPoint>(rb_mQt6QtCore, "QPoint")
            // RubyQt6-Defined Functions
            .define_method("*", [](QPoint *self,  qreal  factor) -> QPoint { return *self *  factor; })
            .define_method("+", [](QPoint *self, QPoint  *other) -> QPoint { return *self +  *other; })
            .define_method("-", [](QPoint *self, QPoint  *other) -> QPoint { return *self -  *other; })
            .define_method("/", [](QPoint *self,  qreal divisor) -> QPoint { return *self / divisor; })
            .define_method("+@", [](QPoint *self) -> QPoint { return + *self; })
            .define_method("-@", [](QPoint *self) -> QPoint { return - *self; })
            .define_singleton_function("_operator_equal", [](QPoint *lhs, QPoint  *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_operator_equal", [](QPoint *lhs, QPointF *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QPoint>())
            .define_constructor(Constructor<QPoint, int, int>(), Arg("xpos"), Arg("ypos"))
            // Public Functions
            .define_method("null?", &QPoint::isNull)
            .define_method("manhattan_length", &QPoint::manhattanLength)
            .define_method("rx", &QPoint::rx)
            .define_method("ry", &QPoint::ry)
            .define_method("set_x", &QPoint::setX)
            .define_method("set_y", &QPoint::setY)
            .define_method("to_point_f", &QPoint::toPointF)
            .define_method("transposed", &QPoint::transposed)
            .define_method("x", &QPoint::x)
            .define_method("y", &QPoint::y);

    rb_cQPointF =
        // RubyQt6::QtCore::QPointF
        define_class_under<QPointF>(rb_mQt6QtCore, "QPointF")
            // RubyQt6-Defined Functions
            .define_method("*", [](QPointF *self,   qreal  factor) -> QPointF { return *self *  factor; })
            .define_method("+", [](QPointF *self, QPointF  *other) -> QPointF { return *self +  *other; })
            .define_method("-", [](QPointF *self, QPointF  *other) -> QPointF { return *self -  *other; })
            .define_method("/", [](QPointF *self,   qreal divisor) -> QPointF { return *self / divisor; })
            .define_method("+@", [](QPointF *self) -> QPointF { return + *self; })
            .define_method("-@", [](QPointF *self) -> QPointF { return - *self; })
            .define_singleton_function("_operator_equal", [](QPointF *lhs, QPoint  *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_operator_equal", [](QPointF *lhs, QPointF *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QPointF>())
            .define_constructor(Constructor<QPointF, qreal, qreal>(), Arg("xpos"), Arg("ypos"))
            .define_constructor(Constructor<QPointF, const QPoint &>(), Arg("point"))
            // Public Functions
            .define_method("null?", &QPointF::isNull)
            .define_method("manhattan_length", &QPointF::manhattanLength)
            .define_method("rx", &QPointF::rx)
            .define_method("ry", &QPointF::ry)
            .define_method("set_x", &QPointF::setX)
            .define_method("set_y", &QPointF::setY)
            .define_method("to_point", &QPointF::toPoint)
            .define_method("transposed", &QPointF::transposed)
            .define_method("x", &QPointF::x)
            .define_method("y", &QPointF::y);
}
