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
            .define_method("_horizontal_spacing", &QGridLayout::horizontalSpacing)
            .define_method("_vertical_spacing", &QGridLayout::verticalSpacing)
            .define_method("_set_horizontal_spacing", &QGridLayout::setHorizontalSpacing, Arg("spacing"))
            .define_method("_set_vertical_spacing", &QGridLayout::setVerticalSpacing, Arg("spacing"))
            .define_method<void (QGridLayout::*)(QLayoutItem *, int, int, int, int, Qt::Alignment)>("_add_item", &QGridLayout::addItem, Arg("item").takeOwnership(), Arg("row"), Arg("column"), Arg("row_span") = static_cast<int>(1), Arg("column_span") = static_cast<int>(1), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QLayout *, int, int, Qt::Alignment)>("_add_layout", &QGridLayout::addLayout, Arg("layout").takeOwnership(), Arg("row"), Arg("column"), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QLayout *, int, int, int, int, Qt::Alignment)>("_add_layout", &QGridLayout::addLayout, Arg("layout").takeOwnership(), Arg("row"), Arg("column"), Arg("row_span"), Arg("column_span"), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QWidget *, int, int, Qt::Alignment)>("_add_widget", &QGridLayout::addWidget, Arg("widget").takeOwnership(), Arg("row"), Arg("column"), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method<void (QGridLayout::*)(QWidget *, int, int, int, int, Qt::Alignment)>("_add_widget", &QGridLayout::addWidget, Arg("widget").takeOwnership(), Arg("row"), Arg("column"), Arg("row_span"), Arg("column_span"), Arg("alignment") = static_cast<Qt::Alignment>(Qt::Alignment()))
            .define_method("_origin_corner", &QGridLayout::originCorner)
            .define_method("_row_stretch", &QGridLayout::rowStretch, Arg("row"))
            .define_method("_column_stretch", &QGridLayout::columnStretch, Arg("column"))
            .define_method("_row_minimum_height", &QGridLayout::rowMinimumHeight, Arg("row"))
            .define_method("_column_minimum_width", &QGridLayout::columnMinimumWidth, Arg("column"))
            .define_method("_set_origin_corner", &QGridLayout::setOriginCorner, Arg("corner"))
            .define_method("_set_row_stretch", &QGridLayout::setRowStretch, Arg("row"), Arg("stretch"))
            .define_method("_set_column_stretch", &QGridLayout::setColumnStretch, Arg("column"), Arg("stretch"))
            .define_method("_set_row_minimum_height", &QGridLayout::setRowMinimumHeight, Arg("row"), Arg("height"))
            .define_method("_set_column_minimum_width", &QGridLayout::setColumnMinimumWidth, Arg("column"), Arg("width"))
            .define_method("_item_at_position", &QGridLayout::itemAtPosition, Arg("row"), Arg("column"))
            .define_method("_row_count", &QGridLayout::rowCount)
            .define_method("_column_count", &QGridLayout::columnCount);
}
