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
            .define_method("_size_constraint", &QLayout::sizeConstraint)
            .define_method("_spacing", &QLayout::spacing)
            .define_method("_enabled?", &QLayout::isEnabled)
            .define_method("_set_size_constraint", &QLayout::setSizeConstraint, Arg("constraint"))
            .define_method("_set_spacing", &QLayout::setSpacing, Arg("spacing"))
            .define_method("_set_enabled", &QLayout::setEnabled, Arg("enabled"))
            .define_method("_add_item", &QLayout::addItem, Arg("item"))
            .define_method("_add_widget", &QLayout::addWidget, Arg("widget"))
            .define_method("_remove_item", &QLayout::removeItem, Arg("item"))
            .define_method("_remove_widget", &QLayout::removeWidget, Arg("widget"))
            .define_method<int (QLayout::*)(const QLayoutItem *) const>("_index_of", &QLayout::indexOf, Arg("item"))
            .define_method<int (QLayout::*)(const QWidget *) const>("_index_of", &QLayout::indexOf, Arg("widget"))
            .define_method("_item_at", &QLayout::itemAt, Arg("index"))
            .define_method("_take_at", &QLayout::takeAt, Arg("index"), Return().takeOwnership())
            .define_method("_count", &QLayout::count);

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
