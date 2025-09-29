#include "qdatetimeedit-rb.hpp"
#include <qdatetimeedit.h>

#include <QCalendarWidget>

using namespace Rice;

Rice::Class rb_cQDateTimeEdit;
Rice::Class rb_cQDateEdit;
Rice::Class rb_cQTimeEdit;

void Init_qdatetimeedit(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQDateTimeEdit =
        // RubyQt6::QtWidgets::QDateTimeEdit
        define_class_under<QDateTimeEdit, QAbstractSpinBox>(rb_mQt6QtWidgets, "QDateTimeEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDateTimeEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDateTimeEdit, const QDateTime &, QWidget *>(), Arg("datetime"), Arg("parent"))
            // Public Functions
            .define_method("calendar", &QDateTimeEdit::calendar)
            .define_method("calendar_popup", &QDateTimeEdit::calendarPopup)
            .define_method("calendar_widget", &QDateTimeEdit::calendarWidget)
            .define_method("clear", &QDateTimeEdit::clear)
            .define_method("clear_maximum_date", &QDateTimeEdit::clearMaximumDate)
            .define_method("clear_maximum_date_time", &QDateTimeEdit::clearMaximumDateTime)
            .define_method("clear_maximum_time", &QDateTimeEdit::clearMaximumTime)
            .define_method("clear_minimum_date", &QDateTimeEdit::clearMinimumDate)
            .define_method("clear_minimum_date_time", &QDateTimeEdit::clearMinimumDateTime)
            .define_method("clear_minimum_time", &QDateTimeEdit::clearMinimumTime)
            .define_method("current_section", &QDateTimeEdit::currentSection)
            .define_method("current_section_index", &QDateTimeEdit::currentSectionIndex)
            .define_method("date", &QDateTimeEdit::date)
            .define_method("date_time", &QDateTimeEdit::dateTime)
            .define_method("display_format", &QDateTimeEdit::displayFormat)
            .define_method("displayed_sections", &QDateTimeEdit::displayedSections)
            .define_method("maximum_date", &QDateTimeEdit::maximumDate)
            .define_method("maximum_date_time", &QDateTimeEdit::maximumDateTime)
            .define_method("maximum_time", &QDateTimeEdit::maximumTime)
            .define_method("minimum_date", &QDateTimeEdit::minimumDate)
            .define_method("minimum_date_time", &QDateTimeEdit::minimumDateTime)
            .define_method("minimum_time", &QDateTimeEdit::minimumTime)
            .define_method("section_at", &QDateTimeEdit::sectionAt, Arg("index"))
            .define_method("section_count", &QDateTimeEdit::sectionCount)
            .define_method("section_text", &QDateTimeEdit::sectionText, Arg("section"))
            .define_method("set_calendar", &QDateTimeEdit::setCalendar, Arg("calendar"))
            .define_method("set_calendar_popup", &QDateTimeEdit::setCalendarPopup, Arg("enable"))
            .define_method("set_calendar_widget", &QDateTimeEdit::setCalendarWidget, Arg("calendar_widget"))
            .define_method("set_current_section", &QDateTimeEdit::setCurrentSection, Arg("section"))
            .define_method("set_current_section_index", &QDateTimeEdit::setCurrentSectionIndex, Arg("index"))
            .define_method("set_date_range", &QDateTimeEdit::setDateRange, Arg("min"), Arg("max"))
            .define_method("set_date_time_range", &QDateTimeEdit::setDateTimeRange, Arg("min"), Arg("max"))
            .define_method("set_display_format", &QDateTimeEdit::setDisplayFormat, Arg("format"))
            .define_method("set_maximum_date", &QDateTimeEdit::setMaximumDate, Arg("max"))
            .define_method("set_maximum_date_time", &QDateTimeEdit::setMaximumDateTime, Arg("dt"))
            .define_method("set_maximum_time", &QDateTimeEdit::setMaximumTime, Arg("max"))
            .define_method("set_minimum_date", &QDateTimeEdit::setMinimumDate, Arg("min"))
            .define_method("set_minimum_date_time", &QDateTimeEdit::setMinimumDateTime, Arg("dt"))
            .define_method("set_minimum_time", &QDateTimeEdit::setMinimumTime, Arg("min"))
            .define_method("set_selected_section", &QDateTimeEdit::setSelectedSection, Arg("section"))
            .define_method("set_time_range", &QDateTimeEdit::setTimeRange, Arg("min"), Arg("max"))
            .define_method("set_time_zone", &QDateTimeEdit::setTimeZone, Arg("zone"))
            .define_method("size_hint", &QDateTimeEdit::sizeHint)
            .define_method("step_by", &QDateTimeEdit::stepBy, Arg("steps"))
            .define_method("time", &QDateTimeEdit::time)
            .define_method("time_zone", &QDateTimeEdit::timeZone)
            // Public Slots
            .define_method("set_date", &QDateTimeEdit::setDate, Arg("date"))
            .define_method("set_date_time", &QDateTimeEdit::setDateTime, Arg("date_time"))
            .define_method("set_time", &QDateTimeEdit::setTime, Arg("time"))
            // Signals
            .define_method("date_changed", &QDateTimeEdit::dateChanged, Arg("date"))
            .define_method("date_time_changed", &QDateTimeEdit::dateTimeChanged, Arg("date_time"))
            .define_method("time_changed", &QDateTimeEdit::timeChanged, Arg("time"));

    Enum<QDateTimeEdit::Section> rb_cQDateTimeEditSection =
        // RubyQt6::QtWidgets::QDateTimeEdit::Section
        define_enum_under<QDateTimeEdit::Section>("Section", rb_cQDateTimeEdit)
            .define_value("NoSection", QDateTimeEdit::Section::NoSection)
            .define_value("AmPmSection", QDateTimeEdit::Section::AmPmSection)
            .define_value("MSecSection", QDateTimeEdit::Section::MSecSection)
            .define_value("SecondSection", QDateTimeEdit::Section::SecondSection)
            .define_value("MinuteSection", QDateTimeEdit::Section::MinuteSection)
            .define_value("HourSection", QDateTimeEdit::Section::HourSection)
            .define_value("DaySection", QDateTimeEdit::Section::DaySection)
            .define_value("MonthSection", QDateTimeEdit::Section::MonthSection)
            .define_value("YearSection", QDateTimeEdit::Section::YearSection)
            .define_value("TimeSections_Mask", QDateTimeEdit::Section::TimeSections_Mask)
            .define_value("DateSections_Mask", QDateTimeEdit::Section::DateSections_Mask);

    rb_cQDateEdit =
        // RubyQt6::QtWidgets::QDateEdit
        define_class_under<QDateEdit, QDateTimeEdit>(rb_mQt6QtWidgets, "QDateEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDateEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDateEdit, QDate, QWidget *>(), Arg("date"), Arg("parent"))
            // Signals
            .define_method("user_date_changed", &QDateEdit::userDateChanged, Arg("date"));

    rb_cQTimeEdit =
        // RubyQt6::QtWidgets::QTimeEdit
        define_class_under<QTimeEdit, QDateTimeEdit>(rb_mQt6QtWidgets, "QTimeEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTimeEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTimeEdit, QTime, QWidget *>(), Arg("time"), Arg("parent"))
            // Signals
            .define_method("user_time_changed", &QTimeEdit::userTimeChanged, Arg("time"));
}
