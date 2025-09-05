#include "qapplication-rb.hpp"
#include <qapplication.h>

#include <QFont>
#include <QPalette>
#include <QStyle>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQApplication;

void Init_qapplication(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQApplication =
        // RubyQt6::QtWidgets::QApplication
        define_class_under<QApplication, QGuiApplication>(rb_mQt6QtWidgets, "QApplication")
            // Constructor
            .define_constructor(Constructor<QApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            // Public Functions
            .define_method("auto_sip_enabled", &QApplication::autoSipEnabled)
            .define_method("style_sheet", &QApplication::styleSheet)
            // Reimplemented Public Functions
            .define_method("notify", &QApplication::notify, Arg(""), Arg(""))
            // Public Slots
            .define_singleton_function("about_qt", &QApplication::aboutQt)
            .define_singleton_function("close_all_windows", &QApplication::closeAllWindows)
            .define_method("set_auto_sip_enabled", &QApplication::setAutoSipEnabled, Arg("enabled"))
            .define_method("set_style_sheet", &QApplication::setStyleSheet, Arg("sheet"))
            // Signals
            .define_method("focus_changed", &QApplication::focusChanged, Arg("old"), Arg("now"))
            // Static Public Members
            .define_singleton_function("active_modal_widget", &QApplication::activeModalWidget)
            .define_singleton_function("active_popup_widget", &QApplication::activePopupWidget)
            .define_singleton_function("active_window", &QApplication::activeWindow)
            .define_singleton_function("alert", &QApplication::alert, Arg("widget"), Arg("duration") = static_cast<int>(0))
            .define_singleton_function("all_widgets", &QApplication::allWidgets)
            .define_singleton_function("beep", &QApplication::beep)
            .define_singleton_function("cursor_flash_time", &QApplication::cursorFlashTime)
            .define_singleton_function("double_click_interval", &QApplication::doubleClickInterval)
            .define_singleton_function("exec", &QApplication::exec)
            .define_singleton_function("focus_widget", &QApplication::focusWidget)
            .define_singleton_function<QFont (*)()>("font", &QApplication::font)
            .define_singleton_function<QFont (*)(const QWidget *)>("font", &QApplication::font, Arg(""))
            .define_singleton_function<QFont (*)(const char *)>("font", &QApplication::font, Arg("class_name"))
            .define_singleton_function("effect_enabled?", &QApplication::isEffectEnabled, Arg(""))
            .define_singleton_function("keyboard_input_interval", &QApplication::keyboardInputInterval)
            .define_singleton_function<QPalette (*)(const QWidget *)>("palette", &QApplication::palette, Arg(""))
            .define_singleton_function<QPalette (*)(const char *)>("palette", &QApplication::palette, Arg("class_name"))
            .define_singleton_function("set_cursor_flash_time", &QApplication::setCursorFlashTime, Arg(""))
            .define_singleton_function("set_double_click_interval", &QApplication::setDoubleClickInterval, Arg(""))
            .define_singleton_function("set_effect_enabled", &QApplication::setEffectEnabled, Arg(""), Arg("enable") = static_cast<bool>(true))
            .define_singleton_function("set_font", &QApplication::setFont, Arg(""), Arg("class_name") = static_cast<const char *>(nullptr))
            .define_singleton_function("set_keyboard_input_interval", &QApplication::setKeyboardInputInterval, Arg(""))
            .define_singleton_function("set_palette", &QApplication::setPalette, Arg(""), Arg("class_name") = static_cast<const char *>(nullptr))
            .define_singleton_function("set_start_drag_distance", &QApplication::setStartDragDistance, Arg("l"))
            .define_singleton_function("set_start_drag_time", &QApplication::setStartDragTime, Arg("ms"))
            .define_singleton_function<QStyle *(*)(const QString &)>("set_style", &QApplication::setStyle, Arg(""))
            .define_singleton_function<void (*)(QStyle *)>("set_style", &QApplication::setStyle, Arg("style").takeOwnership())
            .define_singleton_function("set_wheel_scroll_lines", &QApplication::setWheelScrollLines, Arg(""))
            .define_singleton_function("start_drag_distance", &QApplication::startDragDistance)
            .define_singleton_function("start_drag_time", &QApplication::startDragTime)
            .define_singleton_function("style", &QApplication::style)
            .define_singleton_function<QWidget *(*)(const QPoint &)>("top_level_at", &QApplication::topLevelAt, Arg("p"))
            .define_singleton_function<QWidget *(*)(int, int)>("top_level_at", &QApplication::topLevelAt, Arg("x"), Arg("y"))
            .define_singleton_function("top_level_widgets", &QApplication::topLevelWidgets)
            .define_singleton_function("wheel_scroll_lines", &QApplication::wheelScrollLines)
            .define_singleton_function<QWidget *(*)(const QPoint &)>("widget_at", &QApplication::widgetAt, Arg("p"))
            .define_singleton_function<QWidget *(*)(int, int)>("widget_at", &QApplication::widgetAt, Arg("x"), Arg("y"));
}
