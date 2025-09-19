#include "qtime-rb.hpp"
#include <qdatetime.h>

using namespace Rice;

Rice::Class rb_cQTime;

void Init_qtime(Rice::Module rb_mQt6QtCore)
{
    rb_cQTime =
        // RubyQt6::QtCore::QTime
        define_class_under<QTime>(rb_mQt6QtCore, "QTime");
}
