#include "qtexttable-rb.hpp"
#include <qtexttable.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextTable;
Class rb_cQTextTableCell;

void Init_qtexttable(Module rb_mQt6QtGui)
{
    rb_cQTextTable =
        // RubyQt6::QtGui::QTextTable
        define_class_under<QTextTable, QTextFrame>(rb_mQt6QtGui, "QTextTable")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextTable::staticMetaObject; })
            // Public Functions
            .define_method("resize", &QTextTable::resize, Arg("rows"), Arg("cols"))
            .define_method("insert_rows", &QTextTable::insertRows, Arg("pos"), Arg("num"))
            .define_method("insert_columns", &QTextTable::insertColumns, Arg("pos"), Arg("num"))
            .define_method("append_rows", &QTextTable::appendRows, Arg("count"))
            .define_method("append_columns", &QTextTable::appendColumns, Arg("count"))
            .define_method("remove_rows", &QTextTable::removeRows, Arg("pos"), Arg("num"))
            .define_method("remove_columns", &QTextTable::removeColumns, Arg("pos"), Arg("num"))
            .define_method<void (QTextTable::*)(int, int, int, int)>("merge_cells", &QTextTable::mergeCells, Arg("row"), Arg("col"), Arg("num_rows"), Arg("num_cols"))
            .define_method<void (QTextTable::*)(const QTextCursor &)>("merge_cells", &QTextTable::mergeCells, Arg("cursor"))
            .define_method("split_cell", &QTextTable::splitCell, Arg("row"), Arg("col"), Arg("num_rows"), Arg("num_cols"))
            .define_method("rows", &QTextTable::rows)
            .define_method("columns", &QTextTable::columns)
            .define_method<QTextTableCell (QTextTable::*)(int, int) const>("cell_at", &QTextTable::cellAt, Arg("row"), Arg("col"))
            .define_method<QTextTableCell (QTextTable::*)(int) const>("cell_at", &QTextTable::cellAt, Arg("position"))
            .define_method<QTextTableCell (QTextTable::*)(const QTextCursor &) const>("cell_at", &QTextTable::cellAt, Arg("c"))
            .define_method("row_start", &QTextTable::rowStart, Arg("c"))
            .define_method("row_end", &QTextTable::rowEnd, Arg("c"))
            .define_method("set_format", &QTextTable::setFormat, Arg("format"))
            .define_method("format", &QTextTable::format);

    rb_cQTextTableCell =
        // RubyQt6::QtGui::QTextTableCell
        define_class_under<QTextTableCell>(rb_mQt6QtGui, "QTextTableCell")
            // Public Functions
            .define_method("column", &QTextTableCell::column)
            .define_method("column_span", &QTextTableCell::columnSpan)
            .define_method("first_cursor_position", &QTextTableCell::firstCursorPosition)
            .define_method("first_position", &QTextTableCell::firstPosition)
            .define_method("format", &QTextTableCell::format)
            .define_method("valid?", &QTextTableCell::isValid)
            .define_method("last_cursor_position", &QTextTableCell::lastCursorPosition)
            .define_method("last_position", &QTextTableCell::lastPosition)
            .define_method("row", &QTextTableCell::row)
            .define_method("row_span", &QTextTableCell::rowSpan)
            .define_method("set_format", &QTextTableCell::setFormat, Arg("format"))
            .define_method("table_cell_format_index", &QTextTableCell::tableCellFormatIndex);
}
