#include "qbytearray-rb.hpp"
#include <qbytearray.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQByteArray;

std::optional<QByteArray> QByteArray_slice(QByteArray *self, qsizetype start, qsizetype length)
{
    if (start < 0) {
        start = start + self->size();
        if (start < 0) return std::nullopt;
    } else if (start >= self->size()) {
        return std::nullopt;
    }

    if (length < 0) {
        return std::nullopt;
    } else if (start + length > self->size()) {
        return self->sliced(start);
    } else {
        return self->sliced(start, length);
    }
}

void Init_qbytearray(Module rb_mQt6QtCore)
{
    rb_cQByteArray =
        // RubyQt6::QtCore::QByteArray
        define_class_under<QByteArray>(rb_mQt6QtCore, "QByteArray")
            // RubyQt6-Defined Functions
            .define_method("[]", QByteArray_slice, Arg("start"), Arg("length") = static_cast<qsizetype>(1))
            .define_singleton_function("_operator_compare", [](QByteArray *lhs, QByteArray *rhs) -> int { return lhs->compare(*rhs); }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QByteArray, const char *>(), Arg("data"))
            // Public Functions
            .define_method("capacity", &QByteArray::capacity)
            .define_method("empty?", &QByteArray::isEmpty)
            .define_method("length", &QByteArray::length)
            .define_method("max_size", &QByteArray::max_size)
            .define_method("reserve", &QByteArray::reserve, Arg("size"))
            .define_method("shrink_to_fit", &QByteArray::shrink_to_fit)
            .define_method("to_std_string", &QByteArray::toStdString);
}
