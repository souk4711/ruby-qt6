#include "qdatetime-rb.hpp"
#include <qdatetime.h>

#include <QTimeZone>

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
        define_class_under<QDate>(rb_mQt6QtCore, "QDate")
            // Constructor
            .define_constructor(Constructor<QDate, int, int, int>(), Arg("y"), Arg("m"), Arg("d"))
            // Public Functions
            .define_method("add_days", &QDate::addDays, Arg("days"))
            .define_method<QDate (QDate::*)(int) const>("add_months", &QDate::addMonths, Arg("months"))
            .define_method<QDate (QDate::*)(int, QCalendar) const>("add_months", &QDate::addMonths, Arg("months"), Arg("cal"))
            .define_method<QDate (QDate::*)(int) const>("add_years", &QDate::addYears, Arg("years"))
            .define_method<QDate (QDate::*)(int, QCalendar) const>("add_years", &QDate::addYears, Arg("years"), Arg("cal"))
            .define_method<int (QDate::*)() const>("day", &QDate::day)
            .define_method<int (QDate::*)(QCalendar) const>("day", &QDate::day, Arg("cal"))
            .define_method<int (QDate::*)() const>("day_of_week", &QDate::dayOfWeek)
            .define_method<int (QDate::*)(QCalendar) const>("day_of_week", &QDate::dayOfWeek, Arg("cal"))
            .define_method<int (QDate::*)() const>("day_of_year", &QDate::dayOfYear)
            .define_method<int (QDate::*)(QCalendar) const>("day_of_year", &QDate::dayOfYear, Arg("cal"))
            .define_method<int (QDate::*)() const>("days_in_month", &QDate::daysInMonth)
            .define_method<int (QDate::*)(QCalendar) const>("days_in_month", &QDate::daysInMonth, Arg("cal"))
            .define_method<int (QDate::*)() const>("days_in_year", &QDate::daysInYear)
            .define_method<int (QDate::*)(QCalendar) const>("days_in_year", &QDate::daysInYear, Arg("cal"))
            .define_method("days_to", &QDate::daysTo, Arg("d"))
            .define_method<QDateTime (QDate::*)() const>("end_of_day", &QDate::endOfDay)
            .define_method<QDateTime (QDate::*)(const QTimeZone &) const>("end_of_day", &QDate::endOfDay, Arg("zone"))
            .define_method("get_date", &QDate::getDate, Arg("year"), Arg("month"), Arg("day"))
            .define_method("null?", &QDate::isNull)
            .define_method<bool (QDate::*)() const>("valid?", &QDate::isValid)
            .define_method<int (QDate::*)() const>("month", &QDate::month)
            .define_method<int (QDate::*)(QCalendar) const>("month", &QDate::month, Arg("cal"))
            .define_method<bool (QDate::*)(int, int, int)>("set_date", &QDate::setDate, Arg("year"), Arg("month"), Arg("day"))
            .define_method<bool (QDate::*)(int, int, int, QCalendar)>("set_date", &QDate::setDate, Arg("year"), Arg("month"), Arg("day"), Arg("cal"))
            .define_method<QDateTime (QDate::*)() const>("start_of_day", &QDate::startOfDay)
            .define_method<QDateTime (QDate::*)(const QTimeZone &) const>("start_of_day", &QDate::startOfDay, Arg("zone"))
            .define_method("to_julian_day", &QDate::toJulianDay)
            .define_method<QString (QDate::*)(Qt::DateFormat) const>("to_string", &QDate::toString, Arg("format") = static_cast<Qt::DateFormat>(Qt::TextDate))
            .define_method<QString (QDate::*)(const QString &) const>("to_string", &QDate::toString, Arg("format"))
            .define_method<QString (QDate::*)(const QString &, QCalendar) const>("to_string", &QDate::toString, Arg("format"), Arg("cal"))
            .define_method("week_number", &QDate::weekNumber, Arg("year_num") = static_cast<int *>(nullptr))
            .define_method<int (QDate::*)() const>("year", &QDate::year)
            .define_method<int (QDate::*)(QCalendar) const>("year", &QDate::year, Arg("cal"))
            // Static Public Members
            .define_singleton_function("current_date", &QDate::currentDate)
            .define_singleton_function("from_julian_day", &QDate::fromJulianDay, Arg("jd_"))
            .define_singleton_function<QDate (*)(const QString &, Qt::DateFormat)>("from_string", &QDate::fromString, Arg("string"), Arg("format") = static_cast<Qt::DateFormat>(Qt::TextDate))
            .define_singleton_function<QDate (*)(const QString &, const QString &, QCalendar)>("from_string", &QDate::fromString, Arg("string"), Arg("format"), Arg("cal"))
            .define_singleton_function<QDate (*)(const QString &, const QString &, int)>("from_string", &QDate::fromString, Arg("string"), Arg("format"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_singleton_function<QDate (*)(const QString &, const QString &, int, QCalendar)>("from_string", &QDate::fromString, Arg("string"), Arg("format"), Arg("base_year"), Arg("cal"))
            .define_singleton_function("leap_year?", &QDate::isLeapYear, Arg("year"))
            .define_singleton_function<bool (*)(int, int, int)>("valid?", &QDate::isValid, Arg("y"), Arg("m"), Arg("d"));

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
