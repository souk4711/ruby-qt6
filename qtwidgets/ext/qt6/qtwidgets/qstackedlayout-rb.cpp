#include "qstackedlayout-rb.hpp"
#include <qstackedlayout.h>
#include <rice/qenum.hpp>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQStackedLayout;

void Init_qstackedlayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQStackedLayout =
        // RubyQt6::QtWidgets::QStackedLayout
        define_class_under<QStackedLayout, QLayout>(rb_mQt6QtWidgets, "QStackedLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QStackedLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QStackedLayout, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("add_item", &QStackedLayout::addItem, Arg("item").takeOwnership())
            .define_method("add_widget", &QStackedLayout::addWidget, Arg("widget").takeOwnership())
            .define_method("count", &QStackedLayout::count)
            .define_method("current_index", &QStackedLayout::currentIndex)
            .define_method("current_widget", &QStackedLayout::currentWidget)
            .define_method("insert_widget", &QStackedLayout::insertWidget, Arg("index"), Arg("widget").takeOwnership())
            .define_method("item_at", &QStackedLayout::itemAt, Arg("index"))
            .define_method("minimum_size", &QStackedLayout::minimumSize)
            .define_method("set_geometry", &QStackedLayout::setGeometry, Arg("rect"))
            .define_method("set_stacking_mode", &QStackedLayout::setStackingMode, Arg("stacking_mode"))
            .define_method("stacking_mode", &QStackedLayout::stackingMode)
            .define_method("take_at", &QStackedLayout::takeAt, Arg("index"), Return().takeOwnership())
            .define_method<QWidget* (QStackedLayout::*)(int) const>("widget", &QStackedLayout::widget, Arg("index"))
            // Public Slots
            .define_method("set_current_index", &QStackedLayout::setCurrentIndex, Arg("index"))
            .define_method("set_current_widget", &QStackedLayout::setCurrentWidget, Arg("w"))
            // Signals
            .define_method("current_changed", &QStackedLayout::currentChanged, Arg("index"))
            .define_method("widget_added", &QStackedLayout::widgetAdded, Arg("index"))
            .define_method("widget_removed", &QStackedLayout::widgetRemoved, Arg("index"));

    Data_Type<QStackedLayout::StackingMode> rb_cQStackedLayoutStackingMode =
        // RubyQt6::QtWidgets::QStackedLayout::StackingMode
        define_qenum_under<QStackedLayout::StackingMode>(rb_cQStackedLayout, "StackingMode");
        define_qenum_value_under(rb_cQStackedLayoutStackingMode, "StackOne", QStackedLayout::StackingMode::StackOne);
        define_qenum_value_under(rb_cQStackedLayoutStackingMode, "StackAll", QStackedLayout::StackingMode::StackAll);
}
