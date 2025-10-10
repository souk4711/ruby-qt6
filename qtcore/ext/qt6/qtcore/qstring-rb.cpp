#include "qstring-rb.hpp"
#include <qstring.h>

using namespace Rice;

Rice::Class rb_cQString;

QString QString_replace(QString *self, qsizetype index, const QString &after)
{
    if (index < 0 || index > self->size()) throw std::out_of_range("index " + std::to_string(index) + " out of string");
    return self->replace(index, 1, after);
}

void Init_qstring(Rice::Module rb_mQt6QtCore)
{
    rb_cQString =
        // RubyQt6::QtCore::QString
        define_class_under<QString>(rb_mQt6QtCore, "QString")
            // RubyQt6-Defined Functions
            .define_method("[]=", [](QString *self, qsizetype index, const char *after) -> QString { return QString_replace(self, index, after); }, Arg("index"), Arg("after"))
            // Constructor
            .define_constructor(Constructor<QString, const char *>(), Arg("str"))
            // Public Functions
            .define_method("capacity", &QString::capacity)
            .define_method("empty?", &QString::isEmpty)
            .define_method("length", &QString::length)
            .define_method("max_size", &QString::max_size)
            .define_method("reserve", &QString::reserve, Arg("size"))
            .define_method("shrink_to_fit", &QString::shrink_to_fit)
            .define_method("size", &QString::size)
            .define_method("to_std_string", &QString::toStdString);
}
