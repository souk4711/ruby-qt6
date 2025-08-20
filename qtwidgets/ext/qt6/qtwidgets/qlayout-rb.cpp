#include "qlayout-rb.hpp"
#include <qlayout.h>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQLayout;

void Init_QLayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLayout =
        // Qt6::QtWidgets::QLayout
        define_class_under<QLayout, QObject>(rb_mQt6QtWidgets, "QLayout")
            // Public Functions
            .define_method("activate", &QLayout::activate)
            .define_method("add_item", &QLayout::addItem, Arg(""))
            .define_method("add_widget", &QLayout::addWidget, Arg("w"))
            .define_method("contents_margins", &QLayout::contentsMargins)
            .define_method("contents_rect", &QLayout::contentsRect)
            .define_method("count", &QLayout::count)
            .define_method("get_contents_margins", &QLayout::getContentsMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("is_enabled", &QLayout::isEnabled)
            .define_method<int (QLayout::*)(const QLayoutItem *) const>("index_of", &QLayout::indexOf, Arg(""))
            .define_method<int (QLayout::*)(const QWidget *) const>("index_of", &QLayout::indexOf, Arg(""))
            .define_method("item_at", &QLayout::itemAt, Arg("index"))
            .define_method("menu_bar", &QLayout::menuBar)
            .define_method("parent_widget", &QLayout::parentWidget)
            .define_method("remove_item", &QLayout::removeItem, Arg(""))
            .define_method("remove_widget", &QLayout::removeWidget, Arg("w"))
            .define_method("replace_widget", &QLayout::replaceWidget, Arg("from"), Arg("to"), Arg("options") = static_cast<Qt::FindChildOptions>(Qt::FindChildrenRecursively))
            .define_method<bool (QLayout::*)(QLayout *, Qt::Alignment)>("set_alignment", &QLayout::setAlignment, Arg("l"), Arg("alignment"))
            .define_method<bool (QLayout::*)(QWidget *, Qt::Alignment)>("set_alignment", &QLayout::setAlignment, Arg("w"), Arg("alignment"))
            .define_method("set_enabled", &QLayout::setEnabled, Arg(""))
            .define_method<void (QLayout::*)(const QMargins &)>("set_contents_margins", &QLayout::setContentsMargins, Arg("margins"))
            .define_method<void (QLayout::*)(int, int, int, int)>("set_contents_margins", &QLayout::setContentsMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("set_menu_bar", &QLayout::setMenuBar, Arg("w"))
            .define_method("set_size_constraint", &QLayout::setSizeConstraint, Arg(""))
            .define_method("set_spacing", &QLayout::setSpacing, Arg(""))
            .define_method("size_constraint", &QLayout::sizeConstraint)
            .define_method("spacing", &QLayout::spacing)
            .define_method("take_at", &QLayout::takeAt, Arg("index"))
            .define_method("total_height_for_width", &QLayout::totalHeightForWidth, Arg("w"))
            .define_method("total_maximum_size", &QLayout::totalMaximumSize)
            .define_method("total_minimum_height_for_width", &QLayout::totalMinimumHeightForWidth, Arg("w"))
            .define_method("total_minimum_size", &QLayout::totalMinimumSize)
            .define_method("total_size_hint", &QLayout::totalSizeHint)
            .define_method("unset_contents_margins", &QLayout::unsetContentsMargins)
            .define_method("update", &QLayout::update)
            // Reimplemented Public Functions
            .define_method("control_types", &QLayout::controlTypes)
            .define_method("expanding_directions", &QLayout::expandingDirections)
            .define_method("geometry", &QLayout::geometry)
            .define_method("invalidate", &QLayout::invalidate)
            .define_method("is_empty", &QLayout::isEmpty)
            .define_method("layout", &QLayout::layout)
            .define_method("maximum_size", &QLayout::maximumSize)
            .define_method("minimum_size", &QLayout::minimumSize)
            .define_method("set_geometry", &QLayout::setGeometry, Arg(""))
            // Static Public Members
            .define_singleton_function("closest_acceptable_size", &QLayout::closestAcceptableSize, Arg("w"), Arg("s"));

    // clang-format off
    Enum<QLayout::SizeConstraint> rb_cQLayoutSizeConstraint =
        // Qt6::QtWidgets::QLayout::SizeConstraint
        define_enum_under<QLayout::SizeConstraint>("SizeConstraint", rb_cQLayout)
            .define_value("SetDefaultConstraint", QLayout::SizeConstraint::SetDefaultConstraint)
            .define_value("SetNoConstraint", QLayout::SizeConstraint::SetNoConstraint)
            .define_value("SetMinimumSize", QLayout::SizeConstraint::SetMinimumSize)
            .define_value("SetFixedSize", QLayout::SizeConstraint::SetFixedSize)
            .define_value("SetMaximumSize", QLayout::SizeConstraint::SetMaximumSize)
            .define_value("SetMinAndMaxSize", QLayout::SizeConstraint::SetMinAndMaxSize);
}
