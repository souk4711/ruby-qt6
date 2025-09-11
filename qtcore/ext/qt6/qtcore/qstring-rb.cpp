#include "qstring-rb.hpp"
#include <qstring.h>

using namespace Rice;

Rice::Class rb_cQString;

void Init_qstring(Rice::Module rb_mQt6QtCore)
{
    rb_cQString =
        // RubyQt6::QtCore::QString
        define_class_under<QString>(rb_mQt6QtCore, "QString")
            // Constructor
            .define_constructor(Constructor<QString, const char *>(), Arg("str"))
            // Public Functions
            .define_method("to_std_string", &QString::toStdString);
}
