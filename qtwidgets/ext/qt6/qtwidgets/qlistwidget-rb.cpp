#include "qlistwidget-rb.hpp"
#include <qlistwidget.h>

#include <QMimeData>

using namespace Rice;

Rice::Class rb_cQListWidget;
Rice::Class rb_cQListWidgetItem;

void Init_qlistwidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQListWidget =
        // RubyQt6::QtWidgets::QListWidget
        define_class_under<QListWidget, QListView>(rb_mQt6QtWidgets, "QListWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QListWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QListWidget, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method<void (QListWidget::*)(QListWidgetItem *)>("add_item", &QListWidget::addItem, Arg("item").takeOwnership())
            .define_method<void (QListWidget::*)(const QString &)>("add_item", &QListWidget::addItem, Arg("label"))
            .define_method("add_items", &QListWidget::addItems, Arg("labels"))
            .define_method("close_persistent_editor", &QListWidget::closePersistentEditor, Arg("item"))
            .define_method("count", &QListWidget::count)
            .define_method("current_item", &QListWidget::currentItem)
            .define_method("current_row", &QListWidget::currentRow)
            .define_method("edit_item", &QListWidget::editItem, Arg("item"))
            .define_method("find_items", &QListWidget::findItems, Arg("text"), Arg("flags"))
            .define_method("index_from_item", &QListWidget::indexFromItem, Arg("item"))
            .define_method<void (QListWidget::*)(int, QListWidgetItem *)>("insert_item", &QListWidget::insertItem, Arg("row"), Arg("item").takeOwnership())
            .define_method<void (QListWidget::*)(int, const QString &)>("insert_item", &QListWidget::insertItem, Arg("row"), Arg("label"))
            .define_method("insert_items", &QListWidget::insertItems, Arg("row"), Arg("labels"))
            .define_method<bool (QListWidget::*)(QListWidgetItem *) const>("persistent_editor_open?", &QListWidget::isPersistentEditorOpen, Arg("item"))
            .define_method("sorting_enabled?", &QListWidget::isSortingEnabled)
            .define_method("item", &QListWidget::item, Arg("row"))
            .define_method<QListWidgetItem *(QListWidget::*)(const QPoint &) const>("item_at", &QListWidget::itemAt, Arg("p"))
            .define_method<QListWidgetItem *(QListWidget::*)(int, int) const>("item_at", &QListWidget::itemAt, Arg("x"), Arg("y"))
            .define_method("item_from_index", &QListWidget::itemFromIndex, Arg("index"))
            .define_method("item_widget", &QListWidget::itemWidget, Arg("item"))
            .define_method("items", &QListWidget::items, Arg("data"))
            .define_method("open_persistent_editor", &QListWidget::openPersistentEditor, Arg("item"))
            .define_method("remove_item_widget", &QListWidget::removeItemWidget, Arg("item"))
            .define_method("row", &QListWidget::row, Arg("item"))
            .define_method("selected_items", &QListWidget::selectedItems)
            .define_method<void (QListWidget::*)(QListWidgetItem *)>("set_current_item", &QListWidget::setCurrentItem, Arg("item"))
            .define_method<void (QListWidget::*)(QListWidgetItem *, QItemSelectionModel::SelectionFlags)>("set_current_item", &QListWidget::setCurrentItem, Arg("item"), Arg("command"))
            .define_method<void (QListWidget::*)(int)>("set_current_row", &QListWidget::setCurrentRow, Arg("row"))
            .define_method<void (QListWidget::*)(int, QItemSelectionModel::SelectionFlags)>("set_current_row", &QListWidget::setCurrentRow, Arg("row"), Arg("command"))
            .define_method("set_item_widget", &QListWidget::setItemWidget, Arg("item"), Arg("widget"))
            .define_method("set_selection_model", &QListWidget::setSelectionModel, Arg("selection_model"))
            .define_method("set_sorting_enabled", &QListWidget::setSortingEnabled, Arg("enable"))
            .define_method("sort_items", &QListWidget::sortItems, Arg("order") = static_cast<Qt::SortOrder>(Qt::AscendingOrder))
            .define_method("take_item", &QListWidget::takeItem, Arg("row"), Return().takeOwnership())
            .define_method("visual_item_rect", &QListWidget::visualItemRect, Arg("item"))
            // Public Slots
            .define_method("clear", &QListWidget::clear)
            .define_method("scroll_to_item", &QListWidget::scrollToItem, Arg("item"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            // Signals
            .define_method("current_item_changed", &QListWidget::currentItemChanged, Arg("current"), Arg("previous"))
            .define_method("current_row_changed", &QListWidget::currentRowChanged, Arg("current_row"))
            .define_method("current_text_changed", &QListWidget::currentTextChanged, Arg("current_text"))
            .define_method("item_activated", &QListWidget::itemActivated, Arg("item"))
            .define_method("item_changed", &QListWidget::itemChanged, Arg("item"))
            .define_method("item_clicked", &QListWidget::itemClicked, Arg("item"))
            .define_method("item_double_clicked", &QListWidget::itemDoubleClicked, Arg("item"))
            .define_method("item_entered", &QListWidget::itemEntered, Arg("item"))
            .define_method("item_pressed", &QListWidget::itemPressed, Arg("item"))
            .define_method("item_selection_changed", &QListWidget::itemSelectionChanged);

    rb_cQListWidgetItem =
        // RubyQt6::QtWidgets::QListWidgetItem
        define_class_under<QListWidgetItem>(rb_mQt6QtWidgets, "QListWidgetItem")
            // Constructor
            .define_constructor(Constructor<QListWidgetItem>())
            .define_constructor(Constructor<QListWidgetItem, const QString &>(), Arg("text"))
            .define_constructor(Constructor<QListWidgetItem, const QIcon &, const QString &>(), Arg("icon"), Arg("text"))
            // Public Functions
            .define_method("background", &QListWidgetItem::background)
            .define_method("check_state", &QListWidgetItem::checkState)
            .define_method("clone", &QListWidgetItem::clone)
            .define_method("data", &QListWidgetItem::data, Arg("role"))
            .define_method("flags", &QListWidgetItem::flags)
            .define_method("font", &QListWidgetItem::font)
            .define_method("foreground", &QListWidgetItem::foreground)
            .define_method("icon", &QListWidgetItem::icon)
            .define_method("hidden?", &QListWidgetItem::isHidden)
            .define_method("selected?", &QListWidgetItem::isSelected)
            .define_method("list_widget", &QListWidgetItem::listWidget)
            .define_method("read", &QListWidgetItem::read, Arg("in"))
            .define_method("set_background", &QListWidgetItem::setBackground, Arg("brush"))
            .define_method("set_check_state", &QListWidgetItem::setCheckState, Arg("state"))
            .define_method("set_data", &QListWidgetItem::setData, Arg("role"), Arg("value"))
            .define_method("set_flags", &QListWidgetItem::setFlags, Arg("flags"))
            .define_method("set_font", &QListWidgetItem::setFont, Arg("font"))
            .define_method("set_foreground", &QListWidgetItem::setForeground, Arg("brush"))
            .define_method("set_hidden", &QListWidgetItem::setHidden, Arg("hide"))
            .define_method("set_icon", &QListWidgetItem::setIcon, Arg("icon"))
            .define_method("set_selected", &QListWidgetItem::setSelected, Arg("select"))
            .define_method("set_size_hint", &QListWidgetItem::setSizeHint, Arg("size"))
            .define_method("set_status_tip", &QListWidgetItem::setStatusTip, Arg("status_tip"))
            .define_method("set_text", &QListWidgetItem::setText, Arg("text"))
            .define_method<void (QListWidgetItem::*)(Qt::Alignment)>("set_text_alignment", &QListWidgetItem::setTextAlignment, Arg("alignment"))
            .define_method<void (QListWidgetItem::*)(Qt::AlignmentFlag)>("set_text_alignment", &QListWidgetItem::setTextAlignment, Arg("alignment"))
            .define_method("set_tool_tip", &QListWidgetItem::setToolTip, Arg("tool_tip"))
            .define_method("set_whats_this", &QListWidgetItem::setWhatsThis, Arg("whats_this"))
            .define_method("size_hint", &QListWidgetItem::sizeHint)
            .define_method("status_tip", &QListWidgetItem::statusTip)
            .define_method("text", &QListWidgetItem::text)
            .define_method("text_alignment", &QListWidgetItem::textAlignment)
            .define_method("tool_tip", &QListWidgetItem::toolTip)
            .define_method("type", &QListWidgetItem::type)
            .define_method("whats_this", &QListWidgetItem::whatsThis)
            .define_method("write", &QListWidgetItem::write, Arg("out"));

    Enum<QListWidgetItem::ItemType> rb_cQListWidgetItemItemType =
        // RubyQt6::QtWidgets::QListWidgetItem::ItemType
        define_enum_under<QListWidgetItem::ItemType>("ItemType", rb_cQListWidgetItem)
            .define_value("Type", QListWidgetItem::ItemType::Type)
            .define_value("UserType", QListWidgetItem::ItemType::UserType);
}
