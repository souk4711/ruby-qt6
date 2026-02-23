#include "qtextcursor-rb.hpp"
#include <qtextcursor.h>
#include <rice/qt6/qenum.hpp>

#include <QTextBlock>
#include <QTextDocument>
#include <QTextDocumentFragment>
#include <QTextFrame>
#include <QTextList>
#include <QTextTable>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextCursor;

void Init_qtextcursor(Module rb_mQt6QtGui)
{
    rb_cQTextCursor =
        // RubyQt6::QtGui::QTextCursor
        define_qlass_under<QTextCursor>(rb_mQt6QtGui, "QTextCursor")
            // Constructor
            .define_constructor(Constructor<QTextCursor>())
            .define_constructor(Constructor<QTextCursor, QTextDocument *>(), Arg("document"))
            .define_constructor(Constructor<QTextCursor, QTextFrame *>(), Arg("frame"))
            .define_constructor(Constructor<QTextCursor, const QTextBlock &>(), Arg("block"))
            .define_constructor(Constructor<QTextCursor, const QTextCursor &>(), Arg("other"))
            // Public Functions
            .define_method("anchor", &QTextCursor::anchor)
            .define_method("at_block_end", &QTextCursor::atBlockEnd)
            .define_method("at_block_start", &QTextCursor::atBlockStart)
            .define_method("at_end", &QTextCursor::atEnd)
            .define_method("at_start", &QTextCursor::atStart)
            .define_method("begin_edit_block", &QTextCursor::beginEditBlock)
            .define_method("block", &QTextCursor::block)
            .define_method("block_char_format", &QTextCursor::blockCharFormat)
            .define_method("block_format", &QTextCursor::blockFormat)
            .define_method("block_number", &QTextCursor::blockNumber)
            .define_method("char_format", &QTextCursor::charFormat)
            .define_method("clear_selection", &QTextCursor::clearSelection)
            .define_method("column_number", &QTextCursor::columnNumber)
            .define_method<QTextList *(QTextCursor::*)(QTextListFormat::Style)>("create_list", &QTextCursor::createList, Arg("style"))
            .define_method<QTextList *(QTextCursor::*)(const QTextListFormat &)>("create_list", &QTextCursor::createList, Arg("format"))
            .define_method("current_frame", &QTextCursor::currentFrame)
            .define_method("current_list", &QTextCursor::currentList)
            .define_method("current_table", &QTextCursor::currentTable)
            .define_method("delete_char", &QTextCursor::deleteChar)
            .define_method("delete_previous_char", &QTextCursor::deletePreviousChar)
            .define_method("document", &QTextCursor::document)
            .define_method("end_edit_block", &QTextCursor::endEditBlock)
            .define_method("has_complex_selection", &QTextCursor::hasComplexSelection)
            .define_method("has_selection", &QTextCursor::hasSelection)
            .define_method<void (QTextCursor::*)()>("insert_block", &QTextCursor::insertBlock)
            .define_method<void (QTextCursor::*)(const QTextBlockFormat &)>("insert_block", &QTextCursor::insertBlock, Arg("format"))
            .define_method<void (QTextCursor::*)(const QTextBlockFormat &, const QTextCharFormat &)>("insert_block", &QTextCursor::insertBlock, Arg("format"), Arg("char_format"))
            .define_method("insert_fragment", &QTextCursor::insertFragment, Arg("fragment"))
            .define_method("insert_frame", &QTextCursor::insertFrame, Arg("format"))
            .define_method("_insert_html", &QTextCursor::insertHtml, Arg("html"))
            .define_method<void (QTextCursor::*)(const QImage &, const QString &)>("_insert_image", &QTextCursor::insertImage, Arg("image"), Arg("name") = static_cast<const QString &>(QString()))
            .define_method<void (QTextCursor::*)(const QString &)>("_insert_image", &QTextCursor::insertImage, Arg("name"))
            .define_method<void (QTextCursor::*)(const QTextImageFormat &)>("_insert_image", &QTextCursor::insertImage, Arg("format"))
            .define_method<void (QTextCursor::*)(const QTextImageFormat &, QTextFrameFormat::Position)>("_insert_image", &QTextCursor::insertImage, Arg("format"), Arg("alignment"))
            .define_method<QTextList *(QTextCursor::*)(QTextListFormat::Style)>("insert_list", &QTextCursor::insertList, Arg("style"))
            .define_method<QTextList *(QTextCursor::*)(const QTextListFormat &)>("insert_list", &QTextCursor::insertList, Arg("format"))
            .define_method("_insert_markdown", &QTextCursor::insertMarkdown, Arg("markdown"), Arg("features") = static_cast<QTextDocument::MarkdownFeatures>(QTextDocument::MarkdownDialectGitHub))
            .define_method<QTextTable *(QTextCursor::*)(int, int)>("insert_table", &QTextCursor::insertTable, Arg("rows"), Arg("cols"))
            .define_method<QTextTable *(QTextCursor::*)(int, int, const QTextTableFormat &)>("insert_table", &QTextCursor::insertTable, Arg("rows"), Arg("cols"), Arg("format"))
            .define_method<void (QTextCursor::*)(const QString &)>("_insert_text", &QTextCursor::insertText, Arg("text"))
            .define_method<void (QTextCursor::*)(const QString &, const QTextCharFormat &)>("_insert_text", &QTextCursor::insertText, Arg("text"), Arg("format"))
            .define_method("copy_of?", &QTextCursor::isCopyOf, Arg("other"))
            .define_method("null?", &QTextCursor::isNull)
            .define_method("join_previous_edit_block", &QTextCursor::joinPreviousEditBlock)
            .define_method("keep_position_on_insert", &QTextCursor::keepPositionOnInsert)
            .define_method("merge_block_char_format", &QTextCursor::mergeBlockCharFormat, Arg("modifier"))
            .define_method("merge_block_format", &QTextCursor::mergeBlockFormat, Arg("modifier"))
            .define_method("merge_char_format", &QTextCursor::mergeCharFormat, Arg("modifier"))
            .define_method("move_position", &QTextCursor::movePosition, Arg("op"), Arg("mode") = static_cast<QTextCursor::MoveMode>(QTextCursor::MoveMode::MoveAnchor), Arg("n") = static_cast<int>(1))
            .define_method("position", &QTextCursor::position)
            .define_method("position_in_block", &QTextCursor::positionInBlock)
            .define_method("remove_selected_text", &QTextCursor::removeSelectedText)
            .define_method("select", &QTextCursor::select, Arg("selection"))
            .define_method("selected_table_cells", &QTextCursor::selectedTableCells, Arg("first_row"), Arg("num_rows"), Arg("first_column"), Arg("num_columns"))
            .define_method("selected_text", &QTextCursor::selectedText)
            .define_method("selection", &QTextCursor::selection)
            .define_method("selection_end", &QTextCursor::selectionEnd)
            .define_method("selection_start", &QTextCursor::selectionStart)
            .define_method("set_block_char_format", &QTextCursor::setBlockCharFormat, Arg("format"))
            .define_method("set_block_format", &QTextCursor::setBlockFormat, Arg("format"))
            .define_method("set_char_format", &QTextCursor::setCharFormat, Arg("format"))
            .define_method("set_keep_position_on_insert", &QTextCursor::setKeepPositionOnInsert, Arg("b"))
            .define_method("set_position", &QTextCursor::setPosition, Arg("pos"), Arg("mode") = static_cast<QTextCursor::MoveMode>(QTextCursor::MoveMode::MoveAnchor))
            .define_method("set_vertical_movement_x", &QTextCursor::setVerticalMovementX, Arg("x"))
            .define_method("set_visual_navigation", &QTextCursor::setVisualNavigation, Arg("b"))
            .define_method("vertical_movement_x", &QTextCursor::verticalMovementX)
            .define_method("visual_navigation", &QTextCursor::visualNavigation);

    Data_Type<QTextCursor::MoveMode> rb_cQTextCursorMoveMode =
        // RubyQt6::QtGui::QTextCursor::MoveMode
        define_qenum_under<QTextCursor::MoveMode>(rb_cQTextCursor, "MoveMode");
        define_qenum_value_under(rb_cQTextCursorMoveMode, "MoveAnchor", QTextCursor::MoveMode::MoveAnchor);
        define_qenum_value_under(rb_cQTextCursorMoveMode, "KeepAnchor", QTextCursor::MoveMode::KeepAnchor);

    Data_Type<QTextCursor::MoveOperation> rb_cQTextCursorMoveOperation =
        // RubyQt6::QtGui::QTextCursor::MoveOperation
        define_qenum_under<QTextCursor::MoveOperation>(rb_cQTextCursor, "MoveOperation");
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "NoMove", QTextCursor::MoveOperation::NoMove);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "Start", QTextCursor::MoveOperation::Start);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "Up", QTextCursor::MoveOperation::Up);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "StartOfLine", QTextCursor::MoveOperation::StartOfLine);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "StartOfBlock", QTextCursor::MoveOperation::StartOfBlock);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "StartOfWord", QTextCursor::MoveOperation::StartOfWord);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "PreviousBlock", QTextCursor::MoveOperation::PreviousBlock);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "PreviousCharacter", QTextCursor::MoveOperation::PreviousCharacter);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "PreviousWord", QTextCursor::MoveOperation::PreviousWord);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "Left", QTextCursor::MoveOperation::Left);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "WordLeft", QTextCursor::MoveOperation::WordLeft);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "End", QTextCursor::MoveOperation::End);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "Down", QTextCursor::MoveOperation::Down);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "EndOfLine", QTextCursor::MoveOperation::EndOfLine);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "EndOfWord", QTextCursor::MoveOperation::EndOfWord);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "EndOfBlock", QTextCursor::MoveOperation::EndOfBlock);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "NextBlock", QTextCursor::MoveOperation::NextBlock);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "NextCharacter", QTextCursor::MoveOperation::NextCharacter);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "NextWord", QTextCursor::MoveOperation::NextWord);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "Right", QTextCursor::MoveOperation::Right);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "WordRight", QTextCursor::MoveOperation::WordRight);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "NextCell", QTextCursor::MoveOperation::NextCell);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "PreviousCell", QTextCursor::MoveOperation::PreviousCell);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "NextRow", QTextCursor::MoveOperation::NextRow);
        define_qenum_value_under(rb_cQTextCursorMoveOperation, "PreviousRow", QTextCursor::MoveOperation::PreviousRow);

    Data_Type<QTextCursor::SelectionType> rb_cQTextCursorSelectionType =
        // RubyQt6::QtGui::QTextCursor::SelectionType
        define_qenum_under<QTextCursor::SelectionType>(rb_cQTextCursor, "SelectionType");
        define_qenum_value_under(rb_cQTextCursorSelectionType, "WordUnderCursor", QTextCursor::SelectionType::WordUnderCursor);
        define_qenum_value_under(rb_cQTextCursorSelectionType, "LineUnderCursor", QTextCursor::SelectionType::LineUnderCursor);
        define_qenum_value_under(rb_cQTextCursorSelectionType, "BlockUnderCursor", QTextCursor::SelectionType::BlockUnderCursor);
        define_qenum_value_under(rb_cQTextCursorSelectionType, "Document", QTextCursor::SelectionType::Document);
}
