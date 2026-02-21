#include "qtextedit-rb.hpp"
#include <qtextedit.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QMenu>
#include <QPagedPaintDevice>
#include <QRegularExpression>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextEdit;
Class rb_cQTextEditExtraSelection;

void Init_qtextedit(Module rb_mQt6QtWidgets)
{
    rb_cQTextEdit =
        // RubyQt6::QtWidgets::QTextEdit
        define_qlass_under<QTextEdit, QAbstractScrollArea>(rb_mQt6QtWidgets, "QTextEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("accept_rich_text", &QTextEdit::acceptRichText)
            .define_method("alignment", &QTextEdit::alignment)
            .define_method("anchor_at", &QTextEdit::anchorAt, Arg("pos"))
            .define_method("auto_formatting", &QTextEdit::autoFormatting)
            .define_method("can_paste", &QTextEdit::canPaste)
            .define_method<QMenu *(QTextEdit::*)()>("create_standard_context_menu", &QTextEdit::createStandardContextMenu)
            .define_method<QMenu *(QTextEdit::*)(const QPoint &)>("create_standard_context_menu", &QTextEdit::createStandardContextMenu, Arg("position"))
            .define_method("current_char_format", &QTextEdit::currentCharFormat)
            .define_method("current_font", &QTextEdit::currentFont)
            .define_method("cursor_for_position", &QTextEdit::cursorForPosition, Arg("pos"))
            .define_method<QRect (QTextEdit::*)() const>("cursor_rect", &QTextEdit::cursorRect)
            .define_method<QRect (QTextEdit::*)(const QTextCursor &) const>("cursor_rect", &QTextEdit::cursorRect, Arg("cursor"))
            .define_method("cursor_width", &QTextEdit::cursorWidth)
            .define_method("document", &QTextEdit::document)
            .define_method("document_title", &QTextEdit::documentTitle)
            .define_method("ensure_cursor_visible", &QTextEdit::ensureCursorVisible)
            .define_method("extra_selections", &QTextEdit::extraSelections)
            .define_method<bool (QTextEdit::*)(const QRegularExpression &, QTextDocument::FindFlags)>("find", &QTextEdit::find, Arg("exp"), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method<bool (QTextEdit::*)(const QString &, QTextDocument::FindFlags)>("find", &QTextEdit::find, Arg("exp"), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method("font_family", &QTextEdit::fontFamily)
            .define_method("font_italic", &QTextEdit::fontItalic)
            .define_method("font_point_size", &QTextEdit::fontPointSize)
            .define_method("font_underline", &QTextEdit::fontUnderline)
            .define_method("font_weight", &QTextEdit::fontWeight)
            .define_method("read_only?", &QTextEdit::isReadOnly)
            .define_method("undo_redo_enabled?", &QTextEdit::isUndoRedoEnabled)
            .define_method("line_wrap_column_or_width", &QTextEdit::lineWrapColumnOrWidth)
            .define_method("line_wrap_mode", &QTextEdit::lineWrapMode)
            .define_method("load_resource", &QTextEdit::loadResource, Arg("type"), Arg("name"))
            .define_method("merge_current_char_format", &QTextEdit::mergeCurrentCharFormat, Arg("modifier"))
            .define_method("move_cursor", &QTextEdit::moveCursor, Arg("operation"), Arg("mode") = static_cast<QTextCursor::MoveMode>(QTextCursor::MoveAnchor))
            .define_method("overwrite_mode", &QTextEdit::overwriteMode)
            .define_method("placeholder_text", &QTextEdit::placeholderText)
            .define_method("print", &QTextEdit::print, Arg("printer"))
            .define_method("set_accept_rich_text", &QTextEdit::setAcceptRichText, Arg("accept"))
            .define_method("set_auto_formatting", &QTextEdit::setAutoFormatting, Arg("features"))
            .define_method("set_current_char_format", &QTextEdit::setCurrentCharFormat, Arg("format"))
            .define_method("set_cursor_width", &QTextEdit::setCursorWidth, Arg("width"))
            .define_method("set_document", &QTextEdit::setDocument, Arg("document"))
            .define_method("set_document_title", &QTextEdit::setDocumentTitle, Arg("title"))
            .define_method("set_extra_selections", &QTextEdit::setExtraSelections, Arg("selections"))
            .define_method("set_line_wrap_column_or_width", &QTextEdit::setLineWrapColumnOrWidth, Arg("w"))
            .define_method("set_line_wrap_mode", &QTextEdit::setLineWrapMode, Arg("mode"))
            .define_method("set_overwrite_mode", &QTextEdit::setOverwriteMode, Arg("overwrite"))
            .define_method("set_placeholder_text", &QTextEdit::setPlaceholderText, Arg("placeholder_text"))
            .define_method("set_read_only", &QTextEdit::setReadOnly, Arg("ro"))
            .define_method("set_tab_changes_focus", &QTextEdit::setTabChangesFocus, Arg("b"))
            .define_method("set_tab_stop_distance", &QTextEdit::setTabStopDistance, Arg("distance"))
            .define_method("set_text_cursor", &QTextEdit::setTextCursor, Arg("cursor"))
            .define_method("set_text_interaction_flags", &QTextEdit::setTextInteractionFlags, Arg("flags"))
            .define_method("set_undo_redo_enabled", &QTextEdit::setUndoRedoEnabled, Arg("enable"))
            .define_method("set_word_wrap_mode", &QTextEdit::setWordWrapMode, Arg("policy"))
            .define_method("tab_changes_focus", &QTextEdit::tabChangesFocus)
            .define_method("tab_stop_distance", &QTextEdit::tabStopDistance)
            .define_method("text_background_color", &QTextEdit::textBackgroundColor)
            .define_method("text_color", &QTextEdit::textColor)
            .define_method("text_cursor", &QTextEdit::textCursor)
            .define_method("text_interaction_flags", &QTextEdit::textInteractionFlags)
            .define_method("to_html", &QTextEdit::toHtml)
            .define_method("to_markdown", &QTextEdit::toMarkdown, Arg("features") = static_cast<QTextDocument::MarkdownFeatures>(QTextDocument::MarkdownDialectGitHub))
            .define_method("to_plain_text", &QTextEdit::toPlainText)
            .define_method("word_wrap_mode", &QTextEdit::wordWrapMode)
            // Public Slots
            .define_method("append", &QTextEdit::append, Arg("text"))
            .define_method("clear", &QTextEdit::clear)
            .define_method("copy", &QTextEdit::copy)
            .define_method("cut", &QTextEdit::cut)
            .define_method("insert_html", &QTextEdit::insertHtml, Arg("text"))
            .define_method("insert_plain_text", &QTextEdit::insertPlainText, Arg("text"))
            .define_method("paste", &QTextEdit::paste)
            .define_method("redo", &QTextEdit::redo)
            .define_method("scroll_to_anchor", &QTextEdit::scrollToAnchor, Arg("name"))
            .define_method("select_all", &QTextEdit::selectAll)
            .define_method("_set_alignment", &QTextEdit::setAlignment, Arg("alignment"))
            .define_method("set_current_font", &QTextEdit::setCurrentFont, Arg("f"))
            .define_method("set_font_family", &QTextEdit::setFontFamily, Arg("font_family"))
            .define_method("set_font_italic", &QTextEdit::setFontItalic, Arg("b"))
            .define_method("set_font_point_size", &QTextEdit::setFontPointSize, Arg("s"))
            .define_method("set_font_underline", &QTextEdit::setFontUnderline, Arg("b"))
            .define_method("set_font_weight", &QTextEdit::setFontWeight, Arg("w"))
            .define_method("_set_html", &QTextEdit::setHtml, Arg("text"))
            .define_method("_set_markdown", &QTextEdit::setMarkdown, Arg("markdown"))
            .define_method("_set_plain_text", &QTextEdit::setPlainText, Arg("text"))
            .define_method("set_text_background_color", &QTextEdit::setTextBackgroundColor, Arg("c"))
            .define_method("set_text_color", &QTextEdit::setTextColor, Arg("c"))
            .define_method("_set_text", &QTextEdit::setText, Arg("text"))
            .define_method("undo", &QTextEdit::undo)
            .define_method("zoom_in", &QTextEdit::zoomIn, Arg("range") = static_cast<int>(1))
            .define_method("zoom_out", &QTextEdit::zoomOut, Arg("range") = static_cast<int>(1));
            // Signals
            // .define_method("copy_available", &QTextEdit::copyAvailable, Arg("b"))
            // .define_method("current_char_format_changed", &QTextEdit::currentCharFormatChanged, Arg("format"))
            // .define_method("cursor_position_changed", &QTextEdit::cursorPositionChanged)
            // .define_method("redo_available", &QTextEdit::redoAvailable, Arg("b"))
            // .define_method("selection_changed", &QTextEdit::selectionChanged)
            // .define_method("text_changed", &QTextEdit::textChanged)
            // .define_method("undo_available", &QTextEdit::undoAvailable, Arg("b"));

    Data_Type<QTextEdit::AutoFormattingFlag> rb_cQTextEditAutoFormattingFlag =
        // RubyQt6::QtWidgets::QTextEdit::AutoFormattingFlag
        define_qenum_under<QTextEdit::AutoFormattingFlag>(rb_cQTextEdit, "AutoFormattingFlag");
        define_qenum_value_under(rb_cQTextEditAutoFormattingFlag, "AutoNone", QTextEdit::AutoFormattingFlag::AutoNone);
        define_qenum_value_under(rb_cQTextEditAutoFormattingFlag, "AutoBulletList", QTextEdit::AutoFormattingFlag::AutoBulletList);
        define_qenum_value_under(rb_cQTextEditAutoFormattingFlag, "AutoAll", QTextEdit::AutoFormattingFlag::AutoAll);

    Data_Type<QTextEdit::LineWrapMode> rb_cQTextEditLineWrapMode =
        // RubyQt6::QtWidgets::QTextEdit::LineWrapMode
        define_qenum_under<QTextEdit::LineWrapMode>(rb_cQTextEdit, "LineWrapMode");
        define_qenum_value_under(rb_cQTextEditLineWrapMode, "NoWrap", QTextEdit::LineWrapMode::NoWrap);
        define_qenum_value_under(rb_cQTextEditLineWrapMode, "WidgetWidth", QTextEdit::LineWrapMode::WidgetWidth);
        define_qenum_value_under(rb_cQTextEditLineWrapMode, "FixedPixelWidth", QTextEdit::LineWrapMode::FixedPixelWidth);
        define_qenum_value_under(rb_cQTextEditLineWrapMode, "FixedColumnWidth", QTextEdit::LineWrapMode::FixedColumnWidth);

    Data_Type<QFlags<QTextEdit::AutoFormattingFlag>> rb_cQTextEditAutoFormatting =
        // RubyQt6::QtWidgets::QTextEdit::AutoFormatting
        define_qflags_under<QTextEdit::AutoFormattingFlag>(rb_cQTextEdit, "AutoFormatting");

    rb_cQTextEditExtraSelection =
        // RubyQt6::QtWidgets::QTextEdit::ExtraSelection
        define_qlass_under<QTextEdit::ExtraSelection>(rb_cQTextEdit, "ExtraSelection")
            .define_attr("cursor", &QTextEdit::ExtraSelection::cursor)
            .define_attr("format", &QTextEdit::ExtraSelection::format);
}
