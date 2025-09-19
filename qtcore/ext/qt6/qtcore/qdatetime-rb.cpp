#include "qdatetime-rb.hpp"
#include <qdatetime.h>

using namespace Rice;

Rice::Class rb_cQDateTime;
Rice::Class rb_cQDate;
Rice::Class rb_cQTime;

void Init_qdatetime(Rice::Module rb_mQt6QtCore)
{
    rb_cQDateTime =
        // RubyQt6::QtCore::QDateTime
        define_class_under<QDateTime>(rb_mQt6QtCore, "QDateTime");

    rb_cQDate =
        // RubyQt6::QtCore::QDate
        define_class_under<QDate>(rb_mQt6QtCore, "QDate");

    rb_cQTime =
        // RubyQt6::QtCore::QTime
        define_class_under<QTime>(rb_mQt6QtCore, "QTime");
}
