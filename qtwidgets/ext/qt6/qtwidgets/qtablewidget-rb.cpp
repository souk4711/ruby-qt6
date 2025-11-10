#include "qtablewidget-rb.hpp"
#include <qtablewidget.h>
#include <rice/qt6/qenum.hpp>

#include <QMimeData>

using namespace Rice;

Rice::Class rb_cQTableWidget;
Rice::Class rb_cQTableWidgetItem;
Rice::Class rb_cQTableWidgetSelectionRange;

void Init_qtablewidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQTableWidget =
        // RubyQt6::QtWidgets::QTableWidget
        define_class_under<QTableWidget, QTableView>(rb_mQt6QtWidgets, "QTableWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTableWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTableWidget, int, int, QWidget *>(), Arg("rows"), Arg("columns"), Arg("parent"))
            // Public Functions
            .define_method("cell_widget", &QTableWidget::cellWidget, Arg("row"), Arg("column"))
            .define_method("close_persistent_editor", &QTableWidget::closePersistentEditor, Arg("item"))
            .define_method("column", &QTableWidget::column, Arg("item"))
            .define_method("column_count", &QTableWidget::columnCount)
            .define_method("current_column", &QTableWidget::currentColumn)
            .define_method("current_item", &QTableWidget::currentItem)
            .define_method("current_row", &QTableWidget::currentRow)
            .define_method("edit_item", &QTableWidget::editItem, Arg("item"))
            .define_method("find_items", &QTableWidget::findItems, Arg("text"), Arg("flags"))
            .define_method("horizontal_header_item", &QTableWidget::horizontalHeaderItem, Arg("column"))
            .define_method("index_from_item", &QTableWidget::indexFromItem, Arg("item"))
            .define_method<bool (QTableWidget::*)(QTableWidgetItem *) const>("persistent_editor_open?", &QTableWidget::isPersistentEditorOpen, Arg("item"))
            .define_method("sorting_enabled?", &QTableWidget::isSortingEnabled)
            .define_method("item", &QTableWidget::item, Arg("row"), Arg("column"))
            .define_method<QTableWidgetItem *(QTableWidget::*)(const QPoint &) const>("item_at", &QTableWidget::itemAt, Arg("p"))
            .define_method<QTableWidgetItem *(QTableWidget::*)(int, int) const>("item_at", &QTableWidget::itemAt, Arg("x"), Arg("y"))
            .define_method("item_from_index", &QTableWidget::itemFromIndex, Arg("index"))
            .define_method("item_prototype", &QTableWidget::itemPrototype)
            .define_method("items", &QTableWidget::items, Arg("data"))
            .define_method("open_persistent_editor", &QTableWidget::openPersistentEditor, Arg("item"))
            .define_method("remove_cell_widget", &QTableWidget::removeCellWidget, Arg("row"), Arg("column"))
            .define_method("row", &QTableWidget::row, Arg("item"))
            .define_method("row_count", &QTableWidget::rowCount)
            .define_method("selected_items", &QTableWidget::selectedItems)
            .define_method("selected_ranges", &QTableWidget::selectedRanges)
            .define_method("set_cell_widget", &QTableWidget::setCellWidget, Arg("row"), Arg("column"), Arg("widget"))
            .define_method("set_column_count", &QTableWidget::setColumnCount, Arg("columns"))
            .define_method<void (QTableWidget::*)(int, int)>("set_current_cell", &QTableWidget::setCurrentCell, Arg("row"), Arg("column"))
            .define_method<void (QTableWidget::*)(int, int, QItemSelectionModel::SelectionFlags)>("set_current_cell", &QTableWidget::setCurrentCell, Arg("row"), Arg("column"), Arg("command"))
            .define_method<void (QTableWidget::*)(QTableWidgetItem *)>("set_current_item", &QTableWidget::setCurrentItem, Arg("item"))
            .define_method<void (QTableWidget::*)(QTableWidgetItem *, QItemSelectionModel::SelectionFlags)>("set_current_item", &QTableWidget::setCurrentItem, Arg("item"), Arg("command"))
            .define_method("set_horizontal_header_item", &QTableWidget::setHorizontalHeaderItem, Arg("column"), Arg("item"))
            .define_method("set_horizontal_header_labels", &QTableWidget::setHorizontalHeaderLabels, Arg("labels"))
            .define_method("set_item", &QTableWidget::setItem, Arg("row"), Arg("column"), Arg("item"))
            .define_method("set_item_prototype", &QTableWidget::setItemPrototype, Arg("item"))
            .define_method("set_range_selected", &QTableWidget::setRangeSelected, Arg("range"), Arg("select"))
            .define_method("set_row_count", &QTableWidget::setRowCount, Arg("rows"))
            .define_method("set_sorting_enabled", &QTableWidget::setSortingEnabled, Arg("enable"))
            .define_method("set_vertical_header_item", &QTableWidget::setVerticalHeaderItem, Arg("row"), Arg("item"))
            .define_method("set_vertical_header_labels", &QTableWidget::setVerticalHeaderLabels, Arg("labels"))
            .define_method("sort_items", &QTableWidget::sortItems, Arg("column"), Arg("order") = static_cast<Qt::SortOrder>(Qt::AscendingOrder))
            .define_method("take_horizontal_header_item", &QTableWidget::takeHorizontalHeaderItem, Arg("column"))
            .define_method("take_item", &QTableWidget::takeItem, Arg("row"), Arg("column"))
            .define_method("take_vertical_header_item", &QTableWidget::takeVerticalHeaderItem, Arg("row"))
            .define_method("vertical_header_item", &QTableWidget::verticalHeaderItem, Arg("row"))
            .define_method("visual_column", &QTableWidget::visualColumn, Arg("logical_column"))
            .define_method("visual_item_rect", &QTableWidget::visualItemRect, Arg("item"))
            .define_method("visual_row", &QTableWidget::visualRow, Arg("logical_row"))
            // Public Slots
            .define_method("clear", &QTableWidget::clear)
            .define_method("clear_contents", &QTableWidget::clearContents)
            .define_method("insert_column", &QTableWidget::insertColumn, Arg("column"))
            .define_method("insert_row", &QTableWidget::insertRow, Arg("row"))
            .define_method("remove_column", &QTableWidget::removeColumn, Arg("column"))
            .define_method("remove_row", &QTableWidget::removeRow, Arg("row"))
            .define_method("scroll_to_item", &QTableWidget::scrollToItem, Arg("item"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            // Signals
            .define_method("cell_activated", &QTableWidget::cellActivated, Arg("row"), Arg("column"))
            .define_method("cell_changed", &QTableWidget::cellChanged, Arg("row"), Arg("column"))
            .define_method("cell_clicked", &QTableWidget::cellClicked, Arg("row"), Arg("column"))
            .define_method("cell_double_clicked", &QTableWidget::cellDoubleClicked, Arg("row"), Arg("column"))
            .define_method("cell_entered", &QTableWidget::cellEntered, Arg("row"), Arg("column"))
            .define_method("cell_pressed", &QTableWidget::cellPressed, Arg("row"), Arg("column"))
            .define_method("current_cell_changed", &QTableWidget::currentCellChanged, Arg("current_row"), Arg("current_column"), Arg("previous_row"), Arg("previous_column"))
            .define_method("current_item_changed", &QTableWidget::currentItemChanged, Arg("current"), Arg("previous"))
            .define_method("item_activated", &QTableWidget::itemActivated, Arg("item"))
            .define_method("item_changed", &QTableWidget::itemChanged, Arg("item"))
            .define_method("item_clicked", &QTableWidget::itemClicked, Arg("item"))
            .define_method("item_double_clicked", &QTableWidget::itemDoubleClicked, Arg("item"))
            .define_method("item_entered", &QTableWidget::itemEntered, Arg("item"))
            .define_method("item_pressed", &QTableWidget::itemPressed, Arg("item"))
            .define_method("item_selection_changed", &QTableWidget::itemSelectionChanged);

    rb_cQTableWidgetItem =
        // RubyQt6::QtWidgets::QTableWidgetItem
        define_class_under<QTableWidgetItem>(rb_mQt6QtWidgets, "QTableWidgetItem")
            // RubyQt6-Defined Functions
            .define_singleton_function("_take_ownership_from_ruby", [](QTableWidgetItem *) -> void {}, Arg("item").takeOwnership())
            // Constructor
            .define_constructor(Constructor<QTableWidgetItem>())
            .define_constructor(Constructor<QTableWidgetItem, const QString &>(), Arg("text"))
            .define_constructor(Constructor<QTableWidgetItem, const QIcon &, const QString &>(), Arg("icon"), Arg("text"))
            // Public Functions
            .define_method("background", &QTableWidgetItem::background)
            .define_method("check_state", &QTableWidgetItem::checkState)
            .define_method("clone", &QTableWidgetItem::clone)
            .define_method("column", &QTableWidgetItem::column)
            .define_method("data", &QTableWidgetItem::data, Arg("role"))
            .define_method("flags", &QTableWidgetItem::flags)
            .define_method("font", &QTableWidgetItem::font)
            .define_method("foreground", &QTableWidgetItem::foreground)
            .define_method("icon", &QTableWidgetItem::icon)
            .define_method("selected?", &QTableWidgetItem::isSelected)
            .define_method("read", &QTableWidgetItem::read, Arg("in"))
            .define_method("row", &QTableWidgetItem::row)
            .define_method("set_background", &QTableWidgetItem::setBackground, Arg("brush"))
            .define_method("set_check_state", &QTableWidgetItem::setCheckState, Arg("state"))
            .define_method("set_data", &QTableWidgetItem::setData, Arg("role"), Arg("value"))
            .define_method("_set_flags", &QTableWidgetItem::setFlags, Arg("flags"))
            .define_method("set_font", &QTableWidgetItem::setFont, Arg("font"))
            .define_method("set_foreground", &QTableWidgetItem::setForeground, Arg("brush"))
            .define_method("set_icon", &QTableWidgetItem::setIcon, Arg("icon"))
            .define_method("set_selected", &QTableWidgetItem::setSelected, Arg("select"))
            .define_method("set_size_hint", &QTableWidgetItem::setSizeHint, Arg("size"))
            .define_method("set_status_tip", &QTableWidgetItem::setStatusTip, Arg("status_tip"))
            .define_method("set_text", &QTableWidgetItem::setText, Arg("text"))
            .define_method<void (QTableWidgetItem::*)(Qt::Alignment)>("set_text_alignment", &QTableWidgetItem::setTextAlignment, Arg("alignment"))
            .define_method<void (QTableWidgetItem::*)(Qt::AlignmentFlag)>("set_text_alignment", &QTableWidgetItem::setTextAlignment, Arg("alignment"))
            .define_method("set_tool_tip", &QTableWidgetItem::setToolTip, Arg("tool_tip"))
            .define_method("set_whats_this", &QTableWidgetItem::setWhatsThis, Arg("whats_this"))
            .define_method("status_tip", &QTableWidgetItem::statusTip)
            .define_method("table_widget", &QTableWidgetItem::tableWidget)
            .define_method("text", &QTableWidgetItem::text)
            .define_method("text_alignment", &QTableWidgetItem::textAlignment)
            .define_method("tool_tip", &QTableWidgetItem::toolTip)
            .define_method("type", &QTableWidgetItem::type)
            .define_method("whats_this", &QTableWidgetItem::whatsThis)
            .define_method("write", &QTableWidgetItem::write, Arg("out"));

    Data_Type<QTableWidgetItem::ItemType> rb_cQTableWidgetItemItemType =
        // RubyQt6::QtWidgets::QTableWidgetItem::ItemType
        define_qenum_under<QTableWidgetItem::ItemType>(rb_cQTableWidgetItem, "ItemType");
        define_qenum_value_under(rb_cQTableWidgetItemItemType, "Type", QTableWidgetItem::ItemType::Type);
        define_qenum_value_under(rb_cQTableWidgetItemItemType, "UserType", QTableWidgetItem::ItemType::UserType);

    rb_cQTableWidgetSelectionRange =
        // RubyQt6::QtWidgets::QTableWidgetSelectionRange
        define_class_under<QTableWidgetSelectionRange>(rb_mQt6QtWidgets, "QTableWidgetSelectionRange")
            // Public Functions
            .define_method("bottom_row", &QTableWidgetSelectionRange::bottomRow)
            .define_method("column_count", &QTableWidgetSelectionRange::columnCount)
            .define_method("left_column", &QTableWidgetSelectionRange::leftColumn)
            .define_method("right_column", &QTableWidgetSelectionRange::rightColumn)
            .define_method("row_count", &QTableWidgetSelectionRange::rowCount)
            .define_method("top_row", &QTableWidgetSelectionRange::topRow);
}
