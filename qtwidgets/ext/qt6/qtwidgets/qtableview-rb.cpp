#include "qtableview-rb.hpp"
#include <qtableview.h>

#include <QHeaderView>

using namespace Rice;

Rice::Class rb_cQTableView;

void Init_qtableview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQTableView =
        // RubyQt6::QtWidgets::QTableView
        define_class_under<QTableView, QAbstractItemView>(rb_mQt6QtWidgets, "QTableView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTableView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTableView, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("clear_spans", &QTableView::clearSpans)
            .define_method("column_at", &QTableView::columnAt, Arg("x"))
            .define_method("column_span", &QTableView::columnSpan, Arg("row"), Arg("column"))
            .define_method("column_viewport_position", &QTableView::columnViewportPosition, Arg("column"))
            .define_method("column_width", &QTableView::columnWidth, Arg("column"))
            .define_method("do_items_layout", &QTableView::doItemsLayout)
            .define_method("grid_style", &QTableView::gridStyle)
            .define_method("horizontal_header", &QTableView::horizontalHeader)
            .define_method("index_at", &QTableView::indexAt, Arg("p"))
            .define_method("column_hidden?", &QTableView::isColumnHidden, Arg("column"))
            .define_method("corner_button_enabled?", &QTableView::isCornerButtonEnabled)
            .define_method("row_hidden?", &QTableView::isRowHidden, Arg("row"))
            .define_method("sorting_enabled?", &QTableView::isSortingEnabled)
            .define_method("row_at", &QTableView::rowAt, Arg("y"))
            .define_method("row_height", &QTableView::rowHeight, Arg("row"))
            .define_method("row_span", &QTableView::rowSpan, Arg("row"), Arg("column"))
            .define_method("row_viewport_position", &QTableView::rowViewportPosition, Arg("row"))
            .define_method("scroll_to", &QTableView::scrollTo, Arg("index"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            .define_method("set_column_hidden", &QTableView::setColumnHidden, Arg("column"), Arg("hide"))
            .define_method("set_column_width", &QTableView::setColumnWidth, Arg("column"), Arg("width"))
            .define_method("set_corner_button_enabled", &QTableView::setCornerButtonEnabled, Arg("enable"))
            .define_method("set_grid_style", &QTableView::setGridStyle, Arg("style"))
            .define_method("set_horizontal_header", &QTableView::setHorizontalHeader, Arg("header"))
            .define_method("set_model", &QTableView::setModel, Arg("model"))
            .define_method("set_root_index", &QTableView::setRootIndex, Arg("index"))
            .define_method("set_row_height", &QTableView::setRowHeight, Arg("row"), Arg("height"))
            .define_method("set_row_hidden", &QTableView::setRowHidden, Arg("row"), Arg("hide"))
            .define_method("set_selection_model", &QTableView::setSelectionModel, Arg("selection_model"))
            .define_method("set_sorting_enabled", &QTableView::setSortingEnabled, Arg("enable"))
            .define_method("set_span", &QTableView::setSpan, Arg("row"), Arg("column"), Arg("row_span"), Arg("column_span"))
            .define_method("set_vertical_header", &QTableView::setVerticalHeader, Arg("header"))
            .define_method("set_word_wrap", &QTableView::setWordWrap, Arg("on"))
            .define_method("show_grid", &QTableView::showGrid)
            .define_method("vertical_header", &QTableView::verticalHeader)
            .define_method("visual_rect", &QTableView::visualRect, Arg("index"))
            .define_method("word_wrap", &QTableView::wordWrap)
            // Public Slots
            .define_method("hide_column", &QTableView::hideColumn, Arg("column"))
            .define_method("hide_row", &QTableView::hideRow, Arg("row"))
            .define_method("resize_column_to_contents", &QTableView::resizeColumnToContents, Arg("column"))
            .define_method("resize_columns_to_contents", &QTableView::resizeColumnsToContents)
            .define_method("resize_row_to_contents", &QTableView::resizeRowToContents, Arg("row"))
            .define_method("resize_rows_to_contents", &QTableView::resizeRowsToContents)
            .define_method("select_column", &QTableView::selectColumn, Arg("column"))
            .define_method("select_row", &QTableView::selectRow, Arg("row"))
            .define_method("set_show_grid", &QTableView::setShowGrid, Arg("show"))
            .define_method("show_column", &QTableView::showColumn, Arg("column"))
            .define_method("show_row", &QTableView::showRow, Arg("row"))
            .define_method("sort_by_column", &QTableView::sortByColumn, Arg("column"), Arg("order"));
}
