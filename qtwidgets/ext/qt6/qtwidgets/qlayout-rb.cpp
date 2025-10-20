#include "qlayout-rb.hpp"
#include <qlayout.h>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQLayout;

void Init_qlayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLayout =
        // RubyQt6::QtWidgets::QLayout
        define_class_under<QLayout, QObject>(rb_mQt6QtWidgets, "QLayout")
            // RubyQt6-Defined Functions
            .define_method("set_alignment", [](QLayout *self, QLayout *l, Qt::AlignmentFlag alignment) -> bool { return self->setAlignment(l, alignment); }, Arg("l"), Arg("alignment"))
            .define_method("set_alignment", [](QLayout *self, QWidget *w, Qt::AlignmentFlag alignment) -> bool { return self->setAlignment(w, alignment); }, Arg("w"), Arg("alignment"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QLayout::staticMetaObject; })
            // Inherits QLayoutItem
            .define_method("alignment", &QLayout::alignment)
            .define_method("minimum_height_for_width", &QLayout::minimumHeightForWidth, Arg("w"))
            .define_method("spacer_item", &QLayout::spacerItem)
            .define_method("widget", &QLayout::widget)
            // Public Functions
            .define_method("activate", &QLayout::activate)
            .define_method("add_item", &QLayout::addItem, Arg("item").takeOwnership())
            .define_method("add_widget", &QLayout::addWidget, Arg("widget").takeOwnership())
            .define_method("contents_margins", &QLayout::contentsMargins)
            .define_method("contents_rect", &QLayout::contentsRect)
            .define_method("control_types", &QLayout::controlTypes)
            .define_method("count", &QLayout::count)
            .define_method("expanding_directions", &QLayout::expandingDirections)
            .define_method("geometry", &QLayout::geometry)
            .define_method("get_contents_margins", &QLayout::getContentsMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method<int (QLayout::*)(const QLayoutItem *) const>("index_of", &QLayout::indexOf, Arg("layout_item"))
            .define_method<int (QLayout::*)(const QWidget *) const>("index_of", &QLayout::indexOf, Arg("widget"))
            .define_method("invalidate", &QLayout::invalidate)
            .define_method("empty?", &QLayout::isEmpty)
            .define_method("enabled?", &QLayout::isEnabled)
            .define_method("item_at", &QLayout::itemAt, Arg("index"))
            .define_method("layout", &QLayout::layout)
            .define_method("maximum_size", &QLayout::maximumSize)
            .define_method("menu_bar", &QLayout::menuBar)
            .define_method("minimum_size", &QLayout::minimumSize)
            .define_method("parent_widget", &QLayout::parentWidget)
            .define_method("_remove_item", &QLayout::removeItem, Arg("item"))
            .define_method("_remove_widget", &QLayout::removeWidget, Arg("widget"))
            .define_method("replace_widget", &QLayout::replaceWidget, Arg("from"), Arg("to"), Arg("options") = static_cast<Qt::FindChildOptions>(Qt::FindChildrenRecursively))
            .define_method<bool (QLayout::*)(QLayout *, Qt::Alignment)>("set_alignment", &QLayout::setAlignment, Arg("l"), Arg("alignment"))
            .define_method<bool (QLayout::*)(QWidget *, Qt::Alignment)>("set_alignment", &QLayout::setAlignment, Arg("w"), Arg("alignment"))
            .define_method<void (QLayout::*)(const QMargins &)>("set_contents_margins", &QLayout::setContentsMargins, Arg("margins"))
            .define_method<void (QLayout::*)(int, int, int, int)>("set_contents_margins", &QLayout::setContentsMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("set_enabled", &QLayout::setEnabled, Arg("enabled"))
            .define_method("set_geometry", &QLayout::setGeometry, Arg("rect"))
            .define_method("set_menu_bar", &QLayout::setMenuBar, Arg("w"))
            .define_method("set_size_constraint", &QLayout::setSizeConstraint, Arg("size_constraint"))
            .define_method("set_spacing", &QLayout::setSpacing, Arg("spacing"))
            .define_method("size_constraint", &QLayout::sizeConstraint)
            .define_method("spacing", &QLayout::spacing)
            .define_method("take_at", &QLayout::takeAt, Arg("index"), Return().takeOwnership())
            .define_method("total_height_for_width", &QLayout::totalHeightForWidth, Arg("w"))
            .define_method("total_maximum_size", &QLayout::totalMaximumSize)
            .define_method("total_minimum_height_for_width", &QLayout::totalMinimumHeightForWidth, Arg("w"))
            .define_method("total_minimum_size", &QLayout::totalMinimumSize)
            .define_method("total_size_hint", &QLayout::totalSizeHint)
            .define_method("unset_contents_margins", &QLayout::unsetContentsMargins)
            .define_method("update", &QLayout::update)
            // Static Public Members
            .define_singleton_function("closest_acceptable_size", &QLayout::closestAcceptableSize, Arg("w"), Arg("s"));

    Enum<QLayout::SizeConstraint> rb_cQLayoutSizeConstraint =
        // RubyQt6::QtWidgets::QLayout::SizeConstraint
        define_enum_under<QLayout::SizeConstraint>("SizeConstraint", rb_cQLayout)
            .define_value("SetDefaultConstraint", QLayout::SizeConstraint::SetDefaultConstraint)
            .define_value("SetNoConstraint", QLayout::SizeConstraint::SetNoConstraint)
            .define_value("SetMinimumSize", QLayout::SizeConstraint::SetMinimumSize)
            .define_value("SetFixedSize", QLayout::SizeConstraint::SetFixedSize)
            .define_value("SetMaximumSize", QLayout::SizeConstraint::SetMaximumSize)
            .define_value("SetMinAndMaxSize", QLayout::SizeConstraint::SetMinAndMaxSize);
}
