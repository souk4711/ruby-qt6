#include "qlayoutitem-rb.hpp"
#include <qlayoutitem.h>

#include <QLayout>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQLayoutItem;

void Init_qlayoutitem(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLayoutItem =
        // RubyQt6::QtWidgets::QLayoutItem
        define_class_under<QLayoutItem>(rb_mQt6QtWidgets, "QLayoutItem")
            // Public Functions
            .define_method("alignment", &QLayoutItem::alignment)
            .define_method("control_types", &QLayoutItem::controlTypes)
            .define_method("expanding_directions", &QLayoutItem::expandingDirections)
            .define_method("geometry", &QLayoutItem::geometry)
            .define_method("invalidate", &QLayoutItem::invalidate)
            .define_method("empty?", &QLayoutItem::isEmpty)
            .define_method("layout", &QLayoutItem::layout)
            .define_method("maximum_size", &QLayoutItem::maximumSize)
            .define_method("minimum_height_for_width", &QLayoutItem::minimumHeightForWidth, Arg("w"))
            .define_method("minimum_size", &QLayoutItem::minimumSize)
            .define_method("set_alignment", &QLayoutItem::setAlignment, Arg("a"))
            .define_method("set_geometry", &QLayoutItem::setGeometry, Arg("rect"))
            .define_method("spacer_item", &QLayoutItem::spacerItem)
            .define_method("widget", &QLayoutItem::widget);
}
