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
        define_class_under<QTime>(rb_mQt6QtCore, "QTime")
            // Constructor
            .define_constructor(Constructor<QTime, int, int, int, int>(), Arg("h"), Arg("m"), Arg("s") = static_cast<int>(0), Arg("ms") = static_cast<int>(0))
            // Public Functions
            .define_method("add_m_secs", &QTime::addMSecs, Arg("ms"))
            .define_method("add_secs", &QTime::addSecs, Arg("secs"))
            .define_method("hour", &QTime::hour)
            .define_method("null?", &QTime::isNull)
            .define_method<bool (QTime::*)() const>("valid?", &QTime::isValid)
            .define_method("minute", &QTime::minute)
            .define_method("msec", &QTime::msec)
            .define_method("msecs_since_start_of_day", &QTime::msecsSinceStartOfDay)
            .define_method("msecs_to", &QTime::msecsTo, Arg("t"))
            .define_method("second", &QTime::second)
            .define_method("secs_to", &QTime::secsTo, Arg("t"))
            .define_method("set_hms", &QTime::setHMS, Arg("h"), Arg("m"), Arg("s"), Arg("ms") = static_cast<int>(0))
            .define_method<QString (QTime::*)(Qt::DateFormat) const>("to_string", &QTime::toString, Arg("f") = static_cast<Qt::DateFormat>(Qt::TextDate))
            .define_method<QString (QTime::*)(const QString &) const>("to_string", &QTime::toString, Arg("format"))
            // Static Public Members
            .define_singleton_function("current_time", &QTime::currentTime)
            .define_singleton_function("from_m_secs_since_start_of_day", &QTime::fromMSecsSinceStartOfDay, Arg("msecs"))
            .define_singleton_function<QTime (*)(const QString &, Qt::DateFormat)>("from_string", &QTime::fromString, Arg("string"), Arg("format") = static_cast<Qt::DateFormat>(Qt::TextDate))
            .define_singleton_function<QTime (*)(const QString &, const QString &)>("from_string", &QTime::fromString, Arg("string"), Arg("format"))
            .define_singleton_function<bool (*)(int, int, int, int)>("valid?", &QTime::isValid, Arg("h"), Arg("m"), Arg("s"), Arg("ms") = static_cast<int>(0));
}
