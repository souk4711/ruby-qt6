#include "qtoolbutton-rb.hpp"
#include <qtoolbutton.h>
#include <rice/qt6/qenum.hpp>

#include <QMenu>

using namespace Rice;

Rice::Class rb_cQToolButton;

void Init_qtoolbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQToolButton =
        // RubyQt6::QtWidgets::QToolButton
        define_class_under<QToolButton, QAbstractButton>(rb_mQt6QtWidgets, "QToolButton")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QToolButton::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QToolButton, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("arrow_type", &QToolButton::arrowType)
            .define_method("auto_raise", &QToolButton::autoRaise)
            .define_method("default_action", &QToolButton::defaultAction)
            .define_method("menu", &QToolButton::menu)
            .define_method("popup_mode", &QToolButton::popupMode)
            .define_method("set_arrow_type", &QToolButton::setArrowType, Arg("type"))
            .define_method("set_auto_raise", &QToolButton::setAutoRaise, Arg("enable"))
            .define_method("set_menu", &QToolButton::setMenu, Arg("menu"))
            .define_method("set_popup_mode", &QToolButton::setPopupMode, Arg("mode"))
            .define_method("tool_button_style", &QToolButton::toolButtonStyle)
            // Public Slots
            .define_method("set_default_action", &QToolButton::setDefaultAction, Arg("action"))
            .define_method("set_tool_button_style", &QToolButton::setToolButtonStyle, Arg("style"))
            .define_method("show_menu", &QToolButton::showMenu);
            // Signals
            // .define_method("triggered", &QToolButton::triggered, Arg("action"));

    Data_Type<QToolButton::ToolButtonPopupMode> rb_cQToolButtonToolButtonPopupMode =
        // RubyQt6::QtWidgets::QToolButton::ToolButtonPopupMode
        define_qenum_under<QToolButton::ToolButtonPopupMode>(rb_cQToolButton, "ToolButtonPopupMode");
        define_qenum_value_under(rb_cQToolButtonToolButtonPopupMode, "DelayedPopup", QToolButton::ToolButtonPopupMode::DelayedPopup);
        define_qenum_value_under(rb_cQToolButtonToolButtonPopupMode, "MenuButtonPopup", QToolButton::ToolButtonPopupMode::MenuButtonPopup);
        define_qenum_value_under(rb_cQToolButtonToolButtonPopupMode, "InstantPopup", QToolButton::ToolButtonPopupMode::InstantPopup);
}
