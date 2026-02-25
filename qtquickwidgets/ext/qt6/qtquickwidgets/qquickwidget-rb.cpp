#include "qquickwidget-rb.hpp"
#include <qquickwidget.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQQuickWidget;

void Init_qquickwidget(Module rb_mQt6QtQuickWidgets)
{
    rb_cQQuickWidget =
        // RubyQt6::QtQuickWidgets::QQuickWidget
        define_qlass_under<QQuickWidget, QWidget>(rb_mQt6QtQuickWidgets, "QQuickWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QQuickWidget * { return qobject_cast<QQuickWidget *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QQuickWidget::staticMetaObject; });
}
