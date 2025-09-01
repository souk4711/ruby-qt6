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
            .define_method("_alignment", &QLayoutItem::alignment)
            .define_method("_geometry", &QLayoutItem::geometry)
            .define_method("_height_for_width", &QLayoutItem::heightForWidth, Arg("w"))
            .define_method("_minimum_height_for_width", &QLayoutItem::minimumHeightForWidth, Arg("w"))
            .define_method("_set_alignment", &QLayoutItem::setAlignment, Arg("alignment"))
            .define_method("_set_geometry", &QLayoutItem::setGeometry, Arg("geometry"))
            .define_method("_has_height_for_width?", &QLayoutItem::hasHeightForWidth)
            .define_method("_control_types", &QLayoutItem::controlTypes)
            .define_method("_expanding_directions", &QLayoutItem::expandingDirections)
            .define_method("_maximum_size", &QLayoutItem::maximumSize)
            .define_method("_minimum_size", &QLayoutItem::minimumSize)
            .define_method("_size_hint", &QLayoutItem::sizeHint)
            .define_method("_invalidate", &QLayoutItem::invalidate)
            .define_method("_empty?", &QLayoutItem::isEmpty)
            .define_method("_layout", &QLayoutItem::layout)
            .define_method("_widget", &QLayoutItem::widget)
            .define_method("_spacer_item", &QLayoutItem::spacerItem);
}
