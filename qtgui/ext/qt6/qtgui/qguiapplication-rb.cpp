#include "qguiapplication-rb.hpp"
#include <qguiapplication.h>

#include <QClipboard>
#include <QCursor>
#include <QFont>
#include <QIcon>
#include <QPalette>
#include <QScreen>
#include <QSessionManager>
#include <QStyleHints>
#include <QWindow>

using namespace Rice;

Rice::Class rb_cQGuiApplication;

void Init_qguiapplication(Rice::Module rb_mQt6QtGui)
{
    rb_cQGuiApplication =
        // RubyQt6::QtGui::QGuiApplication
        define_class_under<QGuiApplication, QCoreApplication>(rb_mQt6QtGui, "QGuiApplication")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGuiApplication::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QGuiApplication, int &, char **>(), Arg("argc"), ArgBuffer("argv"))
            // Public Functions
            .define_method("device_pixel_ratio", &QGuiApplication::devicePixelRatio)
            .define_method("notify", &QGuiApplication::notify, Arg("receiver"), Arg("event"))
            .define_method("saving_session?", &QGuiApplication::isSavingSession)
            .define_method("session_restored?", &QGuiApplication::isSessionRestored)
            .define_method("session_id", &QGuiApplication::sessionId)
            .define_method("session_key", &QGuiApplication::sessionKey)
            // Public Slots
            .define_method("set_badge_number", &QGuiApplication::setBadgeNumber, Arg("number"))
            // Signals
            .define_method("application_display_name_changed", &QGuiApplication::applicationDisplayNameChanged)
            .define_method("application_state_changed", &QGuiApplication::applicationStateChanged, Arg("state"))
            .define_method("commit_data_request", &QGuiApplication::commitDataRequest, Arg("session_manager"))
            .define_method("focus_object_changed", &QGuiApplication::focusObjectChanged, Arg("focus_object"))
            .define_method("focus_window_changed", &QGuiApplication::focusWindowChanged, Arg("focus_window"))
            .define_method("font_database_changed", &QGuiApplication::fontDatabaseChanged)
            .define_method("last_window_closed", &QGuiApplication::lastWindowClosed)
            .define_method("layout_direction_changed", &QGuiApplication::layoutDirectionChanged, Arg("direction"))
            .define_method("primary_screen_changed", &QGuiApplication::primaryScreenChanged, Arg("screen"))
            .define_method("save_state_request", &QGuiApplication::saveStateRequest, Arg("session_manager"))
            .define_method("screen_added", &QGuiApplication::screenAdded, Arg("screen"))
            .define_method("screen_removed", &QGuiApplication::screenRemoved, Arg("screen"))
            // Static Public Members
            .define_singleton_function("all_windows", &QGuiApplication::allWindows)
            .define_singleton_function("application_display_name", &QGuiApplication::applicationDisplayName)
            .define_singleton_function("application_state", &QGuiApplication::applicationState)
            .define_singleton_function("change_override_cursor", &QGuiApplication::changeOverrideCursor, Arg("cursor"))
            .define_singleton_function("clipboard", &QGuiApplication::clipboard)
            .define_singleton_function("desktop_file_name", &QGuiApplication::desktopFileName)
            .define_singleton_function("desktop_settings_aware", &QGuiApplication::desktopSettingsAware)
            .define_singleton_function("exec", &QGuiApplication::exec)
            .define_singleton_function("focus_object", &QGuiApplication::focusObject)
            .define_singleton_function("focus_window", &QGuiApplication::focusWindow)
            .define_singleton_function("font", &QGuiApplication::font)
            .define_singleton_function("high_dpi_scale_factor_rounding_policy", &QGuiApplication::highDpiScaleFactorRoundingPolicy)
            .define_singleton_function("input_method", &QGuiApplication::inputMethod)
            .define_singleton_function("left_to_right?", &QGuiApplication::isLeftToRight)
            .define_singleton_function("right_to_left?", &QGuiApplication::isRightToLeft)
            .define_singleton_function("keyboard_modifiers", &QGuiApplication::keyboardModifiers)
            .define_singleton_function("layout_direction", &QGuiApplication::layoutDirection)
            .define_singleton_function("modal_window", &QGuiApplication::modalWindow)
            .define_singleton_function("mouse_buttons", &QGuiApplication::mouseButtons)
            .define_singleton_function("override_cursor", &QGuiApplication::overrideCursor)
            .define_singleton_function("platform_name", &QGuiApplication::platformName)
            .define_singleton_function("primary_screen", &QGuiApplication::primaryScreen)
            .define_singleton_function("query_keyboard_modifiers", &QGuiApplication::queryKeyboardModifiers)
            .define_singleton_function("quit_on_last_window_closed", &QGuiApplication::quitOnLastWindowClosed)
            .define_singleton_function("restore_override_cursor", &QGuiApplication::restoreOverrideCursor)
            .define_singleton_function("screen_at", &QGuiApplication::screenAt, Arg("point"))
            .define_singleton_function("screens", &QGuiApplication::screens)
            .define_singleton_function("set_application_display_name", &QGuiApplication::setApplicationDisplayName, Arg("name"))
            .define_singleton_function("set_desktop_file_name", &QGuiApplication::setDesktopFileName, Arg("name"))
            .define_singleton_function("set_desktop_settings_aware", &QGuiApplication::setDesktopSettingsAware, Arg("on"))
            .define_singleton_function("set_font", &QGuiApplication::setFont, Arg("font"))
            .define_singleton_function("set_high_dpi_scale_factor_rounding_policy", &QGuiApplication::setHighDpiScaleFactorRoundingPolicy, Arg("policy"))
            .define_singleton_function("set_layout_direction", &QGuiApplication::setLayoutDirection, Arg("direction"))
            .define_singleton_function("set_override_cursor", &QGuiApplication::setOverrideCursor, Arg("cursor"))
            .define_singleton_function("set_palette", &QGuiApplication::setPalette, Arg("pal"))
            .define_singleton_function("set_quit_on_last_window_closed", &QGuiApplication::setQuitOnLastWindowClosed, Arg("quit"))
            .define_singleton_function("set_window_icon", &QGuiApplication::setWindowIcon, Arg("icon"))
            .define_singleton_function("style_hints", &QGuiApplication::styleHints)
            .define_singleton_function("sync", &QGuiApplication::sync)
            .define_singleton_function("top_level_at", &QGuiApplication::topLevelAt, Arg("pos"))
            .define_singleton_function("top_level_windows", &QGuiApplication::topLevelWindows)
            .define_singleton_function("window_icon", &QGuiApplication::windowIcon);
}
