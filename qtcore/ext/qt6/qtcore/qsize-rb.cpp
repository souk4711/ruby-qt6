#include "qsize-rb.hpp"
#include <qsize.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSize;
Class rb_cQSizeF;

void Init_qsize(Module rb_mQt6QtCore)
{
    rb_cQSize =
        // RubyQt6::QtCore::QSize
        define_class_under<QSize>(rb_mQt6QtCore, "QSize")
            // RubyQt6-Defined Functions
            .define_method("*", [](QSize *self, qreal  factor) -> QSize { return *self *  factor; })
            .define_method("+", [](QSize *self, QSize  *other) -> QSize { return *self +  *other; })
            .define_method("-", [](QSize *self, QSize  *other) -> QSize { return *self -  *other; })
            .define_method("/", [](QSize *self, qreal divisor) -> QSize { return *self / divisor; })
            .define_singleton_function("_operator_equal", [](QSize *lhs, QSize  *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_operator_equal", [](QSize *lhs, QSizeF *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QSize>())
            .define_constructor(Constructor<QSize, int, int>(), Arg("width"), Arg("height"))
            // Public Functions
            .define_method("bounded_to", &QSize::boundedTo, Arg("other_size"))
            .define_method("expanded_to", &QSize::expandedTo, Arg("other_size"))
            .define_method("grown_by", &QSize::grownBy, Arg("margins"))
            .define_method("height", &QSize::height)
            .define_method("empty?", &QSize::isEmpty)
            .define_method("null?", &QSize::isNull)
            .define_method("valid?", &QSize::isValid)
            .define_method("rheight", &QSize::rheight)
            .define_method("rwidth", &QSize::rwidth)
            .define_method<void (QSize::*)(int, int, Qt::AspectRatioMode) noexcept>("scale", &QSize::scale, Arg("w"), Arg("h"), Arg("mode"))
            .define_method<void (QSize::*)(const QSize &, Qt::AspectRatioMode) noexcept>("scale", &QSize::scale, Arg("s"), Arg("mode"))
            .define_method<QSize (QSize::*)(int, int, Qt::AspectRatioMode) const noexcept>("scaled", &QSize::scaled, Arg("w"), Arg("h"), Arg("mode"))
            .define_method<QSize (QSize::*)(const QSize &, Qt::AspectRatioMode) const noexcept>("scaled", &QSize::scaled, Arg("s"), Arg("mode"))
            .define_method("set_height", &QSize::setHeight, Arg("height"))
            .define_method("set_width", &QSize::setWidth, Arg("width"))
            .define_method("shrunk_by", &QSize::shrunkBy, Arg("margins"))
            .define_method("to_size_f", &QSize::toSizeF)
            .define_method("transpose", &QSize::transpose)
            .define_method("transposed", &QSize::transposed)
            .define_method("width", &QSize::width);

    rb_cQSizeF =
        // RubyQt6::QtCore::QSizeF
        define_class_under<QSizeF>(rb_mQt6QtCore, "QSizeF")
            // RubyQt6-Defined Functions
            .define_method("*", [](QSizeF *self,  qreal  factor) -> QSizeF { return *self *  factor; })
            .define_method("+", [](QSizeF *self, QSizeF  *other) -> QSizeF { return *self +  *other; })
            .define_method("-", [](QSizeF *self, QSizeF  *other) -> QSizeF { return *self -  *other; })
            .define_method("/", [](QSizeF *self,  qreal divisor) -> QSizeF { return *self / divisor; })
            .define_singleton_function("_operator_equal", [](QSizeF *lhs, QSize  *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_operator_equal", [](QSizeF *lhs, QSizeF *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QSizeF>())
            .define_constructor(Constructor<QSizeF, qreal, qreal>(), Arg("width"), Arg("height"))
            .define_constructor(Constructor<QSizeF, const QSize &>(), Arg("size"))
            // Public Functions
            .define_method("bounded_to", &QSizeF::boundedTo, Arg("other_size"))
            .define_method("expanded_to", &QSizeF::expandedTo, Arg("other_size"))
            .define_method("grown_by", &QSizeF::grownBy, Arg("margins"))
            .define_method("height", &QSizeF::height)
            .define_method("empty?", &QSizeF::isEmpty)
            .define_method("null?", &QSizeF::isNull)
            .define_method("valid?", &QSizeF::isValid)
            .define_method("rheight", &QSizeF::rheight)
            .define_method("rwidth", &QSizeF::rwidth)
            .define_method<void (QSizeF::*)(qreal, qreal, Qt::AspectRatioMode) noexcept>("scale", &QSizeF::scale, Arg("w"), Arg("h"), Arg("mode"))
            .define_method<void (QSizeF::*)(const QSizeF &, Qt::AspectRatioMode) noexcept>("scale", &QSizeF::scale, Arg("s"), Arg("mode"))
            .define_method<QSizeF (QSizeF::*)(qreal, qreal, Qt::AspectRatioMode) const noexcept>("scaled", &QSizeF::scaled, Arg("w"), Arg("h"), Arg("mode"))
            .define_method<QSizeF (QSizeF::*)(const QSizeF &, Qt::AspectRatioMode) const noexcept>("scaled", &QSizeF::scaled, Arg("s"), Arg("mode"))
            .define_method("set_height", &QSizeF::setHeight, Arg("height"))
            .define_method("set_width", &QSizeF::setWidth, Arg("width"))
            .define_method("shrunk_by", &QSizeF::shrunkBy, Arg("margins"))
            .define_method("to_size", &QSizeF::toSize)
            .define_method("transpose", &QSizeF::transpose)
            .define_method("transposed", &QSizeF::transposed)
            .define_method("width", &QSizeF::width);
}
