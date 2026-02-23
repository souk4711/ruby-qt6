#include "qabstractbutton-rb.hpp"
#include <qabstractbutton.h>

#include <QButtonGroup>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAbstractButton;

void Init_qabstractbutton(Module rb_mQt6QtWidgets)
{
    rb_cQAbstractButton =
        // RubyQt6::QtWidgets::QAbstractButton
        define_qlass_under<QAbstractButton, QWidget>(rb_mQt6QtWidgets, "QAbstractButton")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractButton::staticMetaObject; })
            // Public Functions
            .define_method("auto_exclusive", &QAbstractButton::autoExclusive)
            .define_method("auto_repeat", &QAbstractButton::autoRepeat)
            .define_method("auto_repeat_delay", &QAbstractButton::autoRepeatDelay)
            .define_method("auto_repeat_interval", &QAbstractButton::autoRepeatInterval)
            .define_method("group", &QAbstractButton::group)
            .define_method("icon", &QAbstractButton::icon)
            .define_method("icon_size", &QAbstractButton::iconSize)
            .define_method("checkable?", &QAbstractButton::isCheckable)
            .define_method("checked?", &QAbstractButton::isChecked)
            .define_method("down?", &QAbstractButton::isDown)
            .define_method("set_auto_exclusive", &QAbstractButton::setAutoExclusive, Arg("auto_exclusive"))
            .define_method("set_auto_repeat", &QAbstractButton::setAutoRepeat, Arg("auto_repeat"))
            .define_method("set_auto_repeat_delay", &QAbstractButton::setAutoRepeatDelay, Arg("auto_repeat_delay"))
            .define_method("set_auto_repeat_interval", &QAbstractButton::setAutoRepeatInterval, Arg("auto_repeat_interval"))
            .define_method("set_checkable", &QAbstractButton::setCheckable, Arg("checkable"))
            .define_method("set_down", &QAbstractButton::setDown, Arg("down"))
            .define_method("set_icon", &QAbstractButton::setIcon, Arg("icon"))
            .define_method("set_shortcut", &QAbstractButton::setShortcut, Arg("key"))
            .define_method("_set_text", &QAbstractButton::setText, Arg("text"))
            .define_method("shortcut", &QAbstractButton::shortcut)
            .define_method("text", &QAbstractButton::text)
            // Public Slots
            .define_method("animate_click", &QAbstractButton::animateClick)
            .define_method("click", &QAbstractButton::click)
            .define_method("set_checked", &QAbstractButton::setChecked, Arg("checked"))
            .define_method("set_icon_size", &QAbstractButton::setIconSize, Arg("size"))
            .define_method("toggle", &QAbstractButton::toggle);
            // Signals
            // .define_method("clicked", &QAbstractButton::clicked, Arg("checked") = static_cast<bool>(false))
            // .define_method("pressed", &QAbstractButton::pressed)
            // .define_method("released", &QAbstractButton::released)
            // .define_method("toggled", &QAbstractButton::toggled, Arg("checked"));
}
