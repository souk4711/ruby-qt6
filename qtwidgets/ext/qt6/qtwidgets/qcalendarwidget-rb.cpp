#include "qcalendarwidget-rb.hpp"
#include <qcalendarwidget.h>

#include <QTextCharFormat>

using namespace Rice;

Rice::Class rb_cQCalendarWidget;

void Init_qcalendarwidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQCalendarWidget =
        // RubyQt6::QtWidgets::QCalendarWidget
        define_class_under<QCalendarWidget, QWidget>(rb_mQt6QtWidgets, "QCalendarWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QCalendarWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QCalendarWidget, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("calendar", &QCalendarWidget::calendar)
            .define_method("clear_maximum_date", &QCalendarWidget::clearMaximumDate)
            .define_method("clear_minimum_date", &QCalendarWidget::clearMinimumDate)
            .define_method("date_edit_accept_delay", &QCalendarWidget::dateEditAcceptDelay)
            .define_method<QMap<QDate, QTextCharFormat> (QCalendarWidget::*)() const>("date_text_format", &QCalendarWidget::dateTextFormat)
            .define_method<QTextCharFormat (QCalendarWidget::*)(QDate) const>("date_text_format", &QCalendarWidget::dateTextFormat, Arg("date"))
            .define_method("first_day_of_week", &QCalendarWidget::firstDayOfWeek)
            .define_method("header_text_format", &QCalendarWidget::headerTextFormat)
            .define_method("horizontal_header_format", &QCalendarWidget::horizontalHeaderFormat)
            .define_method("date_edit_enabled?", &QCalendarWidget::isDateEditEnabled)
            .define_method("grid_visible?", &QCalendarWidget::isGridVisible)
            .define_method("navigation_bar_visible?", &QCalendarWidget::isNavigationBarVisible)
            .define_method("maximum_date", &QCalendarWidget::maximumDate)
            .define_method("minimum_date", &QCalendarWidget::minimumDate)
            .define_method("month_shown", &QCalendarWidget::monthShown)
            .define_method("selected_date", &QCalendarWidget::selectedDate)
            .define_method("selection_mode", &QCalendarWidget::selectionMode)
            .define_method("set_calendar", &QCalendarWidget::setCalendar, Arg("calendar"))
            .define_method("set_date_edit_accept_delay", &QCalendarWidget::setDateEditAcceptDelay, Arg("delay"))
            .define_method("set_date_edit_enabled", &QCalendarWidget::setDateEditEnabled, Arg("enable"))
            .define_method("set_date_text_format", &QCalendarWidget::setDateTextFormat, Arg("date"), Arg("format"))
            .define_method("set_first_day_of_week", &QCalendarWidget::setFirstDayOfWeek, Arg("day_of_week"))
            .define_method("set_header_text_format", &QCalendarWidget::setHeaderTextFormat, Arg("format"))
            .define_method("set_horizontal_header_format", &QCalendarWidget::setHorizontalHeaderFormat, Arg("format"))
            .define_method("set_maximum_date", &QCalendarWidget::setMaximumDate, Arg("date"))
            .define_method("set_minimum_date", &QCalendarWidget::setMinimumDate, Arg("date"))
            .define_method("set_selection_mode", &QCalendarWidget::setSelectionMode, Arg("mode"))
            .define_method("set_vertical_header_format", &QCalendarWidget::setVerticalHeaderFormat, Arg("format"))
            .define_method("set_weekday_text_format", &QCalendarWidget::setWeekdayTextFormat, Arg("day_of_week"), Arg("format"))
            .define_method("vertical_header_format", &QCalendarWidget::verticalHeaderFormat)
            .define_method("weekday_text_format", &QCalendarWidget::weekdayTextFormat, Arg("day_of_week"))
            .define_method("year_shown", &QCalendarWidget::yearShown)
            // Public Slots
            .define_method("set_current_page", &QCalendarWidget::setCurrentPage, Arg("year"), Arg("month"))
            .define_method("set_date_range", &QCalendarWidget::setDateRange, Arg("min"), Arg("max"))
            .define_method("set_grid_visible", &QCalendarWidget::setGridVisible, Arg("show"))
            .define_method("set_navigation_bar_visible", &QCalendarWidget::setNavigationBarVisible, Arg("visible"))
            .define_method("set_selected_date", &QCalendarWidget::setSelectedDate, Arg("date"))
            .define_method("show_next_month", &QCalendarWidget::showNextMonth)
            .define_method("show_next_year", &QCalendarWidget::showNextYear)
            .define_method("show_previous_month", &QCalendarWidget::showPreviousMonth)
            .define_method("show_previous_year", &QCalendarWidget::showPreviousYear)
            .define_method("show_selected_date", &QCalendarWidget::showSelectedDate)
            .define_method("show_today", &QCalendarWidget::showToday)
            // Signals
            .define_method("activated", &QCalendarWidget::activated, Arg("date"))
            .define_method("clicked", &QCalendarWidget::clicked, Arg("date"))
            .define_method("current_page_changed", &QCalendarWidget::currentPageChanged, Arg("year"), Arg("month"))
            .define_method("selection_changed", &QCalendarWidget::selectionChanged);

    Enum<QCalendarWidget::HorizontalHeaderFormat> rb_cQCalendarWidgetHorizontalHeaderFormat =
        // RubyQt6::QtWidgets::QCalendarWidget::HorizontalHeaderFormat
        define_enum_under<QCalendarWidget::HorizontalHeaderFormat>("HorizontalHeaderFormat", rb_cQCalendarWidget)
            .define_value("NoHorizontalHeader", QCalendarWidget::HorizontalHeaderFormat::NoHorizontalHeader)
            .define_value("SingleLetterDayNames", QCalendarWidget::HorizontalHeaderFormat::SingleLetterDayNames)
            .define_value("ShortDayNames", QCalendarWidget::HorizontalHeaderFormat::ShortDayNames)
            .define_value("LongDayNames", QCalendarWidget::HorizontalHeaderFormat::LongDayNames);

    Enum<QCalendarWidget::VerticalHeaderFormat> rb_cQCalendarWidgetVerticalHeaderFormat =
        // RubyQt6::QtWidgets::QCalendarWidget::VerticalHeaderFormat
        define_enum_under<QCalendarWidget::VerticalHeaderFormat>("VerticalHeaderFormat", rb_cQCalendarWidget)
            .define_value("NoVerticalHeader", QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader)
            .define_value("ISOWeekNumbers", QCalendarWidget::VerticalHeaderFormat::ISOWeekNumbers);

    Enum<QCalendarWidget::SelectionMode> rb_cQCalendarWidgetSelectionMode =
        // RubyQt6::QtWidgets::QCalendarWidget::SelectionMode
        define_enum_under<QCalendarWidget::SelectionMode>("SelectionMode", rb_cQCalendarWidget)
            .define_value("NoSelection", QCalendarWidget::SelectionMode::NoSelection)
            .define_value("SingleSelection", QCalendarWidget::SelectionMode::SingleSelection);
}
