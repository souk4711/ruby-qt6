#include "qwidget-rb.hpp"

using namespace Rice;

Rice::Class rb_cQWidget;

void Init_QWidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQWidget = define_class_under<QWidget, QObject>(rb_mQt6QtWidgets, "QWidget")
                      .define_constructor(Constructor<QWidget, QWidget *, Qt::WindowFlags>(),
                                          Arg("parent") = static_cast<QWidget *>(nullptr),
                                          Arg("f") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
                      .define_method("show", &QWidget::show);
}
