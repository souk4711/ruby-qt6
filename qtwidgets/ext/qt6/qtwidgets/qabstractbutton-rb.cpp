#include "qabstractbutton-rb.hpp"
#include <qabstractbutton.h>

#include <QButtonGroup>

using namespace Rice;

Rice::Class rb_cQAbstractButton;

void Init_qabstractbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractButton =
        // RubyQt6::QtWidgets::QAbstractButton
        define_class_under<QAbstractButton, QWidget>(rb_mQt6QtWidgets, "QAbstractButton")
            .define_method("_group", &QAbstractButton::group)
            .define_method("_auto_exclusive?", &QAbstractButton::autoExclusive)
            .define_method("_auto_repeat?", &QAbstractButton::autoRepeat)
            .define_method("_auto_repeat_delay", &QAbstractButton::autoRepeatDelay)
            .define_method("_auto_repeat_interval", &QAbstractButton::autoRepeatInterval)
            .define_method("_checkable?", &QAbstractButton::isCheckable)
            .define_method("_checked?", &QAbstractButton::isChecked)
            .define_method("_down?", &QAbstractButton::isDown)
            .define_method("_icon", &QAbstractButton::icon)
            .define_method("_icon_size", &QAbstractButton::iconSize)
            .define_method("_shortcut", &QAbstractButton::shortcut)
            .define_method("_text", &QAbstractButton::text)
            .define_method("_set_auto_exclusive", &QAbstractButton::setAutoExclusive, Arg("enabled"))
            .define_method("_set_auto_repeat", &QAbstractButton::setAutoRepeat, Arg("enabled"))
            .define_method("_set_auto_repeat_delay", &QAbstractButton::setAutoRepeatDelay, Arg("msec"))
            .define_method("_set_auto_repeat_interval", &QAbstractButton::setAutoRepeatInterval, Arg("msec"))
            .define_method("_set_checkable", &QAbstractButton::setCheckable, Arg("checkable"))
            .define_method("_set_checked", &QAbstractButton::setChecked, Arg("checked"))
            .define_method("_set_down", &QAbstractButton::setDown, Arg("down"))
            .define_method("_set_icon", &QAbstractButton::setIcon, Arg("icon"))
            .define_method("_set_icon_size", &QAbstractButton::setIconSize, Arg("size"))
            .define_method("_set_shortcut", &QAbstractButton::setShortcut, Arg("key"))
            .define_method("_set_text", &QAbstractButton::setText, Arg("text"))
            .define_method("_animate_click", &QAbstractButton::animateClick)
            .define_method("_click", &QAbstractButton::click)
            .define_method("_toggle", &QAbstractButton::toggle);
}
