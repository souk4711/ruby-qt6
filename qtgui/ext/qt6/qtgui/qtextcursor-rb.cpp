#include "qtextcursor-rb.hpp"
#include <qtextcursor.h>

#include <QTextBlock>
#include <QTextDocument>
#include <QTextDocumentFragment>
#include <QTextFrame>
#include <QTextList>
#include <QTextTable>

using namespace Rice;

Rice::Class rb_cQTextCursor;

void Init_qtextcursor(Rice::Module rb_mQt6QtGui)
{
    rb_cQTextCursor =
        // RubyQt6::QtGui::QTextCursor
        define_class_under<QTextCursor>(rb_mQt6QtGui, "QTextCursor")
            // Constructor
            .define_constructor(Constructor<QTextCursor>())
            .define_constructor(Constructor<QTextCursor, QTextDocument *>(), Arg("document"))
            .define_constructor(Constructor<QTextCursor, QTextFrame *>(), Arg("frame"))
            .define_constructor(Constructor<QTextCursor, const QTextBlock &>(), Arg("block"))
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
            .define_method("insert_html", &QTextCursor::insertHtml, Arg("html"))
            .define_method<void (QTextCursor::*)(const QImage &, const QString &)>("insert_image", &QTextCursor::insertImage, Arg("image"), Arg("name") = static_cast<const QString &>(QString()))
            .define_method<void (QTextCursor::*)(const QString &)>("insert_image", &QTextCursor::insertImage, Arg("name"))
            .define_method<void (QTextCursor::*)(const QTextImageFormat &)>("insert_image", &QTextCursor::insertImage, Arg("format"))
            .define_method<void (QTextCursor::*)(const QTextImageFormat &, QTextFrameFormat::Position)>("insert_image", &QTextCursor::insertImage, Arg("format"), Arg("alignment"))
            .define_method<QTextList *(QTextCursor::*)(QTextListFormat::Style)>("insert_list", &QTextCursor::insertList, Arg("style"))
            .define_method<QTextList *(QTextCursor::*)(const QTextListFormat &)>("insert_list", &QTextCursor::insertList, Arg("format"))
            .define_method("insert_markdown", &QTextCursor::insertMarkdown, Arg("markdown"), Arg("features") = static_cast<QTextDocument::MarkdownFeatures>(QTextDocument::MarkdownDialectGitHub))
            .define_method<QTextTable *(QTextCursor::*)(int, int)>("insert_table", &QTextCursor::insertTable, Arg("rows"), Arg("cols"))
            .define_method<QTextTable *(QTextCursor::*)(int, int, const QTextTableFormat &)>("insert_table", &QTextCursor::insertTable, Arg("rows"), Arg("cols"), Arg("format"))
            .define_method<void (QTextCursor::*)(const QString &)>("insert_text", &QTextCursor::insertText, Arg("text"))
            .define_method<void (QTextCursor::*)(const QString &, const QTextCharFormat &)>("insert_text", &QTextCursor::insertText, Arg("text"), Arg("format"))
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
            .define_method("swap", &QTextCursor::swap, Arg("other"))
            .define_method("vertical_movement_x", &QTextCursor::verticalMovementX)
            .define_method("visual_navigation", &QTextCursor::visualNavigation);

    Enum<QTextCursor::MoveMode> rb_cQTextCursorMoveMode =
        // RubyQt6::QtGui::QTextCursor::MoveMode
        define_enum_under<QTextCursor::MoveMode>("MoveMode", rb_cQTextCursor)
            .define_value("MoveAnchor", QTextCursor::MoveMode::MoveAnchor)
            .define_value("KeepAnchor", QTextCursor::MoveMode::KeepAnchor);

    Enum<QTextCursor::MoveOperation> rb_cQTextCursorMoveOperation =
        // RubyQt6::QtGui::QTextCursor::MoveOperation
        define_enum_under<QTextCursor::MoveOperation>("MoveOperation", rb_cQTextCursor)
            .define_value("NoMove", QTextCursor::MoveOperation::NoMove)
            .define_value("Start", QTextCursor::MoveOperation::Start)
            .define_value("Up", QTextCursor::MoveOperation::Up)
            .define_value("StartOfLine", QTextCursor::MoveOperation::StartOfLine)
            .define_value("StartOfBlock", QTextCursor::MoveOperation::StartOfBlock)
            .define_value("StartOfWord", QTextCursor::MoveOperation::StartOfWord)
            .define_value("PreviousBlock", QTextCursor::MoveOperation::PreviousBlock)
            .define_value("PreviousCharacter", QTextCursor::MoveOperation::PreviousCharacter)
            .define_value("PreviousWord", QTextCursor::MoveOperation::PreviousWord)
            .define_value("Left", QTextCursor::MoveOperation::Left)
            .define_value("WordLeft", QTextCursor::MoveOperation::WordLeft)
            .define_value("End", QTextCursor::MoveOperation::End)
            .define_value("Down", QTextCursor::MoveOperation::Down)
            .define_value("EndOfLine", QTextCursor::MoveOperation::EndOfLine)
            .define_value("EndOfWord", QTextCursor::MoveOperation::EndOfWord)
            .define_value("EndOfBlock", QTextCursor::MoveOperation::EndOfBlock)
            .define_value("NextBlock", QTextCursor::MoveOperation::NextBlock)
            .define_value("NextCharacter", QTextCursor::MoveOperation::NextCharacter)
            .define_value("NextWord", QTextCursor::MoveOperation::NextWord)
            .define_value("Right", QTextCursor::MoveOperation::Right)
            .define_value("WordRight", QTextCursor::MoveOperation::WordRight)
            .define_value("NextCell", QTextCursor::MoveOperation::NextCell)
            .define_value("PreviousCell", QTextCursor::MoveOperation::PreviousCell)
            .define_value("NextRow", QTextCursor::MoveOperation::NextRow)
            .define_value("PreviousRow", QTextCursor::MoveOperation::PreviousRow);

    Enum<QTextCursor::SelectionType> rb_cQTextCursorSelectionType =
        // RubyQt6::QtGui::QTextCursor::SelectionType
        define_enum_under<QTextCursor::SelectionType>("SelectionType", rb_cQTextCursor)
            .define_value("WordUnderCursor", QTextCursor::SelectionType::WordUnderCursor)
            .define_value("LineUnderCursor", QTextCursor::SelectionType::LineUnderCursor)
            .define_value("BlockUnderCursor", QTextCursor::SelectionType::BlockUnderCursor)
            .define_value("Document", QTextCursor::SelectionType::Document);
}
