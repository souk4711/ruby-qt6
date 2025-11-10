#include "qtreewidget-rb.hpp"
#include <qtreewidget.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQTreeWidget;
Rice::Class rb_cQTreeWidgetItem;

void Init_qtreewidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQTreeWidget =
        // RubyQt6::QtWidgets::QTreeWidget
        define_class_under<QTreeWidget, QTreeView>(rb_mQt6QtWidgets, "QTreeWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTreeWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTreeWidget, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("add_top_level_item", &QTreeWidget::addTopLevelItem, Arg("item"))
            // .define_method("add_top_level_items", &QTreeWidget::addTopLevelItems, Arg("items"))
            .define_method("close_persistent_editor", &QTreeWidget::closePersistentEditor, Arg("item"), Arg("column") = static_cast<int>(0))
            .define_method("column_count", &QTreeWidget::columnCount)
            .define_method("current_column", &QTreeWidget::currentColumn)
            .define_method("current_item", &QTreeWidget::currentItem)
            .define_method("edit_item", &QTreeWidget::editItem, Arg("item"), Arg("column") = static_cast<int>(0))
            .define_method("find_items", &QTreeWidget::findItems, Arg("text"), Arg("flags"), Arg("column") = static_cast<int>(0))
            .define_method("header_item", &QTreeWidget::headerItem)
            .define_method("index_from_item", &QTreeWidget::indexFromItem, Arg("item"), Arg("column") = static_cast<int>(0))
            .define_method("index_of_top_level_item", &QTreeWidget::indexOfTopLevelItem, Arg("item"))
            .define_method("insert_top_level_item", &QTreeWidget::insertTopLevelItem, Arg("index"), Arg("item"))
            // .define_method("insert_top_level_items", &QTreeWidget::insertTopLevelItems, Arg("index"), Arg("items"))
            .define_method("invisible_root_item", &QTreeWidget::invisibleRootItem)
            .define_method<bool (QTreeWidget::*)(QTreeWidgetItem *, int) const>("persistent_editor_open?", &QTreeWidget::isPersistentEditorOpen, Arg("item"), Arg("column") = static_cast<int>(0))
            .define_method("item_above", &QTreeWidget::itemAbove, Arg("item"))
            .define_method<QTreeWidgetItem *(QTreeWidget::*)(const QPoint &) const>("item_at", &QTreeWidget::itemAt, Arg("p"))
            .define_method<QTreeWidgetItem *(QTreeWidget::*)(int, int) const>("item_at", &QTreeWidget::itemAt, Arg("x"), Arg("y"))
            .define_method("item_below", &QTreeWidget::itemBelow, Arg("item"))
            .define_method("item_from_index", &QTreeWidget::itemFromIndex, Arg("index"))
            .define_method("item_widget", &QTreeWidget::itemWidget, Arg("item"), Arg("column"))
            .define_method("open_persistent_editor", &QTreeWidget::openPersistentEditor, Arg("item"), Arg("column") = static_cast<int>(0))
            .define_method("remove_item_widget", &QTreeWidget::removeItemWidget, Arg("item"), Arg("column"))
            .define_method("selected_items", &QTreeWidget::selectedItems)
            .define_method("set_column_count", &QTreeWidget::setColumnCount, Arg("columns"))
            .define_method<void (QTreeWidget::*)(QTreeWidgetItem *)>("set_current_item", &QTreeWidget::setCurrentItem, Arg("item"))
            .define_method<void (QTreeWidget::*)(QTreeWidgetItem *, int)>("set_current_item", &QTreeWidget::setCurrentItem, Arg("item"), Arg("column"))
            .define_method<void (QTreeWidget::*)(QTreeWidgetItem *, int, QItemSelectionModel::SelectionFlags)>("set_current_item", &QTreeWidget::setCurrentItem, Arg("item"), Arg("column"), Arg("command"))
            .define_method("set_header_item", &QTreeWidget::setHeaderItem, Arg("item"))
            .define_method("set_header_label", &QTreeWidget::setHeaderLabel, Arg("label"))
            .define_method("set_header_labels", &QTreeWidget::setHeaderLabels, Arg("labels"))
            .define_method("set_item_widget", &QTreeWidget::setItemWidget, Arg("item"), Arg("column"), Arg("widget"))
            .define_method("set_selection_model", &QTreeWidget::setSelectionModel, Arg("selection_model"))
            .define_method("sort_column", &QTreeWidget::sortColumn)
            .define_method("sort_items", &QTreeWidget::sortItems, Arg("column"), Arg("order"))
            .define_method("take_top_level_item", &QTreeWidget::takeTopLevelItem, Arg("index"))
            .define_method("top_level_item", &QTreeWidget::topLevelItem, Arg("index"))
            .define_method("top_level_item_count", &QTreeWidget::topLevelItemCount)
            .define_method("visual_item_rect", &QTreeWidget::visualItemRect, Arg("item"))
            // Public Slots
            .define_method("clear", &QTreeWidget::clear)
            .define_method("collapse_item", &QTreeWidget::collapseItem, Arg("item"))
            .define_method("expand_item", &QTreeWidget::expandItem, Arg("item"))
            .define_method("scroll_to_item", &QTreeWidget::scrollToItem, Arg("item"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            // Signals
            .define_method("current_item_changed", &QTreeWidget::currentItemChanged, Arg("current"), Arg("previous"))
            .define_method("item_activated", &QTreeWidget::itemActivated, Arg("item"), Arg("column"))
            .define_method("item_changed", &QTreeWidget::itemChanged, Arg("item"), Arg("column"))
            .define_method("item_clicked", &QTreeWidget::itemClicked, Arg("item"), Arg("column"))
            .define_method("item_collapsed", &QTreeWidget::itemCollapsed, Arg("item"))
            .define_method("item_double_clicked", &QTreeWidget::itemDoubleClicked, Arg("item"), Arg("column"))
            .define_method("item_entered", &QTreeWidget::itemEntered, Arg("item"), Arg("column"))
            .define_method("item_expanded", &QTreeWidget::itemExpanded, Arg("item"))
            .define_method("item_pressed", &QTreeWidget::itemPressed, Arg("item"), Arg("column"))
            .define_method("item_selection_changed", &QTreeWidget::itemSelectionChanged);

    rb_cQTreeWidgetItem =
        // RubyQt6::QtWidgets::QTreeWidgetItem
        define_class_under<QTreeWidgetItem>(rb_mQt6QtWidgets, "QTreeWidgetItem")
            // RubyQt6-Defined Functions
            .define_singleton_function("_take_ownership_from_ruby", [](QTreeWidgetItem *) -> void {}, Arg("item").takeOwnership())
            // Constructor
            .define_constructor(Constructor<QTreeWidgetItem>())
            .define_constructor(Constructor<QTreeWidgetItem, QTreeWidget *>(), Arg("treeview"))
            .define_constructor(Constructor<QTreeWidgetItem, QTreeWidgetItem *>(), Arg("parent"))
            .define_constructor(Constructor<QTreeWidgetItem, QTreeWidget *, QTreeWidgetItem *>(), Arg("treeview"), Arg("after"))
            .define_constructor(Constructor<QTreeWidgetItem, QTreeWidgetItem *, QTreeWidgetItem *>(), Arg("parent"), Arg("after"))
            .define_constructor(Constructor<QTreeWidgetItem, const QStringList &>(), Arg("strings"))
            .define_constructor(Constructor<QTreeWidgetItem, QTreeWidget *, const QStringList &>(), Arg("treeview"), Arg("strings"))
            .define_constructor(Constructor<QTreeWidgetItem, QTreeWidgetItem *, const QStringList &>(), Arg("parent"), Arg("strings"))
            // Public Functions
            .define_method("add_child", &QTreeWidgetItem::addChild, Arg("child"))
            // .define_method("add_children", &QTreeWidgetItem::addChildren, Arg("children"))
            .define_method("background", &QTreeWidgetItem::background, Arg("column"))
            .define_method("check_state", &QTreeWidgetItem::checkState, Arg("column"))
            .define_method("child", &QTreeWidgetItem::child, Arg("index"))
            .define_method("child_count", &QTreeWidgetItem::childCount)
            .define_method("child_indicator_policy", &QTreeWidgetItem::childIndicatorPolicy)
            .define_method("clone", &QTreeWidgetItem::clone)
            .define_method("column_count", &QTreeWidgetItem::columnCount)
            .define_method("data", &QTreeWidgetItem::data, Arg("column"), Arg("role"))
            .define_method("flags", &QTreeWidgetItem::flags)
            .define_method("font", &QTreeWidgetItem::font, Arg("column"))
            .define_method("foreground", &QTreeWidgetItem::foreground, Arg("column"))
            .define_method("icon", &QTreeWidgetItem::icon, Arg("column"))
            .define_method("index_of_child", &QTreeWidgetItem::indexOfChild, Arg("child"))
            .define_method("insert_child", &QTreeWidgetItem::insertChild, Arg("index"), Arg("child"))
            // .define_method("insert_children", &QTreeWidgetItem::insertChildren, Arg("index"), Arg("children"))
            .define_method("disabled?", &QTreeWidgetItem::isDisabled)
            .define_method("expanded?", &QTreeWidgetItem::isExpanded)
            .define_method("first_column_spanned?", &QTreeWidgetItem::isFirstColumnSpanned)
            .define_method("hidden?", &QTreeWidgetItem::isHidden)
            .define_method("selected?", &QTreeWidgetItem::isSelected)
            .define_method("parent", &QTreeWidgetItem::parent)
            .define_method("read", &QTreeWidgetItem::read, Arg("in"))
            .define_method("remove_child", &QTreeWidgetItem::removeChild, Arg("child"))
            .define_method("set_background", &QTreeWidgetItem::setBackground, Arg("column"), Arg("brush"))
            .define_method("set_check_state", &QTreeWidgetItem::setCheckState, Arg("column"), Arg("state"))
            .define_method("set_child_indicator_policy", &QTreeWidgetItem::setChildIndicatorPolicy, Arg("policy"))
            .define_method("set_data", &QTreeWidgetItem::setData, Arg("column"), Arg("role"), Arg("value"))
            .define_method("set_disabled", &QTreeWidgetItem::setDisabled, Arg("disabled"))
            .define_method("set_expanded", &QTreeWidgetItem::setExpanded, Arg("expand"))
            .define_method("set_first_column_spanned", &QTreeWidgetItem::setFirstColumnSpanned, Arg("span"))
            .define_method("set_flags", &QTreeWidgetItem::setFlags, Arg("flags"))
            .define_method("set_font", &QTreeWidgetItem::setFont, Arg("column"), Arg("font"))
            .define_method("set_foreground", &QTreeWidgetItem::setForeground, Arg("column"), Arg("brush"))
            .define_method("set_hidden", &QTreeWidgetItem::setHidden, Arg("hide"))
            .define_method("set_icon", &QTreeWidgetItem::setIcon, Arg("column"), Arg("icon"))
            .define_method("set_selected", &QTreeWidgetItem::setSelected, Arg("select"))
            .define_method("set_size_hint", &QTreeWidgetItem::setSizeHint, Arg("column"), Arg("size"))
            .define_method("set_status_tip", &QTreeWidgetItem::setStatusTip, Arg("column"), Arg("status_tip"))
            .define_method("set_text", &QTreeWidgetItem::setText, Arg("column"), Arg("text"))
            .define_method<void (QTreeWidgetItem::*)(int, Qt::Alignment)>("set_text_alignment", &QTreeWidgetItem::setTextAlignment, Arg("column"), Arg("alignment"))
            .define_method<void (QTreeWidgetItem::*)(int, Qt::AlignmentFlag)>("set_text_alignment", &QTreeWidgetItem::setTextAlignment, Arg("column"), Arg("alignment"))
            .define_method("set_tool_tip", &QTreeWidgetItem::setToolTip, Arg("column"), Arg("tool_tip"))
            .define_method("set_whats_this", &QTreeWidgetItem::setWhatsThis, Arg("column"), Arg("whats_this"))
            .define_method<void (QTreeWidgetItem::*)(int, Qt::SortOrder)>("sort_children", &QTreeWidgetItem::sortChildren, Arg("column"), Arg("order"))
            .define_method("status_tip", &QTreeWidgetItem::statusTip, Arg("column"))
            .define_method("take_child", &QTreeWidgetItem::takeChild, Arg("index"))
            // .define_method("take_children", &QTreeWidgetItem::takeChildren)
            .define_method("text", &QTreeWidgetItem::text, Arg("column"))
            .define_method("text_alignment", &QTreeWidgetItem::textAlignment, Arg("column"))
            .define_method("tool_tip", &QTreeWidgetItem::toolTip, Arg("column"))
            .define_method("tree_widget", &QTreeWidgetItem::treeWidget)
            .define_method("type", &QTreeWidgetItem::type)
            .define_method("whats_this", &QTreeWidgetItem::whatsThis, Arg("column"))
            .define_method("write", &QTreeWidgetItem::write, Arg("out"));

    Data_Type<QTreeWidgetItem::ChildIndicatorPolicy> rb_cQTreeWidgetItemChildIndicatorPolicy =
        // RubyQt6::QtWidgets::QTreeWidgetItem::ChildIndicatorPolicy
        define_qenum_under<QTreeWidgetItem::ChildIndicatorPolicy>(rb_cQTreeWidgetItem, "ChildIndicatorPolicy");
        define_qenum_value_under(rb_cQTreeWidgetItemChildIndicatorPolicy, "ShowIndicator", QTreeWidgetItem::ChildIndicatorPolicy::ShowIndicator);
        define_qenum_value_under(rb_cQTreeWidgetItemChildIndicatorPolicy, "DontShowIndicator", QTreeWidgetItem::ChildIndicatorPolicy::DontShowIndicator);
        define_qenum_value_under(rb_cQTreeWidgetItemChildIndicatorPolicy, "DontShowIndicatorWhenChildless", QTreeWidgetItem::ChildIndicatorPolicy::DontShowIndicatorWhenChildless);

    Data_Type<QTreeWidgetItem::ItemType> rb_cQTreeWidgetItemItemType =
        // RubyQt6::QtWidgets::QTreeWidgetItem::ItemType
        define_qenum_under<QTreeWidgetItem::ItemType>(rb_cQTreeWidgetItem, "ItemType");
        define_qenum_value_under(rb_cQTreeWidgetItemItemType, "Type", QTreeWidgetItem::ItemType::Type);
        define_qenum_value_under(rb_cQTreeWidgetItemItemType, "UserType", QTreeWidgetItem::ItemType::UserType);
}
