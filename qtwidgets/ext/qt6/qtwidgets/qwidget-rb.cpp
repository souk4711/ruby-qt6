#include "qwidget-rb.hpp"
#include <qwidget.h>

using namespace Rice;

Rice::Class rb_cQWidget;

void Init_qwidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQWidget =
        // RubyQt6::QtWidgets::QWidget
        define_class_under<QWidget, QObject>(rb_mQt6QtWidgets, "QWidget")
            .define_method("show", &QWidget::show)
            .define_method("show_full_screen", &QWidget::showFullScreen)
            .define_method("show_maximized", &QWidget::showMaximized)
            .define_method("show_minimized", &QWidget::showMinimized)
            .define_method("show_normal", &QWidget::showNormal)
            .define_method("hide", &QWidget::hide)
            .define_method("size", &QWidget::size)
            .define_method<void (QWidget::*)(int, int)>("resize", &QWidget::resize, Arg("width"), Arg("height"))
            .define_method<void (QWidget::*)(const QSize &)>("resize", &QWidget::resize, Arg("size"));
}
