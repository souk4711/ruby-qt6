#include "qstring-rb.hpp"
#include <qstring.h>

using namespace Rice;

Rice::Class rb_cQString;

void Init_QString(Rice::Module rb_mQt6QtCore)
{
    rb_cQString =
        // Qt6::QtCore::QString
        define_class_under<QString>(rb_mQt6QtCore, "QString")
            .define_constructor(Constructor<QString, const char *>(), Arg("str"))
            .define_method("to_std_string", &QString::toStdString);
}
