#include "qquickstyle-rb.hpp"
#include <qquickstyle.h>

using namespace Rice;

Rice::Class rb_cQQuickStyle;

void Init_qquickstyle(Rice::Module rb_mQt6QtQuickControls2)
{
    rb_cQQuickStyle =
        // RubyQt6::QtQuickControls2::QQuickStyle
        define_class_under<QQuickStyle>(rb_mQt6QtQuickControls2, "QQuickStyle")
            // Static Public Members
            .define_singleton_function("name", &QQuickStyle::name)
            .define_singleton_function("set_style", &QQuickStyle::setStyle, Arg("style"))
            .define_singleton_function("set_fallback_style", &QQuickStyle::setFallbackStyle, Arg("style"));
}
