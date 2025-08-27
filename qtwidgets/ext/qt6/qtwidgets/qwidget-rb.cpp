#include "qwidget-rb.hpp"
#include <qwidget.h>

using namespace Rice;

Rice::Class rb_cQWidget;

void Init_qwidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQWidget =
        // RubyQt6::QtWidgets::QWidget
        define_class_under<QWidget, QObject>(rb_mQt6QtWidgets, "QWidget")
            .define_constructor(Constructor<QWidget, QWidget *, Qt::WindowFlags>(), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("f") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
            .define_method("_parent_widget", &QWidget::parentWidget)
            .define_method<void (QWidget::*)(QWidget *)>("_set_parent", &QWidget::setParent, Arg("parent"))
            .define_method("_show", &QWidget::show)
            .define_method("_show_full_screen", &QWidget::showFullScreen)
            .define_method("_show_maximized", &QWidget::showMaximized)
            .define_method("_show_minimized", &QWidget::showMinimized)
            .define_method("_show_normal", &QWidget::showNormal)
            .define_method("_hide", &QWidget::hide)
            .define_method("_geometry", &QWidget::geometry)
            .define_method<void (QWidget::*)(const QRect &)>("_set_geometry", &QWidget::setGeometry, Arg(""))
            .define_method("_size", &QWidget::size)
            .define_method<void (QWidget::*)(const QSize &)>("_resize", &QWidget::resize, Arg("size"))
            .define_method<void (QWidget::*)(int, int)>("_resize", &QWidget::resize, Arg("width"), Arg("height"))
            .define_method("_font", &QWidget::font)
            .define_method("_set_font", &QWidget::setFont, Arg("font"));
}
