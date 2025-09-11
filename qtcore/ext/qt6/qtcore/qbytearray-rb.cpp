#include "qbytearray-rb.hpp"
#include <qbytearray.h>

using namespace Rice;

Rice::Class rb_cQByteArray;

void Init_qbytearray(Rice::Module rb_mQt6QtCore)
{
    rb_cQByteArray =
        // RubyQt6::QtCore::QByteArray
        define_class_under<QByteArray>(rb_mQt6QtCore, "QByteArray")
            // Constructor
            .define_constructor(Constructor<QByteArray, const char *, qsizetype>(), Arg("data"), Arg("size") = static_cast<qsizetype>(-1))
            // Public Functions
            .define_method("to_std_string", &QByteArray::toStdString);
}
