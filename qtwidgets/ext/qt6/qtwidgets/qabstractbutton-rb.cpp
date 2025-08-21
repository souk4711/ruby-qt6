#include "qabstractbutton-rb.hpp"
#include <qabstractbutton.h>

#include <QButtonGroup>

using namespace Rice;

Rice::Class rb_cQAbstractButton;

void Init_qabstractbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractButton =
        // Qt6::QtWidgets::QAbstractButton
        define_class_under<QAbstractButton, QWidget>(rb_mQt6QtWidgets, "QAbstractButton")
            .define_method("set_text", &QAbstractButton::setText, Arg("text"))
            .define_method("text", &QAbstractButton::text)
            .define_method("set_icon", &QAbstractButton::setIcon, Arg("icon"))
            .define_method("icon", &QAbstractButton::icon)
            .define_method("icon_size", &QAbstractButton::iconSize)
            .define_method("set_shortcut", &QAbstractButton::setShortcut, Arg("key"))
            .define_method("shortcut", &QAbstractButton::shortcut)
            .define_method("set_checkable", &QAbstractButton::setCheckable, Arg(""))
            .define_method("is_checkable", &QAbstractButton::isCheckable)
            .define_method("is_checked", &QAbstractButton::isChecked)
            .define_method("set_down", &QAbstractButton::setDown, Arg(""))
            .define_method("is_down", &QAbstractButton::isDown)
            .define_method("set_auto_repeat", &QAbstractButton::setAutoRepeat, Arg(""))
            .define_method("auto_repeat", &QAbstractButton::autoRepeat)
            .define_method("set_auto_repeat_delay", &QAbstractButton::setAutoRepeatDelay, Arg(""))
            .define_method("auto_repeat_delay", &QAbstractButton::autoRepeatDelay)
            .define_method("set_auto_repeat_interval", &QAbstractButton::setAutoRepeatInterval, Arg(""))
            .define_method("auto_repeat_interval", &QAbstractButton::autoRepeatInterval)
            .define_method("set_auto_exclusive", &QAbstractButton::setAutoExclusive, Arg(""))
            .define_method("auto_exclusive", &QAbstractButton::autoExclusive)
            .define_method("group", &QAbstractButton::group)
            .define_method("set_icon_size", &QAbstractButton::setIconSize, Arg("size"))
            .define_method("animate_click", &QAbstractButton::animateClick)
            .define_method("click", &QAbstractButton::click)
            .define_method("toggle", &QAbstractButton::toggle)
            .define_method("set_checked", &QAbstractButton::setChecked, Arg(""))
            .define_method("pressed", &QAbstractButton::pressed)
            .define_method("released", &QAbstractButton::released)
            .define_method("clicked", &QAbstractButton::clicked, Arg("checked") = static_cast<bool>(false))
            .define_method("toggled", &QAbstractButton::toggled, Arg("checked"));
}
