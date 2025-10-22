#include "qboxlayout-rb.hpp"
#include <qboxlayout.h>
#include <rice/qenum.hpp>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQBoxLayout;
Rice::Class rb_cQHBoxLayout;
Rice::Class rb_cQVBoxLayout;

void Init_qboxlayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQBoxLayout =
        // RubyQt6::QtWidgets::QBoxLayout
        define_class_under<QBoxLayout, QLayout>(rb_mQt6QtWidgets, "QBoxLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QBoxLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QBoxLayout, QBoxLayout::Direction, QWidget *>(), Arg("direction"), Arg("parent"))
            // Public Functions
            .define_method("add_item", &QBoxLayout::addItem, Arg("item").takeOwnership())
            .define_method("add_layout", &QBoxLayout::addLayout, Arg("layout").takeOwnership(), Arg("stretch") = static_cast<int>(0))
            .define_method("add_spacer_item", &QBoxLayout::addSpacerItem, Arg("item").takeOwnership())
            .define_method("add_spacing", &QBoxLayout::addSpacing, Arg("size"))
            .define_method("add_stretch", &QBoxLayout::addStretch, Arg("stretch") = static_cast<int>(0))
            .define_method("add_strut", &QBoxLayout::addStrut, Arg("strut"))
            .define_method("add_widget", &QBoxLayout::addWidget, Arg("widget").takeOwnership(), Arg("stretch") = static_cast<int>(0), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method("count", &QBoxLayout::count)
            .define_method("direction", &QBoxLayout::direction)
            .define_method("expanding_directions", &QBoxLayout::expandingDirections)
            .define_method("insert_item", &QBoxLayout::insertItem, Arg("index"), Arg("item").takeOwnership())
            .define_method("insert_layout", &QBoxLayout::insertLayout, Arg("index"), Arg("layout").takeOwnership(), Arg("stretch") = static_cast<int>(0))
            .define_method("insert_spacer_item", &QBoxLayout::insertSpacerItem, Arg("index"), Arg("item").takeOwnership())
            .define_method("insert_spacing", &QBoxLayout::insertSpacing, Arg("index"), Arg("size"))
            .define_method("insert_stretch", &QBoxLayout::insertStretch, Arg("index"), Arg("stretch") = static_cast<int>(0))
            .define_method("insert_widget", &QBoxLayout::insertWidget, Arg("index"), Arg("widget").takeOwnership(), Arg("stretch") = static_cast<int>(0), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method("invalidate", &QBoxLayout::invalidate)
            .define_method("item_at", &QBoxLayout::itemAt, Arg("index"))
            .define_method("maximum_size", &QBoxLayout::maximumSize)
            .define_method("minimum_height_for_width", &QBoxLayout::minimumHeightForWidth, Arg("w"))
            .define_method("minimum_size", &QBoxLayout::minimumSize)
            .define_method("set_direction", &QBoxLayout::setDirection, Arg("direction"))
            .define_method("set_geometry", &QBoxLayout::setGeometry, Arg("rect"))
            .define_method("set_spacing", &QBoxLayout::setSpacing, Arg("spacing"))
            .define_method("set_stretch", &QBoxLayout::setStretch, Arg("index"), Arg("stretch"))
            .define_method<bool (QBoxLayout::*)(QLayout *, int)>("set_stretch_factor", &QBoxLayout::setStretchFactor, Arg("l"), Arg("stretch"))
            .define_method<bool (QBoxLayout::*)(QWidget *, int)>("set_stretch_factor", &QBoxLayout::setStretchFactor, Arg("w"), Arg("stretch"))
            .define_method("spacing", &QBoxLayout::spacing)
            .define_method("stretch", &QBoxLayout::stretch, Arg("index"))
            .define_method("take_at", &QBoxLayout::takeAt, Arg("index"), Return().takeOwnership());

    Enum<QBoxLayout::Direction> rb_cQBoxLayoutDirection =
        // RubyQt6::QtWidgets::QBoxLayout::Direction
        define_qenum_under<QBoxLayout::Direction>("Direction", rb_cQBoxLayout)
            .define_value("LeftToRight", QBoxLayout::Direction::LeftToRight)
            .define_value("RightToLeft", QBoxLayout::Direction::RightToLeft)
            .define_value("TopToBottom", QBoxLayout::Direction::TopToBottom)
            .define_value("BottomToTop", QBoxLayout::Direction::BottomToTop)
            .define_value("Down", QBoxLayout::Direction::Down)
            .define_value("Up", QBoxLayout::Direction::Up);

    rb_cQHBoxLayout =
        // RubyQt6::QtWidgets::QHBoxLayout
        define_class_under<QHBoxLayout, QBoxLayout>(rb_mQt6QtWidgets, "QHBoxLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QHBoxLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QHBoxLayout>()).define_constructor(Constructor<QHBoxLayout, QWidget *>(), Arg("parent"));

    rb_cQVBoxLayout =
        // RubyQt6::QtWidgets::QVBoxLayout
        define_class_under<QVBoxLayout, QBoxLayout>(rb_mQt6QtWidgets, "QVBoxLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QVBoxLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QVBoxLayout>()).define_constructor(Constructor<QVBoxLayout, QWidget *>(), Arg("parent"));
}
