#include "qgridlayout-rb.hpp"
#include <qgridlayout.h>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQGridLayout;

void Init_qgridlayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQGridLayout =
        // RubyQt6::QtWidgets::QGridLayout
        define_class_under<QGridLayout, QLayout>(rb_mQt6QtWidgets, "QGridLayout")
            .define_constructor(Constructor<QGridLayout, QWidget *>(), Arg("parent") = static_cast<QWidget *>(nullptr))
            // Public Functions
            .define_method<void (QGridLayout::*)(QLayoutItem *, int, int, int, int, Qt::Alignment)>("add_item", &QGridLayout::addItem, Arg("item").takeOwnership(), Arg("row"), Arg("column"), Arg("row_span") = static_cast<int>(1), Arg("column_span") = static_cast<int>(1), Arg("") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QLayout *, int, int, Qt::Alignment)>("add_layout", &QGridLayout::addLayout, Arg("layout").takeOwnership(), Arg("row"), Arg("column"), Arg("") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QLayout *, int, int, int, int, Qt::Alignment)>("add_layout", &QGridLayout::addLayout, Arg("layout").takeOwnership(), Arg("row"), Arg("column"), Arg("row_span"), Arg("column_span"), Arg("") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QWidget *, int, int, Qt::Alignment)>("add_widget", &QGridLayout::addWidget, Arg("w").takeOwnership(), Arg("row"), Arg("column"), Arg("") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QWidget *, int, int, int, int, Qt::Alignment)>("add_widget", &QGridLayout::addWidget, Arg("w").takeOwnership(), Arg("row"), Arg("column"), Arg("row_span"), Arg("column_span"), Arg("") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method("cell_rect", &QGridLayout::cellRect, Arg("row"), Arg("column"))
            .define_method("column_count", &QGridLayout::columnCount)
            .define_method("column_minimum_width", &QGridLayout::columnMinimumWidth, Arg("column"))
            .define_method("column_stretch", &QGridLayout::columnStretch, Arg("column"))
            .define_method("get_item_position", &QGridLayout::getItemPosition, Arg("idx"), Arg("row"), Arg("column"), Arg("row_span"), Arg("column_span"))
            .define_method("horizontal_spacing", &QGridLayout::horizontalSpacing)
            .define_method("item_at_position", &QGridLayout::itemAtPosition, Arg("row"), Arg("column"))
            .define_method("origin_corner", &QGridLayout::originCorner)
            .define_method("row_count", &QGridLayout::rowCount)
            .define_method("row_minimum_height", &QGridLayout::rowMinimumHeight, Arg("row"))
            .define_method("row_stretch", &QGridLayout::rowStretch, Arg("row"))
            .define_method("set_column_minimum_width", &QGridLayout::setColumnMinimumWidth, Arg("column"), Arg("min_size"))
            .define_method("set_column_stretch", &QGridLayout::setColumnStretch, Arg("column"), Arg("stretch"))
            .define_method("set_default_positioning", &QGridLayout::setDefaultPositioning, Arg("n"), Arg("orient"))
            .define_method("set_horizontal_spacing", &QGridLayout::setHorizontalSpacing, Arg("spacing"))
            .define_method("set_origin_corner", &QGridLayout::setOriginCorner, Arg(""))
            .define_method("set_row_minimum_height", &QGridLayout::setRowMinimumHeight, Arg("row"), Arg("min_size"))
            .define_method("set_row_stretch", &QGridLayout::setRowStretch, Arg("row"), Arg("stretch"))
            .define_method("set_vertical_spacing", &QGridLayout::setVerticalSpacing, Arg("spacing"))
            .define_method("vertical_spacing", &QGridLayout::verticalSpacing);
}
