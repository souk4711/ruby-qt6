#include "qboxlayout-rb.hpp"
#include <qboxlayout.h>
#include <rice/qt6/qenum.hpp>

#include <QWidget>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQBoxLayout;
Class rb_cQHBoxLayout;
Class rb_cQVBoxLayout;

void Init_qboxlayout(Module rb_mQt6QtWidgets)
{
    rb_cQBoxLayout =
        // RubyQt6::QtWidgets::QBoxLayout
        define_qlass_under<QBoxLayout, QLayout>(rb_mQt6QtWidgets, "QBoxLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QBoxLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QBoxLayout, QBoxLayout::Direction, QWidget *>(), Arg("direction"), Arg("parent"))
            // Public Functions
            .define_method("add_item", &QBoxLayout::addItem, Arg("item"))
            .define_method("add_layout", &QBoxLayout::addLayout, Arg("layout"), Arg("stretch") = static_cast<int>(0))
            .define_method("add_spacer_item", &QBoxLayout::addSpacerItem, Arg("item"))
            .define_method("add_spacing", &QBoxLayout::addSpacing, Arg("size"))
            .define_method("add_stretch", &QBoxLayout::addStretch, Arg("stretch") = static_cast<int>(0))
            .define_method("add_strut", &QBoxLayout::addStrut, Arg("strut"))
            .define_method("add_widget", &QBoxLayout::addWidget, Arg("widget"), Arg("stretch") = static_cast<int>(0), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method("count", &QBoxLayout::count)
            .define_method("direction", &QBoxLayout::direction)
            .define_method("insert_item", &QBoxLayout::insertItem, Arg("index"), Arg("item"))
            .define_method("insert_layout", &QBoxLayout::insertLayout, Arg("index"), Arg("layout"), Arg("stretch") = static_cast<int>(0))
            .define_method("insert_spacer_item", &QBoxLayout::insertSpacerItem, Arg("index"), Arg("item"))
            .define_method("insert_spacing", &QBoxLayout::insertSpacing, Arg("index"), Arg("size"))
            .define_method("insert_stretch", &QBoxLayout::insertStretch, Arg("index"), Arg("stretch") = static_cast<int>(0))
            .define_method("insert_widget", &QBoxLayout::insertWidget, Arg("index"), Arg("widget"), Arg("stretch") = static_cast<int>(0), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method("item_at", &QBoxLayout::itemAt, Arg("index"))
            .define_method("set_direction", &QBoxLayout::setDirection, Arg("direction"))
            .define_method("set_spacing", &QBoxLayout::setSpacing, Arg("spacing"))
            .define_method("set_stretch", &QBoxLayout::setStretch, Arg("index"), Arg("stretch"))
            .define_method<bool (QBoxLayout::*)(QLayout *, int)>("set_stretch_factor", &QBoxLayout::setStretchFactor, Arg("l"), Arg("stretch"))
            .define_method<bool (QBoxLayout::*)(QWidget *, int)>("set_stretch_factor", &QBoxLayout::setStretchFactor, Arg("w"), Arg("stretch"))
            .define_method("spacing", &QBoxLayout::spacing)
            .define_method("stretch", &QBoxLayout::stretch, Arg("index"))
            .define_method("take_at", &QBoxLayout::takeAt, Arg("index"));

    Data_Type<QBoxLayout::Direction> rb_cQBoxLayoutDirection =
        // RubyQt6::QtWidgets::QBoxLayout::Direction
        define_qenum_under<QBoxLayout::Direction>(rb_cQBoxLayout, "Direction");
        define_qenum_value_under(rb_cQBoxLayoutDirection, "LeftToRight", QBoxLayout::Direction::LeftToRight);
        define_qenum_value_under(rb_cQBoxLayoutDirection, "RightToLeft", QBoxLayout::Direction::RightToLeft);
        define_qenum_value_under(rb_cQBoxLayoutDirection, "TopToBottom", QBoxLayout::Direction::TopToBottom);
        define_qenum_value_under(rb_cQBoxLayoutDirection, "BottomToTop", QBoxLayout::Direction::BottomToTop);
        define_qenum_value_under(rb_cQBoxLayoutDirection, "Down", QBoxLayout::Direction::Down);
        define_qenum_value_under(rb_cQBoxLayoutDirection, "Up", QBoxLayout::Direction::Up);

    rb_cQHBoxLayout =
        // RubyQt6::QtWidgets::QHBoxLayout
        define_qlass_under<QHBoxLayout, QBoxLayout>(rb_mQt6QtWidgets, "QHBoxLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QHBoxLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QHBoxLayout>()).define_constructor(Constructor<QHBoxLayout, QWidget *>(), Arg("parent"));

    rb_cQVBoxLayout =
        // RubyQt6::QtWidgets::QVBoxLayout
        define_qlass_under<QVBoxLayout, QBoxLayout>(rb_mQt6QtWidgets, "QVBoxLayout")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QVBoxLayout::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QVBoxLayout>()).define_constructor(Constructor<QVBoxLayout, QWidget *>(), Arg("parent"));
}
