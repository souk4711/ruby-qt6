#include "qboxlayout-rb.hpp"
#include <QBoxLayout>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQBoxLayout;
Rice::Class rb_cQHBoxLayout;
Rice::Class rb_cQVBoxLayout;

void Init_QBoxLayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQBoxLayout = // Qt6::QWidgets::QBoxLayout
        define_class_under<QBoxLayout, QLayout>(rb_mQt6QtWidgets, "QBoxLayout")
            .define_constructor(Constructor<QBoxLayout, QBoxLayout::Direction, QWidget *>(), Arg(""), Arg("parent") = static_cast<QWidget *>(nullptr));

    Enum<QBoxLayout::Direction> rb_cQBoxLayoutDirection = // Qt6::QWidgets::QBoxLayout::Direction
        define_enum_under<QBoxLayout::Direction>("Direction", rb_cQBoxLayout)
            .define_value("LeftToRight", QBoxLayout::Direction::LeftToRight)
            .define_value("RightToLeft", QBoxLayout::Direction::RightToLeft)
            .define_value("TopToBottom", QBoxLayout::Direction::TopToBottom)
            .define_value("BottomToTop", QBoxLayout::Direction::BottomToTop)
            .define_value("Down", QBoxLayout::Direction::Down)
            .define_value("Up", QBoxLayout::Direction::Up);

    rb_cQHBoxLayout = //  Qt6::QWidgets::QHBoxLayout
        define_class_under<QHBoxLayout, QBoxLayout>(rb_mQt6QtWidgets, "QHBoxLayout")
            .define_constructor(Constructor<QHBoxLayout>())
            .define_constructor(Constructor<QHBoxLayout, QWidget *>(), Arg("parent"));

    rb_cQVBoxLayout = //  Qt6::QWidgets::QVBoxLayout
        define_class_under<QVBoxLayout, QBoxLayout>(rb_mQt6QtWidgets, "QVBoxLayout")
            .define_constructor(Constructor<QVBoxLayout>())
            .define_constructor(Constructor<QVBoxLayout, QWidget *>(), Arg("parent"));
}
