#include "qstylehints-rb.hpp"
#include <qstylehints.h>

#include <QAccessibilityHints>

using namespace Rice;

Rice::Class rb_cQStyleHints;

void Init_qstylehints(Rice::Module rb_mQt6QtGui)
{
    rb_cQStyleHints =
        // RubyQt6::QtGui::QStyleHints
        define_class_under<QStyleHints, QObject>(rb_mQt6QtGui, "QStyleHints")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QStyleHints::staticMetaObject; })
            // Public Functions
            .define_method("accessibility", &QStyleHints::accessibility)
            .define_method("color_scheme", &QStyleHints::colorScheme)
            .define_method("context_menu_trigger", &QStyleHints::contextMenuTrigger)
            .define_method("cursor_flash_time", &QStyleHints::cursorFlashTime)
            .define_method("font_smoothing_gamma", &QStyleHints::fontSmoothingGamma)
            .define_method("keyboard_auto_repeat_rate_f", &QStyleHints::keyboardAutoRepeatRateF)
            .define_method("keyboard_input_interval", &QStyleHints::keyboardInputInterval)
            .define_method("menu_selection_wraps", &QStyleHints::menuSelectionWraps)
            .define_method("mouse_double_click_distance", &QStyleHints::mouseDoubleClickDistance)
            .define_method("mouse_double_click_interval", &QStyleHints::mouseDoubleClickInterval)
            .define_method("mouse_press_and_hold_interval", &QStyleHints::mousePressAndHoldInterval)
            .define_method("mouse_quick_selection_threshold", &QStyleHints::mouseQuickSelectionThreshold)
            .define_method("password_mask_character", &QStyleHints::passwordMaskCharacter)
            .define_method("password_mask_delay", &QStyleHints::passwordMaskDelay)
            .define_method("set_color_scheme", &QStyleHints::setColorScheme, Arg("scheme"))
            .define_method("set_context_menu_trigger", &QStyleHints::setContextMenuTrigger, Arg("context_menu_trigger"))
            .define_method("set_cursor_flash_time", &QStyleHints::setCursorFlashTime, Arg("cursor_flash_time"))
            .define_method("set_focus_on_touch_release", &QStyleHints::setFocusOnTouchRelease)
            .define_method("set_keyboard_input_interval", &QStyleHints::setKeyboardInputInterval, Arg("keyboard_input_interval"))
            .define_method("set_mouse_double_click_interval", &QStyleHints::setMouseDoubleClickInterval, Arg("mouse_double_click_interval"))
            .define_method("set_mouse_press_and_hold_interval", &QStyleHints::setMousePressAndHoldInterval, Arg("mouse_press_and_hold_interval"))
            .define_method("set_mouse_quick_selection_threshold", &QStyleHints::setMouseQuickSelectionThreshold, Arg("threshold"))
            .define_method("set_show_shortcuts_in_context_menus", &QStyleHints::setShowShortcutsInContextMenus, Arg("show_shortcuts_in_context_menus"))
            .define_method("set_start_drag_distance", &QStyleHints::setStartDragDistance, Arg("start_drag_distance"))
            .define_method("set_start_drag_time", &QStyleHints::setStartDragTime, Arg("start_drag_time"))
            .define_method("set_tab_focus_behavior", &QStyleHints::setTabFocusBehavior, Arg("tab_focus_behavior"))
            .define_method("set_use_hover_effects", &QStyleHints::setUseHoverEffects, Arg("use_hover_effects"))
            .define_method("set_wheel_scroll_lines", &QStyleHints::setWheelScrollLines, Arg("scroll_lines"))
            .define_method("show_is_full_screen", &QStyleHints::showIsFullScreen)
            .define_method("show_is_maximized", &QStyleHints::showIsMaximized)
            .define_method("show_shortcuts_in_context_menus", &QStyleHints::showShortcutsInContextMenus)
            .define_method("single_click_activation", &QStyleHints::singleClickActivation)
            .define_method("start_drag_distance", &QStyleHints::startDragDistance)
            .define_method("start_drag_time", &QStyleHints::startDragTime)
            .define_method("start_drag_velocity", &QStyleHints::startDragVelocity)
            .define_method("tab_focus_behavior", &QStyleHints::tabFocusBehavior)
            .define_method("touch_double_tap_distance", &QStyleHints::touchDoubleTapDistance)
            .define_method("unset_color_scheme", &QStyleHints::unsetColorScheme)
            .define_method("use_hover_effects", &QStyleHints::useHoverEffects)
            .define_method("use_rtl_extensions", &QStyleHints::useRtlExtensions)
            .define_method("wheel_scroll_lines", &QStyleHints::wheelScrollLines)
            // Signals
            .define_method("color_scheme_changed", &QStyleHints::colorSchemeChanged, Arg("color_scheme"))
            .define_method("context_menu_trigger_changed", &QStyleHints::contextMenuTriggerChanged, Arg("context_menu_trigger"))
            .define_method("cursor_flash_time_changed", &QStyleHints::cursorFlashTimeChanged, Arg("cursor_flash_time"))
            .define_method("keyboard_input_interval_changed", &QStyleHints::keyboardInputIntervalChanged, Arg("keyboard_input_interval"))
            .define_method("mouse_double_click_interval_changed", &QStyleHints::mouseDoubleClickIntervalChanged, Arg("mouse_double_click_interval"))
            .define_method("mouse_press_and_hold_interval_changed", &QStyleHints::mousePressAndHoldIntervalChanged, Arg("mouse_press_and_hold_interval"))
            .define_method("mouse_quick_selection_threshold_changed", &QStyleHints::mouseQuickSelectionThresholdChanged, Arg("threshold"))
            .define_method("show_shortcuts_in_context_menus_changed", &QStyleHints::showShortcutsInContextMenusChanged, Arg("show_shortcuts_in_context_menus"))
            .define_method("start_drag_distance_changed", &QStyleHints::startDragDistanceChanged, Arg("start_drag_distance"))
            .define_method("start_drag_time_changed", &QStyleHints::startDragTimeChanged, Arg("start_drag_time"))
            .define_method("tab_focus_behavior_changed", &QStyleHints::tabFocusBehaviorChanged, Arg("tab_focus_behavior"))
            .define_method("use_hover_effects_changed", &QStyleHints::useHoverEffectsChanged, Arg("use_hover_effects"))
            .define_method("wheel_scroll_lines_changed", &QStyleHints::wheelScrollLinesChanged, Arg("scroll_lines"));
}
