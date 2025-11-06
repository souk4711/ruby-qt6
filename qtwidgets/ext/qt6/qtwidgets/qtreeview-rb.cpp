#include "qtreeview-rb.hpp"
#include <qtreeview.h>

#include <QHeaderView>

using namespace Rice;

Rice::Class rb_cQTreeView;

void Init_qtreeview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQTreeView =
        // RubyQt6::QtWidgets::QTreeView
        define_class_under<QTreeView, QAbstractItemView>(rb_mQt6QtWidgets, "QTreeView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTreeView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTreeView, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("all_columns_show_focus", &QTreeView::allColumnsShowFocus)
            .define_method("auto_expand_delay", &QTreeView::autoExpandDelay)
            .define_method("column_at", &QTreeView::columnAt, Arg("x"))
            .define_method("column_viewport_position", &QTreeView::columnViewportPosition, Arg("column"))
            .define_method("column_width", &QTreeView::columnWidth, Arg("column"))
            .define_method("data_changed", &QTreeView::dataChanged, Arg("top_left"), Arg("bottom_right"), Arg("roles") = static_cast<const QList<int> &>(QList<int>()))
            .define_method("do_items_layout", &QTreeView::doItemsLayout)
            .define_method("expands_on_double_click", &QTreeView::expandsOnDoubleClick)
            .define_method("header", &QTreeView::header)
            .define_method("indentation", &QTreeView::indentation)
            .define_method("index_above", &QTreeView::indexAbove, Arg("index"))
            .define_method("index_at", &QTreeView::indexAt, Arg("p"))
            .define_method("index_below", &QTreeView::indexBelow, Arg("index"))
            .define_method("animated?", &QTreeView::isAnimated)
            .define_method("column_hidden?", &QTreeView::isColumnHidden, Arg("column"))
            .define_method("expanded?", &QTreeView::isExpanded, Arg("index"))
            .define_method("first_column_spanned?", &QTreeView::isFirstColumnSpanned, Arg("row"), Arg("parent"))
            .define_method("header_hidden?", &QTreeView::isHeaderHidden)
            .define_method("row_hidden?", &QTreeView::isRowHidden, Arg("row"), Arg("parent"))
            .define_method("sorting_enabled?", &QTreeView::isSortingEnabled)
            .define_method("items_expandable", &QTreeView::itemsExpandable)
            .define_method("keyboard_search", &QTreeView::keyboardSearch, Arg("search"))
            .define_method("reset", &QTreeView::reset)
            .define_method("reset_indentation", &QTreeView::resetIndentation)
            .define_method("root_is_decorated", &QTreeView::rootIsDecorated)
            .define_method("scroll_to", &QTreeView::scrollTo, Arg("index"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            .define_method("select_all", &QTreeView::selectAll)
            .define_method("set_all_columns_show_focus", &QTreeView::setAllColumnsShowFocus, Arg("enable"))
            .define_method("set_animated", &QTreeView::setAnimated, Arg("enable"))
            .define_method("set_auto_expand_delay", &QTreeView::setAutoExpandDelay, Arg("delay"))
            .define_method("set_column_hidden", &QTreeView::setColumnHidden, Arg("column"), Arg("hide"))
            .define_method("set_column_width", &QTreeView::setColumnWidth, Arg("column"), Arg("width"))
            .define_method("set_expanded", &QTreeView::setExpanded, Arg("index"), Arg("expand"))
            .define_method("set_expands_on_double_click", &QTreeView::setExpandsOnDoubleClick, Arg("enable"))
            .define_method("set_first_column_spanned", &QTreeView::setFirstColumnSpanned, Arg("row"), Arg("parent"), Arg("span"))
            .define_method("set_header", &QTreeView::setHeader, Arg("header"))
            .define_method("set_header_hidden", &QTreeView::setHeaderHidden, Arg("hide"))
            .define_method("set_indentation", &QTreeView::setIndentation, Arg("i"))
            .define_method("set_items_expandable", &QTreeView::setItemsExpandable, Arg("enable"))
            .define_method("set_model", &QTreeView::setModel, Arg("model"))
            .define_method("set_root_index", &QTreeView::setRootIndex, Arg("index"))
            .define_method("set_root_is_decorated", &QTreeView::setRootIsDecorated, Arg("show"))
            .define_method("set_row_hidden", &QTreeView::setRowHidden, Arg("row"), Arg("parent"), Arg("hide"))
            .define_method("set_selection_model", &QTreeView::setSelectionModel, Arg("selection_model"))
            .define_method("set_sorting_enabled", &QTreeView::setSortingEnabled, Arg("enable"))
            .define_method("set_tree_position", &QTreeView::setTreePosition, Arg("logical_index"))
            .define_method("set_uniform_row_heights", &QTreeView::setUniformRowHeights, Arg("uniform"))
            .define_method("set_word_wrap", &QTreeView::setWordWrap, Arg("on"))
            .define_method("tree_position", &QTreeView::treePosition)
            .define_method("uniform_row_heights", &QTreeView::uniformRowHeights)
            .define_method("visual_rect", &QTreeView::visualRect, Arg("index"))
            .define_method("word_wrap", &QTreeView::wordWrap)
            // Public Slots
            .define_method("collapse", &QTreeView::collapse, Arg("index"))
            .define_method("collapse_all", &QTreeView::collapseAll)
            .define_method("expand", &QTreeView::expand, Arg("index"))
            .define_method("expand_all", &QTreeView::expandAll)
            .define_method("expand_recursively", &QTreeView::expandRecursively, Arg("index"), Arg("depth") = static_cast<int>(-1))
            .define_method("expand_to_depth", &QTreeView::expandToDepth, Arg("depth"))
            .define_method("hide_column", &QTreeView::hideColumn, Arg("column"))
            .define_method("resize_column_to_contents", &QTreeView::resizeColumnToContents, Arg("column"))
            .define_method("show_column", &QTreeView::showColumn, Arg("column"))
            .define_method("sort_by_column", &QTreeView::sortByColumn, Arg("column"), Arg("order"))
            // Signals
            .define_method("collapsed", &QTreeView::collapsed, Arg("index"))
            .define_method("expanded", &QTreeView::expanded, Arg("index"));
}
