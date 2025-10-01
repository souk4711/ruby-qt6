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
            .define_constructor(Constructor<QByteArray, const char *>(), Arg("data"))
            // Public Functions
            .define_method("to_std_string", &QByteArray::toStdString);
}
