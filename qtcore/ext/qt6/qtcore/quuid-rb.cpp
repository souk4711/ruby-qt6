#include "quuid-rb.hpp"
#include <quuid.h>

using namespace Rice;

Rice::Class rb_cQUuid;

void Init_quuid(Rice::Module rb_mQt6QtCore)
{
    rb_cQUuid =
        // RubyQt6::QtCore::QUuid
        define_class_under<QUuid>(rb_mQt6QtCore, "QUuid");
}
