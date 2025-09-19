#include "qdatetime-rb.hpp"
#include <qdatetime.h>

using namespace Rice;

Rice::Class rb_cQDateTime;

void Init_qdatetime(Rice::Module rb_mQt6QtCore)
{
    rb_cQDateTime =
        // RubyQt6::QtCore::QDateTime
        define_class_under<QDateTime>(rb_mQt6QtCore, "QDateTime");
}
