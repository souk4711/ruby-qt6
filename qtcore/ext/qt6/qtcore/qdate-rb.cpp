#include "qdate-rb.hpp"
#include <qdatetime.h>

using namespace Rice;

Rice::Class rb_cQDate;

void Init_qdate(Rice::Module rb_mQt6QtCore)
{
    rb_cQDate =
        // RubyQt6::QtCore::QDate
        define_class_under<QDate>(rb_mQt6QtCore, "QDate");
}
