#include "qwidget-rb.hpp"
#include <qwidget.h>

using namespace Rice;

Rice::Class rb_cQWidget;

void Init_qwidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQWidget =
        // RubyQt6::QtWidgets::QWidget
        define_class_under<QWidget, QObject>(rb_mQt6QtWidgets, "QWidget")
            .define_method("_show", &QWidget::show)
            .define_method("_show_full_screen", &QWidget::showFullScreen)
            .define_method("_show_maximized", &QWidget::showMaximized)
            .define_method("_show_minimized", &QWidget::showMinimized)
            .define_method("_show_normal", &QWidget::showNormal)
            .define_method("_hide", &QWidget::hide)
            .define_method("_size", &QWidget::size)
            .define_method<void (QWidget::*)(const QSize &)>("_resize", &QWidget::resize, Arg("size"))
            .define_method("_font", &QWidget::font)
            .define_method("_set_font", &QWidget::setFont, Arg("font"));
}
