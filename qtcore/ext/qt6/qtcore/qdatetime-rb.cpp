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
        define_class_under<QDateTime>(rb_mQt6QtCore, "QDateTime")
            // Constructor
            .define_constructor(Constructor<QDateTime, QDate, QTime, const QTimeZone &, QDateTime::TransitionResolution>(), Arg("date"), Arg("time"), Arg("time_zone"), Arg("resolve") = static_cast<QDateTime::TransitionResolution>(QDateTime::TransitionResolution::LegacyBehavior))
            .define_constructor(Constructor<QDateTime, QDate, QTime, QDateTime::TransitionResolution>(), Arg("date"), Arg("time"), Arg("resolve") = static_cast<QDateTime::TransitionResolution>(QDateTime::TransitionResolution::LegacyBehavior))
            // Public Functions
            .define_method("add_days", &QDateTime::addDays, Arg("days"))
            .define_method("add_duration", &QDateTime::addDuration, Arg("msecs"))
            .define_method("add_m_secs", &QDateTime::addMSecs, Arg("msecs"))
            .define_method("add_months", &QDateTime::addMonths, Arg("months"))
            .define_method("add_secs", &QDateTime::addSecs, Arg("secs"))
            .define_method("add_years", &QDateTime::addYears, Arg("years"))
            .define_method("date", &QDateTime::date)
            .define_method("days_to", &QDateTime::daysTo, Arg("other"))
            .define_method("daylight_time?", &QDateTime::isDaylightTime)
            .define_method("null?", &QDateTime::isNull)
            .define_method("valid?", &QDateTime::isValid)
            .define_method("msecs_to", &QDateTime::msecsTo, Arg("other"))
            .define_method("offset_from_utc", &QDateTime::offsetFromUtc)
            .define_method("secs_to", &QDateTime::secsTo, Arg("other"))
            .define_method("set_date", &QDateTime::setDate, Arg("date"), Arg("resolve") = static_cast<QDateTime::TransitionResolution>(QDateTime::TransitionResolution::LegacyBehavior))
            .define_method("set_m_secs_since_epoch", &QDateTime::setMSecsSinceEpoch, Arg("msecs"))
            .define_method("set_secs_since_epoch", &QDateTime::setSecsSinceEpoch, Arg("secs"))
            .define_method("set_time", &QDateTime::setTime, Arg("time"), Arg("resolve") = static_cast<QDateTime::TransitionResolution>(QDateTime::TransitionResolution::LegacyBehavior))
            .define_method("set_time_zone", &QDateTime::setTimeZone, Arg("to_zone"), Arg("resolve") = static_cast<QDateTime::TransitionResolution>(QDateTime::TransitionResolution::LegacyBehavior))
            .define_method("swap", &QDateTime::swap, Arg("other"))
            .define_method("time", &QDateTime::time)
            .define_method("time_representation", &QDateTime::timeRepresentation)
            .define_method("time_spec", &QDateTime::timeSpec)
            .define_method("time_zone", &QDateTime::timeZone)
            .define_method("time_zone_abbreviation", &QDateTime::timeZoneAbbreviation)
            .define_method("to_local_time", &QDateTime::toLocalTime)
            .define_method("to_m_secs_since_epoch", &QDateTime::toMSecsSinceEpoch)
            .define_method("to_offset_from_utc", &QDateTime::toOffsetFromUtc, Arg("offset_seconds"))
            .define_method("to_secs_since_epoch", &QDateTime::toSecsSinceEpoch)
            .define_method<QString (QDateTime::*)(Qt::DateFormat) const>("to_string", &QDateTime::toString, Arg("format") = static_cast<Qt::DateFormat>(Qt::TextDate))
            .define_method<QString (QDateTime::*)(const QString &) const>("to_string", &QDateTime::toString, Arg("format"))
            .define_method<QString (QDateTime::*)(const QString &, QCalendar) const>("to_string", &QDateTime::toString, Arg("format"), Arg("cal"))
            .define_method("to_time_zone", &QDateTime::toTimeZone, Arg("to_zone"))
            .define_method("to_utc", &QDateTime::toUTC)
            // Static Public Members
            .define_singleton_function<QDateTime (*)()>("current_date_time", &QDateTime::currentDateTime)
            .define_singleton_function<QDateTime (*)(const QTimeZone &)>("current_date_time", &QDateTime::currentDateTime, Arg("zone"))
            .define_singleton_function("current_date_time_utc", &QDateTime::currentDateTimeUtc)
            // .define_singleton_function("current_m_secs_since_epoch", &QDateTime::currentMSecsSinceEpoch)
            // .define_singleton_function("current_secs_since_epoch", &QDateTime::currentSecsSinceEpoch)
            .define_singleton_function<QDateTime (*)(qint64)>("from_m_secs_since_epoch", &QDateTime::fromMSecsSinceEpoch, Arg("msecs"))
            .define_singleton_function<QDateTime (*)(qint64, const QTimeZone &)>("from_m_secs_since_epoch", &QDateTime::fromMSecsSinceEpoch, Arg("msecs"), Arg("time_zone"))
            .define_singleton_function<QDateTime (*)(qint64)>("from_secs_since_epoch", &QDateTime::fromSecsSinceEpoch, Arg("secs"))
            .define_singleton_function<QDateTime (*)(qint64, const QTimeZone &)>("from_secs_since_epoch", &QDateTime::fromSecsSinceEpoch, Arg("secs"), Arg("time_zone"))
            .define_singleton_function("from_std_time_point", &QDateTime::fromStdTimePoint, Arg("time"))
            .define_singleton_function<QDateTime (*)(const QString &, Qt::DateFormat)>("from_string", &QDateTime::fromString, Arg("string"), Arg("format") = static_cast<Qt::DateFormat>(Qt::TextDate))
            .define_singleton_function<QDateTime (*)(const QString &, const QString &, QCalendar)>("from_string", &QDateTime::fromString, Arg("string"), Arg("format"), Arg("cal"))
            .define_singleton_function<QDateTime (*)(const QString &, const QString &, int)>("from_string", &QDateTime::fromString, Arg("string"), Arg("format"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_singleton_function<QDateTime (*)(const QString &, const QString &, int, QCalendar)>("from_string", &QDateTime::fromString, Arg("string"), Arg("format"), Arg("base_year"), Arg("cal"));

    Enum<QDateTime::TransitionResolution> rb_cQDateTimeTransitionResolution =
        // RubyQt6::QtCore::QDateTime::TransitionResolution
        define_enum_under<QDateTime::TransitionResolution>("TransitionResolution", rb_cQDateTime)
            .define_value("Reject", QDateTime::TransitionResolution::Reject)
            .define_value("RelativeToBefore", QDateTime::TransitionResolution::RelativeToBefore)
            .define_value("RelativeToAfter", QDateTime::TransitionResolution::RelativeToAfter)
            .define_value("PreferBefore", QDateTime::TransitionResolution::PreferBefore)
            .define_value("PreferAfter", QDateTime::TransitionResolution::PreferAfter)
            .define_value("PreferStandard", QDateTime::TransitionResolution::PreferStandard)
            .define_value("PreferDaylightSaving", QDateTime::TransitionResolution::PreferDaylightSaving)
            .define_value("LegacyBehavior", QDateTime::TransitionResolution::LegacyBehavior);

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
