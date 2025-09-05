#include "qstackedlayout-rb.hpp"
#include <qstackedlayout.h>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQStackedLayout;

void Init_qstackedlayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQStackedLayout =
        // RubyQt6::QtWidgets::QStackedLayout
        define_class_under<QStackedLayout, QLayout>(rb_mQt6QtWidgets, "QStackedLayout")
            // Constructor
            .define_constructor(Constructor<QStackedLayout, QWidget *>(), Arg("parent"))
            .define_constructor(Constructor<QStackedLayout, QLayout *>(), Arg("parent_layout"))
            // Public Functions
            .define_method("add_widget", &QStackedLayout::addWidget, Arg("w").takeOwnership())
            .define_method("current_index", &QStackedLayout::currentIndex)
            .define_method("current_widget", &QStackedLayout::currentWidget)
            .define_method("insert_widget", &QStackedLayout::insertWidget, Arg("index"), Arg("w"))
            .define_method("set_stacking_mode", &QStackedLayout::setStackingMode, Arg("stacking_mode"))
            .define_method("stacking_mode", &QStackedLayout::stackingMode)
            .define_method<QWidget* (QStackedLayout::*)(int) const>("widget", &QStackedLayout::widget, Arg(""))
            // Reimplemented Public Functions
            .define_method("add_item", &QStackedLayout::addItem, Arg("item"))
            .define_method("count", &QStackedLayout::count)
            .define_method("has_height_for_width", &QStackedLayout::hasHeightForWidth)
            .define_method("height_for_width", &QStackedLayout::heightForWidth, Arg("width"))
            .define_method("item_at", &QStackedLayout::itemAt, Arg(""))
            .define_method("minimum_size", &QStackedLayout::minimumSize)
            .define_method("set_geometry", &QStackedLayout::setGeometry, Arg("rect"))
            .define_method("size_hint", &QStackedLayout::sizeHint)
            .define_method("take_at", &QStackedLayout::takeAt, Arg(""))
            // Public Slots
            .define_method("set_current_index", &QStackedLayout::setCurrentIndex, Arg("index"))
            .define_method("set_current_widget", &QStackedLayout::setCurrentWidget, Arg("w"))
            // Signals
            .define_method("current_changed", &QStackedLayout::currentChanged, Arg("index"))
            .define_method("widget_added", &QStackedLayout::widgetAdded, Arg("index"))
            .define_method("widget_removed", &QStackedLayout::widgetRemoved, Arg("index"));

    Enum<QStackedLayout::StackingMode> rb_cQStackedLayoutStackingMode =
        // RubyQt6::QtWidgets::QStackedLayout::StackingMode
        define_enum_under<QStackedLayout::StackingMode>("StackingMode", rb_cQStackedLayout)
            .define_value("StackOne", QStackedLayout::StackingMode::StackOne)
            .define_value("StackAll", QStackedLayout::StackingMode::StackAll);
}
