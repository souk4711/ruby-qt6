#include "qapplication-rb.hpp"
#include <qapplication.h>

using namespace Rice;

Rice::Class rb_cQApplication;

void Init_qapplication(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQApplication =
        // RubyQt6::QtWidgets::QApplication
        define_class_under<QApplication, QGuiApplication>(rb_mQt6QtWidgets, "QApplication")
            .define_constructor(Constructor<QApplication, int &, char **>(), Arg("argc") = static_cast<int>(0), Arg("argv") = static_cast<char **>(nullptr))
            .define_singleton_function("_cursor_flash_time", &QApplication::cursorFlashTime)
            .define_singleton_function("_double_click_interval", &QApplication::doubleClickInterval)
            .define_singleton_function("_keyboard_input_interval", &QApplication::keyboardInputInterval)
            .define_singleton_function("_start_drag_distance", &QApplication::startDragDistance)
            .define_singleton_function("_start_drag_time", &QApplication::startDragTime)
            .define_singleton_function("_wheel_scroll_lines", &QApplication::wheelScrollLines)
            .define_singleton_function("_set_cursor_flash_time", &QApplication::setCursorFlashTime, Arg("msec"))
            .define_singleton_function("_set_double_click_interval", &QApplication::setDoubleClickInterval, Arg("msec"))
            .define_singleton_function("_set_keyboard_input_interval", &QApplication::setKeyboardInputInterval, Arg("msec"))
            .define_singleton_function("_set_start_drag_distance", &QApplication::setStartDragDistance, Arg("distance"))
            .define_singleton_function("_set_start_drag_time", &QApplication::setStartDragTime, Arg("msec"))
            .define_singleton_function("_set_wheel_scroll_lines", &QApplication::setWheelScrollLines, Arg("lines"))
            .define_singleton_function("_about_qt", &QApplication::aboutQt)
            .define_singleton_function("_close_all_windows", &QApplication::closeAllWindows)
            .define_singleton_function("_exec", &QApplication::exec)
            .define_method("_auto_sip_enabled?", &QApplication::autoSipEnabled)
            .define_method("_style_sheet", &QApplication::styleSheet)
            .define_method("_set_auto_sip_enabled", &QApplication::setAutoSipEnabled, Arg("enabled"))
            .define_method("_set_style_sheet", &QApplication::setStyleSheet, Arg("style_sheet"));
}
