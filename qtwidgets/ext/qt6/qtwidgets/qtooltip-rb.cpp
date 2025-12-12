#include "qtooltip-rb.hpp"
#include <qtooltip.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQToolTip;

void Init_qtooltip(Module rb_mQt6QtWidgets)
{
    rb_cQToolTip =
        // RubyQt6::QtWidgets::QToolTip
        define_class_under<QToolTip>(rb_mQt6QtWidgets, "QToolTip")
            // RubyQt6-Defined Functions
            .define_singleton_function("show_text", [](const QPoint &pos, const char *text, QWidget *w, const QRect &rect, int msecDisplayTime) -> void { return QToolTip::showText(pos, text, w, rect, msecDisplayTime); }, Arg("pos"), Arg("text"), Arg("w") = static_cast<QWidget *>(nullptr), Arg("rect") = static_cast<const QRect &>(QRect {}), Arg("msec_show_time") = static_cast<int>(-1))
            // Static Public Members
            .define_singleton_function("font", &QToolTip::font)
            .define_singleton_function("hide_text", &QToolTip::hideText)
            .define_singleton_function("visible?", &QToolTip::isVisible)
            .define_singleton_function("palette", &QToolTip::palette)
            .define_singleton_function("set_font", &QToolTip::setFont, Arg("font"))
            .define_singleton_function("set_palette", &QToolTip::setPalette, Arg("palette"))
            .define_singleton_function("show_text", &QToolTip::showText, Arg("pos"), Arg("text"), Arg("w") = static_cast<QWidget *>(nullptr), Arg("rect") = static_cast<const QRect &>(QRect {}), Arg("msec_show_time") = static_cast<int>(-1))
            .define_singleton_function("text", &QToolTip::text);
}
