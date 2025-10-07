#include "qabstractitemview-rb.hpp"
#include <qabstractitemview.h>

using namespace Rice;

Rice::Class rb_cQAbstractItemView;

void Init_qabstractitemview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractItemView =
        // RubyQt6::QtWidgets::QAbstractItemView
        define_class_under<QAbstractItemView, QAbstractScrollArea>(rb_mQt6QtWidgets, "QAbstractItemView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractItemView::staticMetaObject; })
            // Public Functions
            .define_method("alternating_row_colors", &QAbstractItemView::alternatingRowColors)
            .define_method("auto_scroll_margin", &QAbstractItemView::autoScrollMargin)
            .define_method("close_persistent_editor", &QAbstractItemView::closePersistentEditor, Arg("index"))
            .define_method("current_index", &QAbstractItemView::currentIndex)
            .define_method("default_drop_action", &QAbstractItemView::defaultDropAction)
            .define_method("do_items_layout", &QAbstractItemView::doItemsLayout)
            .define_method("drag_drop_mode", &QAbstractItemView::dragDropMode)
            .define_method("drag_drop_overwrite_mode", &QAbstractItemView::dragDropOverwriteMode)
            .define_method("drag_enabled", &QAbstractItemView::dragEnabled)
            .define_method("edit_triggers", &QAbstractItemView::editTriggers)
            .define_method("has_auto_scroll", &QAbstractItemView::hasAutoScroll)
            .define_method("horizontal_scroll_mode", &QAbstractItemView::horizontalScrollMode)
            .define_method("icon_size", &QAbstractItemView::iconSize)
            .define_method("index_at", &QAbstractItemView::indexAt, Arg("point"))
            .define_method("index_widget", &QAbstractItemView::indexWidget, Arg("index"))
            .define_method("persistent_editor_open?", &QAbstractItemView::isPersistentEditorOpen, Arg("index"))
            .define_method<QAbstractItemDelegate *(QAbstractItemView::*)() const>("item_delegate", &QAbstractItemView::itemDelegate)
            .define_method("item_delegate_for_column", &QAbstractItemView::itemDelegateForColumn, Arg("column"))
            .define_method("item_delegate_for_index", &QAbstractItemView::itemDelegateForIndex, Arg("index"))
            .define_method("item_delegate_for_row", &QAbstractItemView::itemDelegateForRow, Arg("row"))
            .define_method("keyboard_search", &QAbstractItemView::keyboardSearch, Arg("search"))
            .define_method("model", &QAbstractItemView::model)
            .define_method("open_persistent_editor", &QAbstractItemView::openPersistentEditor, Arg("index"))
            .define_method("reset_horizontal_scroll_mode", &QAbstractItemView::resetHorizontalScrollMode)
            .define_method("reset_vertical_scroll_mode", &QAbstractItemView::resetVerticalScrollMode)
            .define_method("root_index", &QAbstractItemView::rootIndex)
            .define_method("scroll_to", &QAbstractItemView::scrollTo, Arg("index"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            .define_method("selection_behavior", &QAbstractItemView::selectionBehavior)
            .define_method("selection_mode", &QAbstractItemView::selectionMode)
            .define_method("selection_model", &QAbstractItemView::selectionModel)
            .define_method("set_alternating_row_colors", &QAbstractItemView::setAlternatingRowColors, Arg("enable"))
            .define_method("set_auto_scroll", &QAbstractItemView::setAutoScroll, Arg("enable"))
            .define_method("set_auto_scroll_margin", &QAbstractItemView::setAutoScrollMargin, Arg("margin"))
            .define_method("set_default_drop_action", &QAbstractItemView::setDefaultDropAction, Arg("drop_action"))
            .define_method("set_drag_drop_mode", &QAbstractItemView::setDragDropMode, Arg("behavior"))
            .define_method("set_drag_drop_overwrite_mode", &QAbstractItemView::setDragDropOverwriteMode, Arg("overwrite"))
            .define_method("set_drag_enabled", &QAbstractItemView::setDragEnabled, Arg("enable"))
            .define_method("set_drop_indicator_shown", &QAbstractItemView::setDropIndicatorShown, Arg("enable"))
            .define_method("set_edit_triggers", &QAbstractItemView::setEditTriggers, Arg("triggers"))
            .define_method("set_horizontal_scroll_mode", &QAbstractItemView::setHorizontalScrollMode, Arg("mode"))
            .define_method("set_icon_size", &QAbstractItemView::setIconSize, Arg("size"))
            .define_method("set_index_widget", &QAbstractItemView::setIndexWidget, Arg("index"), Arg("widget"))
            .define_method("set_item_delegate", &QAbstractItemView::setItemDelegate, Arg("delegate"))
            .define_method("set_item_delegate_for_column", &QAbstractItemView::setItemDelegateForColumn, Arg("column"), Arg("delegate"))
            .define_method("set_item_delegate_for_row", &QAbstractItemView::setItemDelegateForRow, Arg("row"), Arg("delegate"))
            .define_method("set_model", &QAbstractItemView::setModel, Arg("model"))
            .define_method("set_selection_behavior", &QAbstractItemView::setSelectionBehavior, Arg("behavior"))
            .define_method("set_selection_mode", &QAbstractItemView::setSelectionMode, Arg("mode"))
            .define_method("set_selection_model", &QAbstractItemView::setSelectionModel, Arg("selection_model"))
            .define_method("set_tab_key_navigation", &QAbstractItemView::setTabKeyNavigation, Arg("enable"))
            .define_method("set_text_elide_mode", &QAbstractItemView::setTextElideMode, Arg("mode"))
            .define_method("set_update_threshold", &QAbstractItemView::setUpdateThreshold, Arg("threshold"))
            .define_method("set_vertical_scroll_mode", &QAbstractItemView::setVerticalScrollMode, Arg("mode"))
            .define_method("show_drop_indicator", &QAbstractItemView::showDropIndicator)
            .define_method("size_hint_for_column", &QAbstractItemView::sizeHintForColumn, Arg("column"))
            .define_method("size_hint_for_index", &QAbstractItemView::sizeHintForIndex, Arg("index"))
            .define_method("size_hint_for_row", &QAbstractItemView::sizeHintForRow, Arg("row"))
            .define_method("tab_key_navigation", &QAbstractItemView::tabKeyNavigation)
            .define_method("text_elide_mode", &QAbstractItemView::textElideMode)
            .define_method("update_threshold", &QAbstractItemView::updateThreshold)
            .define_method("vertical_scroll_mode", &QAbstractItemView::verticalScrollMode)
            .define_method("visual_rect", &QAbstractItemView::visualRect, Arg("index"))
            // Public Slots
            .define_method("clear_selection", &QAbstractItemView::clearSelection)
            .define_method<void (QAbstractItemView::*)(const QModelIndex &)>("edit", &QAbstractItemView::edit, Arg("index"))
            .define_method("reset", &QAbstractItemView::reset)
            .define_method("scroll_to_bottom", &QAbstractItemView::scrollToBottom)
            .define_method("scroll_to_top", &QAbstractItemView::scrollToTop)
            .define_method("select_all", &QAbstractItemView::selectAll)
            .define_method("set_current_index", &QAbstractItemView::setCurrentIndex, Arg("index"))
            .define_method("set_root_index", &QAbstractItemView::setRootIndex, Arg("index"))
            .define_method<void (QAbstractItemView::*)(const QModelIndex &)>("update", &QAbstractItemView::update, Arg("index"))
            // Signals
            .define_method("activated", &QAbstractItemView::activated, Arg("index"))
            .define_method("clicked", &QAbstractItemView::clicked, Arg("index"))
            .define_method("double_clicked", &QAbstractItemView::doubleClicked, Arg("index"))
            .define_method("entered", &QAbstractItemView::entered, Arg("index"))
            .define_method("icon_size_changed", &QAbstractItemView::iconSizeChanged, Arg("size"))
            .define_method("pressed", &QAbstractItemView::pressed, Arg("index"))
            .define_method("viewport_entered", &QAbstractItemView::viewportEntered);

    Enum<QAbstractItemView::DragDropMode> rb_cQAbstractItemViewDragDropMode =
        // RubyQt6::QtWidgets::QAbstractItemView::DragDropMode
        define_enum_under<QAbstractItemView::DragDropMode>("DragDropMode", rb_cQAbstractItemView)
            .define_value("NoDragDrop", QAbstractItemView::DragDropMode::NoDragDrop)
            .define_value("DragOnly", QAbstractItemView::DragDropMode::DragOnly)
            .define_value("DropOnly", QAbstractItemView::DragDropMode::DropOnly)
            .define_value("DragDrop", QAbstractItemView::DragDropMode::DragDrop)
            .define_value("InternalMove", QAbstractItemView::DragDropMode::InternalMove);

    Enum<QAbstractItemView::EditTrigger> rb_cQAbstractItemViewEditTrigger =
        // RubyQt6::QtWidgets::QAbstractItemView::EditTrigger
        define_enum_under<QAbstractItemView::EditTrigger>("EditTrigger", rb_cQAbstractItemView)
            .define_value("NoEditTriggers", QAbstractItemView::EditTrigger::NoEditTriggers)
            .define_value("CurrentChanged", QAbstractItemView::EditTrigger::CurrentChanged)
            .define_value("DoubleClicked", QAbstractItemView::EditTrigger::DoubleClicked)
            .define_value("SelectedClicked", QAbstractItemView::EditTrigger::SelectedClicked)
            .define_value("EditKeyPressed", QAbstractItemView::EditTrigger::EditKeyPressed)
            .define_value("AnyKeyPressed", QAbstractItemView::EditTrigger::AnyKeyPressed)
            .define_value("AllEditTriggers", QAbstractItemView::EditTrigger::AllEditTriggers);

    Enum<QAbstractItemView::ScrollHint> rb_cQAbstractItemViewScrollHint =
        // RubyQt6::QtWidgets::QAbstractItemView::ScrollHint
        define_enum_under<QAbstractItemView::ScrollHint>("ScrollHint", rb_cQAbstractItemView)
            .define_value("EnsureVisible", QAbstractItemView::ScrollHint::EnsureVisible)
            .define_value("PositionAtTop", QAbstractItemView::ScrollHint::PositionAtTop)
            .define_value("PositionAtBottom", QAbstractItemView::ScrollHint::PositionAtBottom)
            .define_value("PositionAtCenter", QAbstractItemView::ScrollHint::PositionAtCenter);

    Enum<QAbstractItemView::ScrollMode> rb_cQAbstractItemViewScrollMode =
        // RubyQt6::QtWidgets::QAbstractItemView::ScrollMode
        define_enum_under<QAbstractItemView::ScrollMode>("ScrollMode", rb_cQAbstractItemView)
            .define_value("ScrollPerItem", QAbstractItemView::ScrollMode::ScrollPerItem)
            .define_value("ScrollPerPixel", QAbstractItemView::ScrollMode::ScrollPerPixel);

    Enum<QAbstractItemView::SelectionBehavior> rb_cQAbstractItemViewSelectionBehavior =
        // RubyQt6::QtWidgets::QAbstractItemView::SelectionBehavior
        define_enum_under<QAbstractItemView::SelectionBehavior>("SelectionBehavior", rb_cQAbstractItemView)
            .define_value("SelectItems", QAbstractItemView::SelectionBehavior::SelectItems)
            .define_value("SelectRows", QAbstractItemView::SelectionBehavior::SelectRows)
            .define_value("SelectColumns", QAbstractItemView::SelectionBehavior::SelectColumns);

    Enum<QAbstractItemView::SelectionMode> rb_cQAbstractItemViewSelectionMode =
        // RubyQt6::QtWidgets::QAbstractItemView::SelectionMode
        define_enum_under<QAbstractItemView::SelectionMode>("SelectionMode", rb_cQAbstractItemView)
            .define_value("NoSelection", QAbstractItemView::SelectionMode::NoSelection)
            .define_value("SingleSelection", QAbstractItemView::SelectionMode::SingleSelection)
            .define_value("MultiSelection", QAbstractItemView::SelectionMode::MultiSelection)
            .define_value("ExtendedSelection", QAbstractItemView::SelectionMode::ExtendedSelection)
            .define_value("ContiguousSelection", QAbstractItemView::SelectionMode::ContiguousSelection);
}
