#include "qplaintextedit-rb.hpp"
#include <qplaintextedit.h>

#include <QMenu>
#include <QPagedPaintDevice>
#include <QPainter>
#include <QRegularExpression>
#include <QTextBlock>
#include <QTextFrame>

using namespace Rice;

Rice::Class rb_cQPlainTextEdit;

void Init_qplaintextedit(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQPlainTextEdit =
        // RubyQt6::QtWidgets::QPlainTextEdit
        define_class_under<QPlainTextEdit, QAbstractScrollArea>(rb_mQt6QtWidgets, "QPlainTextEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QPlainTextEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QPlainTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("anchor_at", &QPlainTextEdit::anchorAt, Arg("pos"))
            .define_method("background_visible", &QPlainTextEdit::backgroundVisible)
            .define_method("block_count", &QPlainTextEdit::blockCount)
            .define_method("can_paste", &QPlainTextEdit::canPaste)
            .define_method("center_on_scroll", &QPlainTextEdit::centerOnScroll)
            .define_method<QMenu *(QPlainTextEdit::*)()>("create_standard_context_menu", &QPlainTextEdit::createStandardContextMenu)
            .define_method<QMenu *(QPlainTextEdit::*)(const QPoint &)>("create_standard_context_menu", &QPlainTextEdit::createStandardContextMenu, Arg("position"))
            .define_method("current_char_format", &QPlainTextEdit::currentCharFormat)
            .define_method("cursor_for_position", &QPlainTextEdit::cursorForPosition, Arg("pos"))
            .define_method<QRect (QPlainTextEdit::*)() const>("cursor_rect", &QPlainTextEdit::cursorRect)
            .define_method<QRect (QPlainTextEdit::*)(const QTextCursor &) const>("cursor_rect", &QPlainTextEdit::cursorRect, Arg("cursor"))
            .define_method("cursor_width", &QPlainTextEdit::cursorWidth)
            .define_method("document", &QPlainTextEdit::document)
            .define_method("document_title", &QPlainTextEdit::documentTitle)
            .define_method("ensure_cursor_visible", &QPlainTextEdit::ensureCursorVisible)
            .define_method("extra_selections", &QPlainTextEdit::extraSelections)
            .define_method<bool (QPlainTextEdit::*)(const QRegularExpression &, QTextDocument::FindFlags)>("find", &QPlainTextEdit::find, Arg("exp"), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method<bool (QPlainTextEdit::*)(const QString &, QTextDocument::FindFlags)>("find", &QPlainTextEdit::find, Arg("exp"), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method<QVariant (QPlainTextEdit::*)(Qt::InputMethodQuery) const>("input_method_query", &QPlainTextEdit::inputMethodQuery, Arg("property"))
            .define_method<QVariant (QPlainTextEdit::*)(Qt::InputMethodQuery, QVariant) const>("input_method_query", &QPlainTextEdit::inputMethodQuery, Arg("query"), Arg("argument"))
            .define_method("read_only?", &QPlainTextEdit::isReadOnly)
            .define_method("undo_redo_enabled?", &QPlainTextEdit::isUndoRedoEnabled)
            .define_method("line_wrap_mode", &QPlainTextEdit::lineWrapMode)
            .define_method("load_resource", &QPlainTextEdit::loadResource, Arg("type"), Arg("name"))
            .define_method("maximum_block_count", &QPlainTextEdit::maximumBlockCount)
            .define_method("merge_current_char_format", &QPlainTextEdit::mergeCurrentCharFormat, Arg("modifier"))
            .define_method("move_cursor", &QPlainTextEdit::moveCursor, Arg("operation"), Arg("mode") = static_cast<QTextCursor::MoveMode>(QTextCursor::MoveAnchor))
            .define_method("overwrite_mode", &QPlainTextEdit::overwriteMode)
            .define_method("placeholder_text", &QPlainTextEdit::placeholderText)
            .define_method("print", &QPlainTextEdit::print, Arg("printer"))
            .define_method("set_background_visible", &QPlainTextEdit::setBackgroundVisible, Arg("visible"))
            .define_method("set_center_on_scroll", &QPlainTextEdit::setCenterOnScroll, Arg("enabled"))
            .define_method("set_current_char_format", &QPlainTextEdit::setCurrentCharFormat, Arg("format"))
            .define_method("set_cursor_width", &QPlainTextEdit::setCursorWidth, Arg("width"))
            .define_method("set_document", &QPlainTextEdit::setDocument, Arg("document"))
            .define_method("set_document_title", &QPlainTextEdit::setDocumentTitle, Arg("title"))
            .define_method("set_extra_selections", &QPlainTextEdit::setExtraSelections, Arg("selections"))
            .define_method("set_line_wrap_mode", &QPlainTextEdit::setLineWrapMode, Arg("mode"))
            .define_method("set_maximum_block_count", &QPlainTextEdit::setMaximumBlockCount, Arg("maximum"))
            .define_method("set_overwrite_mode", &QPlainTextEdit::setOverwriteMode, Arg("overwrite"))
            .define_method("set_placeholder_text", &QPlainTextEdit::setPlaceholderText, Arg("placeholder_text"))
            .define_method("set_read_only", &QPlainTextEdit::setReadOnly, Arg("ro"))
            .define_method("set_tab_changes_focus", &QPlainTextEdit::setTabChangesFocus, Arg("b"))
            .define_method("set_tab_stop_distance", &QPlainTextEdit::setTabStopDistance, Arg("distance"))
            .define_method("set_text_cursor", &QPlainTextEdit::setTextCursor, Arg("cursor"))
            .define_method("set_text_interaction_flags", &QPlainTextEdit::setTextInteractionFlags, Arg("flags"))
            .define_method("set_undo_redo_enabled", &QPlainTextEdit::setUndoRedoEnabled, Arg("enable"))
            .define_method("set_word_wrap_mode", &QPlainTextEdit::setWordWrapMode, Arg("policy"))
            .define_method("tab_changes_focus", &QPlainTextEdit::tabChangesFocus)
            .define_method("tab_stop_distance", &QPlainTextEdit::tabStopDistance)
            .define_method("text_cursor", &QPlainTextEdit::textCursor)
            .define_method("text_interaction_flags", &QPlainTextEdit::textInteractionFlags)
            .define_method("to_plain_text", &QPlainTextEdit::toPlainText)
            .define_method("word_wrap_mode", &QPlainTextEdit::wordWrapMode)
            // Public Slots
            .define_method("append_html", &QPlainTextEdit::appendHtml, Arg("html"))
            .define_method("append_plain_text", &QPlainTextEdit::appendPlainText, Arg("text"))
            .define_method("center_cursor", &QPlainTextEdit::centerCursor)
            .define_method("clear", &QPlainTextEdit::clear)
            .define_method("copy", &QPlainTextEdit::copy)
            .define_method("cut", &QPlainTextEdit::cut)
            .define_method("insert_plain_text", &QPlainTextEdit::insertPlainText, Arg("text"))
            .define_method("paste", &QPlainTextEdit::paste)
            .define_method("redo", &QPlainTextEdit::redo)
            .define_method("select_all", &QPlainTextEdit::selectAll)
            .define_method("set_plain_text", &QPlainTextEdit::setPlainText, Arg("text"))
            .define_method("undo", &QPlainTextEdit::undo)
            .define_method("zoom_in", &QPlainTextEdit::zoomIn, Arg("range") = static_cast<int>(1))
            .define_method("zoom_out", &QPlainTextEdit::zoomOut, Arg("range") = static_cast<int>(1))
            // Signals
            .define_method("block_count_changed", &QPlainTextEdit::blockCountChanged, Arg("new_block_count"))
            .define_method("copy_available", &QPlainTextEdit::copyAvailable, Arg("b"))
            .define_method("cursor_position_changed", &QPlainTextEdit::cursorPositionChanged)
            .define_method("modification_changed", &QPlainTextEdit::modificationChanged, Arg("b"))
            .define_method("redo_available", &QPlainTextEdit::redoAvailable, Arg("b"))
            .define_method("selection_changed", &QPlainTextEdit::selectionChanged)
            .define_method("text_changed", &QPlainTextEdit::textChanged)
            .define_method("undo_available", &QPlainTextEdit::undoAvailable, Arg("b"))
            .define_method("update_request", &QPlainTextEdit::updateRequest, Arg("rect"), Arg("dy"));

    Enum<QPlainTextEdit::LineWrapMode> rb_cQPlainTextEditLineWrapMode =
        // RubyQt6::QtWidgets::QPlainTextEdit::LineWrapMode
        define_enum_under<QPlainTextEdit::LineWrapMode>("LineWrapMode", rb_cQPlainTextEdit)
            .define_value("NoWrap", QPlainTextEdit::LineWrapMode::NoWrap)
            .define_value("WidgetWidth", QPlainTextEdit::LineWrapMode::WidgetWidth);
}
