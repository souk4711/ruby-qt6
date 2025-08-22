#include "qvariant-rb.hpp"
#include <qvariant.h>

using namespace Rice;

Rice::Class rb_cQVariant;

void Init_qvariant(Rice::Module rb_mQt6QtCore)
{
    rb_cQVariant =
        // RubyQt6::QtCore::QVariant
        define_class_under<QVariant>(rb_mQt6QtCore, "QVariant")
            .define_constructor(Constructor<QVariant>());
}
