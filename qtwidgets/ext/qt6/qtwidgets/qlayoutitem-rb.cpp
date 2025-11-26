#include "qlayoutitem-rb.hpp"
#include <qlayoutitem.h>

#include <QLayout>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQLayoutItem;
Rice::Class rb_cQSpacerItem;
Rice::Class rb_cQWidgetItem;

void Init_qlayoutitem(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLayoutItem =
        // RubyQt6::QtWidgets::QLayoutItem
        define_class_under<QLayoutItem>(rb_mQt6QtWidgets, "QLayoutItem")
            // RubyQt6-Defined Functions
            .define_singleton_function("_delete_now", [](QLayoutItem *item) -> void { delete item; }, Arg("item").takeOwnership())
            .define_singleton_function("_take_ownership_from_ruby", [](QLayoutItem *) -> void {}, Arg("item").takeOwnership())
            .define_method("set_alignment", [](QLayoutItem *self, Qt::AlignmentFlag alignment) -> void { return self->setAlignment(alignment); }, Arg("alignment"))
            // Public Functions
            .define_method("alignment", &QLayoutItem::alignment)
            .define_method("control_types", &QLayoutItem::controlTypes)
            .define_method("expanding_directions", &QLayoutItem::expandingDirections)
            .define_method("geometry", &QLayoutItem::geometry)
            .define_method("has_height_for_width", &QLayoutItem::hasHeightForWidth)
            .define_method("height_for_width", &QLayoutItem::heightForWidth, Arg("w"))
            .define_method("invalidate", &QLayoutItem::invalidate)
            .define_method("empty?", &QLayoutItem::isEmpty)
            .define_method("layout", &QLayoutItem::layout)
            .define_method("maximum_size", &QLayoutItem::maximumSize)
            .define_method("minimum_height_for_width", &QLayoutItem::minimumHeightForWidth, Arg("w"))
            .define_method("minimum_size", &QLayoutItem::minimumSize)
            .define_method("set_alignment", &QLayoutItem::setAlignment, Arg("alignment"))
            .define_method("set_geometry", &QLayoutItem::setGeometry, Arg("rect"))
            .define_method("size_hint", &QLayoutItem::sizeHint)
            .define_method("spacer_item", &QLayoutItem::spacerItem)
            .define_method("widget", &QLayoutItem::widget);


    rb_cQSpacerItem =
        // RubyQt6::QtWidgets::QSpacerItem
        define_class_under<QSpacerItem, QLayoutItem>(rb_mQt6QtWidgets, "QSpacerItem")
            // Constructor
            .define_constructor(Constructor<QSpacerItem, int, int, QSizePolicy::Policy, QSizePolicy::Policy>(), Arg("w"), Arg("h"), Arg("h_policy"), Arg("v_policy"))
            // Public Functions
            .define_method("change_size", &QSpacerItem::changeSize, Arg("w"), Arg("h"), Arg("h_policy") = static_cast<QSizePolicy::Policy>(QSizePolicy::Minimum), Arg("v_policy") = static_cast<QSizePolicy::Policy>(QSizePolicy::Minimum))
            .define_method("size_policy", &QSpacerItem::sizePolicy);

    rb_cQWidgetItem =
        // RubyQt6::QtWidgets::QWidgetItem
        define_class_under<QWidgetItem, QLayoutItem>(rb_mQt6QtWidgets, "QWidgetItem")
            // Constructor
            .define_constructor(Constructor<QWidgetItem, QWidget *>(), Arg("widget"));
}
