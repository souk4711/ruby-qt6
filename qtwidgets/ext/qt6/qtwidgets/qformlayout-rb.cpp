#include "qformlayout-rb.hpp"
#include <qformlayout.h>

#include <QWidget>

using namespace Rice;

Rice::Class rb_cQFormLayout;
Rice::Class rb_cQFormLayoutTakeRowResult;

void Init_qformlayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFormLayout =
        // RubyQt6::QtWidgets::QFormLayout
        define_class_under<QFormLayout, QLayout>(rb_mQt6QtWidgets, "QFormLayout")
            // Constructor
            .define_constructor(Constructor<QFormLayout, QWidget *>(), Arg("parent") = static_cast<QWidget *>(nullptr))
            // Public Functions
            .define_method<void (QFormLayout::*)(QLayout *)>("add_row", &QFormLayout::addRow, Arg("layout").takeOwnership())
            .define_method<void (QFormLayout::*)(QWidget *)>("add_row", &QFormLayout::addRow, Arg("widget").takeOwnership())
            .define_method<void (QFormLayout::*)(QWidget *, QLayout *)>("add_row", &QFormLayout::addRow, Arg("label").takeOwnership(), Arg("field").takeOwnership())
            .define_method<void (QFormLayout::*)(QWidget *, QWidget *)>("add_row", &QFormLayout::addRow, Arg("label").takeOwnership(), Arg("field").takeOwnership())
            .define_method<void (QFormLayout::*)(const QString &, QLayout *)>("add_row", &QFormLayout::addRow, Arg("label_text"), Arg("field").takeOwnership())
            .define_method<void (QFormLayout::*)(const QString &, QWidget *)>("add_row", &QFormLayout::addRow, Arg("label_text"), Arg("field").takeOwnership())
            .define_method("field_growth_policy", &QFormLayout::fieldGrowthPolicy)
            .define_method("form_alignment", &QFormLayout::formAlignment)
            .define_method("get_item_position", &QFormLayout::getItemPosition, Arg("index"), Arg("row_ptr"), Arg("role_ptr"))
            .define_method("get_layout_position", &QFormLayout::getLayoutPosition, Arg("layout"), Arg("row_ptr"), Arg("role_ptr"))
            .define_method("get_widget_position", &QFormLayout::getWidgetPosition, Arg("widget"), Arg("row_ptr"), Arg("role_ptr"))
            .define_method("horizontal_spacing", &QFormLayout::horizontalSpacing)
            .define_method<void (QFormLayout::*)(int, QLayout *)>("insert_row", &QFormLayout::insertRow, Arg("row"), Arg("layout").takeOwnership())
            .define_method<void (QFormLayout::*)(int, QWidget *)>("insert_row", &QFormLayout::insertRow, Arg("row"), Arg("widget").takeOwnership())
            .define_method<void (QFormLayout::*)(int, QWidget *, QLayout *)>("insert_row", &QFormLayout::insertRow, Arg("row"), Arg("label").takeOwnership(), Arg("field").takeOwnership())
            .define_method<void (QFormLayout::*)(int, QWidget *, QWidget *)>("insert_row", &QFormLayout::insertRow, Arg("row"), Arg("label").takeOwnership(), Arg("field").takeOwnership())
            .define_method<void (QFormLayout::*)(int, const QString &, QLayout *)>("insert_row", &QFormLayout::insertRow, Arg("row"), Arg("label_text"), Arg("field").takeOwnership())
            .define_method<void (QFormLayout::*)(int, const QString &, QWidget *)>("insert_row", &QFormLayout::insertRow, Arg("row"), Arg("label_text"), Arg("field").takeOwnership())
            .define_method<bool (QFormLayout::*)(QLayout *) const>("row_visible?", &QFormLayout::isRowVisible, Arg("layout"))
            .define_method<bool (QFormLayout::*)(QWidget *) const>("row_visible?", &QFormLayout::isRowVisible, Arg("widget"))
            .define_method<bool (QFormLayout::*)(int) const>("row_visible?", &QFormLayout::isRowVisible, Arg("row"))
            .define_method<QLayoutItem *(QFormLayout::*)(int) const>("item_at", &QFormLayout::itemAt, Arg("index"))
            .define_method<QLayoutItem *(QFormLayout::*)(int, QFormLayout::ItemRole) const>("item_at", &QFormLayout::itemAt, Arg("row"), Arg("role"))
            .define_method("label_alignment", &QFormLayout::labelAlignment)
            .define_method<QWidget *(QFormLayout::*)(QLayout *) const>("label_for_field", &QFormLayout::labelForField, Arg("field"))
            .define_method<QWidget *(QFormLayout::*)(QWidget *) const>("label_for_field", &QFormLayout::labelForField, Arg("field"))
            .define_method<void (QFormLayout::*)(QLayout *)>("remove_row", &QFormLayout::removeRow, Arg("layout"))
            .define_method<void (QFormLayout::*)(QWidget *)>("remove_row", &QFormLayout::removeRow, Arg("widget"))
            .define_method<void (QFormLayout::*)(int)>("remove_row", &QFormLayout::removeRow, Arg("row"))
            .define_method("row_count", &QFormLayout::rowCount)
            .define_method("row_wrap_policy", &QFormLayout::rowWrapPolicy)
            .define_method("set_field_growth_policy", &QFormLayout::setFieldGrowthPolicy, Arg("policy"))
            .define_method("set_form_alignment", &QFormLayout::setFormAlignment, Arg("alignment"))
            .define_method("set_horizontal_spacing", &QFormLayout::setHorizontalSpacing, Arg("spacing"))
            .define_method("set_item", &QFormLayout::setItem, Arg("row"), Arg("role"), Arg("item"))
            .define_method("set_label_alignment", &QFormLayout::setLabelAlignment, Arg("alignment"))
            .define_method("set_layout", &QFormLayout::setLayout, Arg("row"), Arg("role"), Arg("layout"))
            .define_method<void (QFormLayout::*)(QLayout *, bool)>("set_row_visible", &QFormLayout::setRowVisible, Arg("layout"), Arg("on"))
            .define_method<void (QFormLayout::*)(QWidget *, bool)>("set_row_visible", &QFormLayout::setRowVisible, Arg("widget"), Arg("on"))
            .define_method<void (QFormLayout::*)(int, bool)>("set_row_visible", &QFormLayout::setRowVisible, Arg("row"), Arg("on"))
            .define_method("set_row_wrap_policy", &QFormLayout::setRowWrapPolicy, Arg("policy"))
            .define_method("set_vertical_spacing", &QFormLayout::setVerticalSpacing, Arg("spacing"))
            .define_method("set_widget", &QFormLayout::setWidget, Arg("row"), Arg("role"), Arg("widget"))
            .define_method<QFormLayout::TakeRowResult (QFormLayout::*)(QLayout *)>("take_row", &QFormLayout::takeRow, Arg("layout"))
            .define_method<QFormLayout::TakeRowResult (QFormLayout::*)(QWidget *)>("take_row", &QFormLayout::takeRow, Arg("widget"))
            .define_method<QFormLayout::TakeRowResult (QFormLayout::*)(int)>("take_row", &QFormLayout::takeRow, Arg("row"))
            .define_method("vertical_spacing", &QFormLayout::verticalSpacing)
            // Reimplemented Public Functions
            .define_method("add_item", &QFormLayout::addItem, Arg("item"))
            .define_method("count", &QFormLayout::count)
            .define_method("expanding_directions", &QFormLayout::expandingDirections)
            .define_method("has_height_for_width", &QFormLayout::hasHeightForWidth)
            .define_method("height_for_width", &QFormLayout::heightForWidth, Arg("width"))
            .define_method("invalidate", &QFormLayout::invalidate)
            .define_method<QLayoutItem *(QFormLayout::*)(int) const>("item_at", &QFormLayout::itemAt, Arg("index"))
            .define_method("minimum_size", &QFormLayout::minimumSize)
            .define_method("set_geometry", &QFormLayout::setGeometry, Arg("rect"))
            .define_method("set_spacing", &QFormLayout::setSpacing, Arg(""))
            .define_method("size_hint", &QFormLayout::sizeHint)
            .define_method("spacing", &QFormLayout::spacing)
            .define_method("take_at", &QFormLayout::takeAt, Arg("index"));

    rb_cQFormLayoutTakeRowResult =
        // RubyQt6::QtWidgets::QFormLayout::TakeRowResult
        define_class_under<QFormLayout::TakeRowResult>(rb_cQFormLayout, "TakeRowResult")
            .define_attr("label_item", &QFormLayout::TakeRowResult::labelItem, Rice::AttrAccess::Read)
            .define_attr("field_item", &QFormLayout::TakeRowResult::fieldItem, Rice::AttrAccess::Read);

    Enum<QFormLayout::FieldGrowthPolicy> rb_cQFormLayoutFieldGrowthPolicy =
        // RubyQt6::QtWidgets::QFormLayout::FieldGrowthPolicy
        define_enum_under<QFormLayout::FieldGrowthPolicy>("FieldGrowthPolicy", rb_cQFormLayout)
            .define_value("FieldsStayAtSizeHint", QFormLayout::FieldGrowthPolicy::FieldsStayAtSizeHint)
            .define_value("ExpandingFieldsGrow", QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow)
            .define_value("AllNonFixedFieldsGrow", QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);

    Enum<QFormLayout::RowWrapPolicy> rb_cQFormLayoutRowWrapPolicy =
        // RubyQt6::QtWidgets::QFormLayout::RowWrapPolicy
        define_enum_under<QFormLayout::RowWrapPolicy>("RowWrapPolicy", rb_cQFormLayout)
            .define_value("DontWrapRows", QFormLayout::RowWrapPolicy::DontWrapRows)
            .define_value("WrapLongRows", QFormLayout::RowWrapPolicy::WrapLongRows)
            .define_value("WrapAllRows", QFormLayout::RowWrapPolicy::WrapAllRows);

    Enum<QFormLayout::ItemRole> rb_cQFormLayoutItemRole =
        // RubyQt6::QtWidgets::QFormLayout::ItemRole
        define_enum_under<QFormLayout::ItemRole>("ItemRole", rb_cQFormLayout)
            .define_value("LabelRole", QFormLayout::ItemRole::LabelRole)
            .define_value("FieldRole", QFormLayout::ItemRole::FieldRole)
            .define_value("SpanningRole", QFormLayout::ItemRole::SpanningRole);
}
