#include "qquickwidget-rb.hpp"
#include <qquickwidget.h>

using namespace Rice;

Rice::Class rb_cQQuickWidget;

void Init_qquickwidget(Rice::Module rb_mQt6QtQuickWidgets)
{
    rb_cQQuickWidget =
        // RubyQt6::QtQuickWidgets::QQuickWidget
        define_class_under<QQuickWidget, QWidget>(rb_mQt6QtQuickWidgets, "QQuickWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QQuickWidget::staticMetaObject; });
}
