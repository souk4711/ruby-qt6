#include "qstackedwidget-rb.hpp"
#include <qstackedwidget.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQStackedWidget;

void Init_qstackedwidget(Module rb_mQt6QtWidgets)
{
    rb_cQStackedWidget =
        // RubyQt6::QtWidgets::QStackedWidget
        define_qlass_under<QStackedWidget, QFrame>(rb_mQt6QtWidgets, "QStackedWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QStackedWidget * { return qobject_cast<QStackedWidget *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QStackedWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QStackedWidget, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("add_widget", &QStackedWidget::addWidget, Arg("widget"))
            .define_method("count", &QStackedWidget::count)
            .define_method("current_index", &QStackedWidget::currentIndex)
            .define_method("current_widget", &QStackedWidget::currentWidget)
            .define_method("index_of", &QStackedWidget::indexOf, Arg("widget"))
            .define_method("insert_widget", &QStackedWidget::insertWidget, Arg("index"), Arg("widget"))
            .define_method("remove_widget", &QStackedWidget::removeWidget, Arg("w"))
            .define_method("widget", &QStackedWidget::widget, Arg("index"))
            // Public Slots
            .define_method("set_current_index", &QStackedWidget::setCurrentIndex, Arg("index"))
            .define_method("set_current_widget", &QStackedWidget::setCurrentWidget, Arg("w"));
            // Signals
            // .define_method("current_changed", &QStackedWidget::currentChanged, Arg("index"))
            // .define_method("widget_added", &QStackedWidget::widgetAdded, Arg("index"))
            // .define_method("widget_removed", &QStackedWidget::widgetRemoved, Arg("index"));
}
