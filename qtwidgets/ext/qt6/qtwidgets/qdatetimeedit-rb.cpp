#include "qdatetimeedit-rb.hpp"
#include <qdatetimeedit.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QCalendarWidget>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDateTimeEdit;
Class rb_cQDateEdit;
Class rb_cQTimeEdit;

void Init_qdatetimeedit(Module rb_mQt6QtWidgets)
{
    rb_cQDateTimeEdit =
        // RubyQt6::QtWidgets::QDateTimeEdit
        define_qlass_under<QDateTimeEdit, QAbstractSpinBox>(rb_mQt6QtWidgets, "QDateTimeEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QDateTimeEdit * { return qobject_cast<QDateTimeEdit *>(object); })
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
            .define_method("_set_display_format", &QDateTimeEdit::setDisplayFormat, Arg("format"))
            .define_method("set_maximum_date", &QDateTimeEdit::setMaximumDate, Arg("max"))
            .define_method("set_maximum_date_time", &QDateTimeEdit::setMaximumDateTime, Arg("dt"))
            .define_method("set_maximum_time", &QDateTimeEdit::setMaximumTime, Arg("max"))
            .define_method("set_minimum_date", &QDateTimeEdit::setMinimumDate, Arg("min"))
            .define_method("set_minimum_date_time", &QDateTimeEdit::setMinimumDateTime, Arg("dt"))
            .define_method("set_minimum_time", &QDateTimeEdit::setMinimumTime, Arg("min"))
            .define_method("set_selected_section", &QDateTimeEdit::setSelectedSection, Arg("section"))
            .define_method("set_time_range", &QDateTimeEdit::setTimeRange, Arg("min"), Arg("max"))
            .define_method("set_time_zone", &QDateTimeEdit::setTimeZone, Arg("zone"))
            .define_method("step_by", &QDateTimeEdit::stepBy, Arg("steps"))
            .define_method("time", &QDateTimeEdit::time)
            .define_method("time_zone", &QDateTimeEdit::timeZone)
            // Public Slots
            .define_method("set_date", &QDateTimeEdit::setDate, Arg("date"))
            .define_method("set_date_time", &QDateTimeEdit::setDateTime, Arg("date_time"))
            .define_method("set_time", &QDateTimeEdit::setTime, Arg("time"));
            // Signals
            // .define_method("date_changed", &QDateTimeEdit::dateChanged, Arg("date"))
            // .define_method("date_time_changed", &QDateTimeEdit::dateTimeChanged, Arg("date_time"))
            // .define_method("time_changed", &QDateTimeEdit::timeChanged, Arg("time"));

    Data_Type<QDateTimeEdit::Section> rb_cQDateTimeEditSection =
        // RubyQt6::QtWidgets::QDateTimeEdit::Section
        define_qenum_under<QDateTimeEdit::Section>(rb_cQDateTimeEdit, "Section");
        define_qenum_value_under(rb_cQDateTimeEditSection, "NoSection", QDateTimeEdit::Section::NoSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "AmPmSection", QDateTimeEdit::Section::AmPmSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "MSecSection", QDateTimeEdit::Section::MSecSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "SecondSection", QDateTimeEdit::Section::SecondSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "MinuteSection", QDateTimeEdit::Section::MinuteSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "HourSection", QDateTimeEdit::Section::HourSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "DaySection", QDateTimeEdit::Section::DaySection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "MonthSection", QDateTimeEdit::Section::MonthSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "YearSection", QDateTimeEdit::Section::YearSection);
        define_qenum_value_under(rb_cQDateTimeEditSection, "TimeSections_Mask", QDateTimeEdit::Section::TimeSections_Mask);
        define_qenum_value_under(rb_cQDateTimeEditSection, "DateSections_Mask", QDateTimeEdit::Section::DateSections_Mask);

    Data_Type<QFlags<QDateTimeEdit::Section>> rb_cQDateTimeEditSections =
        // RubyQt6::QtWidgets::QDateTimeEdit::Sections
        define_qflags_under<QDateTimeEdit::Section>(rb_cQDateTimeEdit, "Sections");

    rb_cQDateEdit =
        // RubyQt6::QtWidgets::QDateEdit
        define_qlass_under<QDateEdit, QDateTimeEdit>(rb_mQt6QtWidgets, "QDateEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QDateEdit * { return qobject_cast<QDateEdit *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDateEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDateEdit, QDate, QWidget *>(), Arg("date"), Arg("parent"));
            // Signals
            // .define_method("user_date_changed", &QDateEdit::userDateChanged, Arg("date"));

    rb_cQTimeEdit =
        // RubyQt6::QtWidgets::QTimeEdit
        define_qlass_under<QTimeEdit, QDateTimeEdit>(rb_mQt6QtWidgets, "QTimeEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QTimeEdit * { return qobject_cast<QTimeEdit *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTimeEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTimeEdit, QTime, QWidget *>(), Arg("time"), Arg("parent"));
            // Signals
            // .define_method("user_time_changed", &QTimeEdit::userTimeChanged, Arg("time"));
}
